/// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/Dijkstra.h"

int main(int argc, char *argv[])
{
    char filepath[MAX_STRLEN];//图的信息文件
    node graphic[MAX_VERTEX_NUM] = {0};//图的数组
    int sid, did;
    int selnum; 

    if(argc < 2) {
        printf("usage:*.exe input\n");
        exit(1);
    }
    strcpy(filepath, argv[1]);
    /***********初始化图***************/
    if(!InitGraphic(filepath, graphic, MAX_VERTEX_NUM)) {
        UnitGraphic(graphic);
        exit(1);
    }
    printf("****  Print The Graphic information  ****");
    ViewGraphic(graphic);//打印图
    /************dijkstra运算***********/
    if(!Dijkstra(graphic)) {
        UnitGraphic(graphic);
        exit(1);
    }

    printf("\n****Find the shortest path between nodes****");
    printf("\n1.View minimum route between nodes.");
    printf("\n2.Exit.");
    
    for(;;) {
        printf("\nEnter Your Selection:");
        scanf("%d",&selnum);
        switch(selnum)    {
            case 1:    {
                printf("\nEnter source node ID:");
                scanf("%d",&sid);
                printf("\nEnter destination node ID:");
                scanf("%d",&did);

                MinRoute(graphic, sid, did);//打印最优路径
                break;
            }
            case 2:
                exit(1);
            default: {
                printf("\nEnter proper choice.\n");
                break;
            }
        }
    }
    UnitGraphic(graphic);
    return 0;
}