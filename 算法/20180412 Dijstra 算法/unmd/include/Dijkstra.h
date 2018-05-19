///Dijkstra.h
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#define MAX_VERTEX_NUM 100                        	//最大顶点数
#define MAX_EDGE_NUM 50                            	//相邻最大节点数
#define INFINITE 1E5                            	//表示节点之间无连接的一个较大的数
#define MAX_STRLEN 256                            	//最大字符串字节数

#define FALSE                        0
#define TRUE                        1
typedef int                            BOOL;
typedef unsigned int                UINT;

#define SAFEFREE(p) {if(NULL!=(p)) free(p);}

extern int g_node_num;                            //一个图中，实际节点数的全局变量
typedef struct _vertex {                         //通用的顶点数据结构体
    int id;//id
    struct _vertex *pLinkList[MAX_EDGE_NUM];      //相邻顶点的指针数组
    int nCost[MAX_VERTEX_NUM];                    //与相邻顶点的权重数组
    struct _vertex **next;                        //与剩余顶点之间的最短路径
    int *pmincost;                                //与剩余顶点之间的最小代价
}vertex;

typedef struct _node {                            //组成图的顶点元素信息进行封装
    int nID;
    struct _vertex *pVer;
}node;

BOOL InitGraphic(char path[], node arr[], UINT nsize);
void UnitGraphic(node arr[]);
void ViewGraphic(node arr[]);
BOOL Dijkstra(node arr[]);
void MinRoute(node arr[], UINT nSrID, UINT nDsID);

#endif