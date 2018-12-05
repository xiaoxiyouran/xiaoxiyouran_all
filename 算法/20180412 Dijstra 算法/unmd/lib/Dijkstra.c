/// Dijkstra.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Dijkstra.h"

int g_node_num;/*用于计算实际节点数的全局变量*/
/****************************************
*函数名：InitGraphic
*参数：path-图的信息文件路径；arr-储存图的数组；nsize-数组大小
*返回值：BOOL-成功返回1，错误返回0
*说明：根据图的信息文件，初始化数组
*****************************************/
BOOL InitGraphic(char path[], node arr[], UINT nsize)
{
    char buf[MAX_STRLEN];
    char *pos;
    char ctemp;
    int ncost;
    int i;
    UINT nid;//临时顶点ID
    UINT ncid;//临时连接顶点的ID
    UINT nlinkpos;//连接顶点数组中的位置

    memset(arr, 0, sizeof(node)*nsize);//赋值0
    FILE *pfile = fopen(path, "r");
    if(NULL == pfile) {
        printf("Error opening file.\n");
        return FALSE;
    }
    while(NULL != fgets(buf, MAX_STRLEN, pfile)) {
        pos = strtok(buf, ":");//读取一行，解析第一个冒号之前的标号，即第几个节点
        nid = atoi(pos);
        if(nid < nsize) {
            arr[nid-1].nID = nid;
            arr[nid-1].pVer = (vertex*)malloc(sizeof(vertex));//申请一个顶点struct
            if(NULL == arr[nid-1].pVer) {
                printf("out of memory!\n");
                return FALSE;
            }
            memset(arr[nid-1].pVer, 0, sizeof(vertex));//赋值0
            arr[nid-1].pVer->id = nid;
            g_node_num++;//节点数加1
        } else {
            fprintf(stderr, "access the boundary of setting:%d\n", nid);
        }
    }
    rewind(pfile);//文件指针跳转到开始处，读取各顶点的相邻节点
    for(i=0; i<g_node_num; i++) {
        fscanf(pfile, "%d", &nid);//读取第一个节点标号
        nlinkpos = 0;//指示其相邻节点结构体的当前位置
        while((ctemp=fgetc(pfile)) != ';') {
            fscanf(pfile, "%u-%d", &ncid, &ncost);
            if(ncid > nsize || ncost < 0) {
                fprintf(stderr, "access the boundary of setting or find negative cost:%u-%d\n", ncid, ncost);
                return FALSE;
            }

            arr[nid-1].pVer->pLinkList[nlinkpos] = arr[ncid-1].pVer;/*相邻节点指针数组赋值*/
            arr[nid-1].pVer->nCost[ncid-1] = ncost;/*此节点到相邻节点的cost*/
            arr[nid-1].pVer->pmincost = NULL;
            arr[nid-1].pVer->next = NULL;
            nlinkpos++;
        }
    }
    fclose(pfile);
    return TRUE;
}
/*******************************************
*函数名：ViewGraphic
*参数：arr-图的数组
*返回值：无
*说明：打印图的结构信息
*******************************************/
void ViewGraphic(node arr[])
{
    int i, j;
    int nidtemp;//临时节点序号
    printf("\nID\tConnceted to-ID:cost");
    for(i=0; i<g_node_num; i++) {
        printf("\n%d\t",arr[i].nID);
        for(j=0; arr[i].pVer->pLinkList[j] != NULL; j++) {
            nidtemp = arr[i].pVer->pLinkList[j]->id;
            printf("%d:", nidtemp);
            printf("%d ",arr[i].pVer->nCost[nidtemp-1]);
        }
    }
}

/*************************************************
*函数名：Dijkstra
*参数：arr-图的数组
*返回值：TRUE-成功；FALSE-失败
*说明：依次将每个节点作为起始节点，计算剩余节点与其之间的最短路径
*************************************************/
BOOL Dijkstra(node arr[])
{
    UINT i, j, k;
    vertex *pbegin, *ptemp, *ptemp1;
    int *tcost;//用于储存其余节点到起始节点的最小代价
    BOOL *pbDone;//用于判断节点是否计算完毕的数组
    int nidtemp;//与当前节点相邻的其它节点中，cost最小的顶点序号
    int nmixcost = INFINITE;

    tcost = (int*)malloc(g_node_num * sizeof(int));
    pbDone = (BOOL*)malloc(g_node_num * sizeof(BOOL));
    if(NULL == tcost || NULL == pbDone) {
        printf("out of memory\n");
        return FALSE;
    }
    for(i=0; arr[i].pVer!=0; i++) {//依次将每个顶点作为起始节点
        for(j=0; j<g_node_num; j++) {//初始化数组
            tcost[j] = INFINITE;//其它节点到起始节点的代价
            pbDone[j] = 0;
        }
        pbegin = arr[i].pVer;//起始顶点
        pbegin->next = (vertex**)malloc(g_node_num * sizeof(vertex*));//储存每个顶点最优的前驱顶点的id的数组
        pbegin->pmincost = (int*)malloc(g_node_num * sizeof(int));//储存每个顶点到起始顶点的最小代价数组
        tcost[i] = 0;//初始化
        pbDone[i] = 1;
        pbegin->pmincost[i] = 0;
        ptemp = pbegin;//设定起始顶点为当前顶点

        while(1) {
            for(j=0; ptemp->pLinkList[j]!=0; j++) {//遍历当前顶点的相邻节点，更新最小代价(松弛边)
                ptemp1 = ptemp->pLinkList[j];
                if(tcost[ptemp1->id-1] > tcost[ptemp->id-1] + ptemp->nCost[ptemp1->id-1] \
                    && pbDone[ptemp1->id-1] == 0) {
                    tcost[ptemp1->id-1] = tcost[ptemp->id-1] + ptemp->nCost[ptemp1->id-1];
                    pbegin->next[ptemp1->id-1] = ptemp;//设定顶点更新后的前驱顶点
                }
            }
            nmixcost = INFINITE;
            for(j=0; j<g_node_num; j++) {//找出更新后,所有顶点中，代价最小的顶点，重新作为当前顶点。这一步可以优化。
                if(pbDone[arr[j].nID-1] != 1 && tcost[arr[j].nID-1] < nmixcost && tcost[arr[j].nID-1] != 0) {
                        nmixcost = tcost[arr[j].nID-1];
                        nidtemp = arr[j].nID;
                }
            }
            if(nmixcost == INFINITE) {//除起始顶点外的所有节点都已经被处理完毕，退出
                break;
            }
            pbegin->pmincost[nidtemp-1] = nmixcost;
            ptemp = arr[nidtemp-1].pVer;//重新设定当前顶点
            pbDone[nidtemp-1] = 1;//表示当前顶点已经被处理过了，其路径已经最短，代价最小
        }
    }
    free(pbDone);
    free(tcost);
    return TRUE;
}

/**********************************************************
*函数名：MinRoute
*参数：arr-图的数组；nSrID-起始节点序号；nDsID-目的节点序号
*返回值：无
*说明：给定图的数组，利用Dijkstra函数处理之后，根据设定的起始和终止节点序号，打印
*最短路径和最小代价。
***********************************************************/
void MinRoute(node arr[], UINT nSrID, UINT nDsID)
{
    if(nSrID<0 || nSrID>g_node_num || nDsID<0 || nDsID>g_node_num) {
        printf("Invalid node number!\n");
    }
    int nid;
    vertex *ptemp = arr[nSrID-1].pVer;
    printf("the total cost is: %d\n", ptemp->pmincost[nDsID-1]);
    printf("the path is:");
    nid = nDsID;
    printf("%d->",arr[nid-1].nID);
    while(ptemp->next[nid-1]->id != arr[nSrID-1].nID) {
        nid = ptemp->next[nid-1]->id;//回溯路径
        printf("%d->",nid);
    }
    printf("%d\n",arr[nSrID-1]);
}

/*****************************************
*函数名：UnitGraphic
*参数：arr-图的数组
*返回值：无
*说明：释放内存
*****************************************/
void UnitGraphic(node arr[])
{
    UINT i;
    for(i=0; i<g_node_num; i++) {
        if(arr[i].pVer != NULL) {
            SAFEFREE(arr[i].pVer->next);
            SAFEFREE(arr[i].pVer->pmincost);
        }
    }
}