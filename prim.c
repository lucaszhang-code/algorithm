#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N  6
#define MAX 1000

//邻接矩阵数据结构 
typedef  struct {
    int vnum;//顶点数
    int type;   //0 无向图，1 有向图
    char  vexs[N];     // 顶点信息
    int  arcs[N][N]; //关系矩阵
} GraphMatrix;

typedef struct {
    int vex;    // 顶点
    int shortweight;    // 
}ShortWeight;


//邻接表数据结构
typedef struct EdgeNode { //边表中的结点
    int  endvex;     //相邻顶点在顶点表中下标
    int  weight;  //边的权
    struct EdgeNode* nextedge;   //链字段
}EdgeNode;
typedef struct EdgeNode* EdgeList;

typedef struct
{
    char  vertex;  //记录顶点信息
    EdgeList  edgelist;  //指向边表的指针
} VexNode;

typedef struct {
    VexNode* vexs[N];  //N个顶点
    int type;//0 无向图，1 有向图
    int vcount;//顶点数
} GraphList;

//邻接矩阵初始化
GraphMatrix* initGraphMatrix()
{
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接矩阵，不需要考虑输入的数字非法情况，不输入顶点的信息*/
    GraphMatrix* G = (GraphMatrix*)malloc(sizeof(GraphMatrix));

    int edgenum = 0;
    int vnum = 0;
    scanf("%d %d %d", &G->type, &vnum, &edgenum);
    G->vnum = vnum;
    char* temp = (char*)malloc(N * sizeof(char));
    scanf("%s", temp);
    for (int i = 0; i < G->vnum; i++)
    {
        G->vexs[i] = temp[i];
    }
    int count = 0;
    for (int i = 0; i < G->vnum; i++)
    {
        for (int j = 0; j < G->vnum; j++)
            G->arcs[i][j] = MAX;
    }
    if (G->type == 1)
    {
        while (count < edgenum)
        {
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            G->arcs[i][j] = k;
            count++;
        }
    }
    else
    {
        while (count < edgenum)
        {
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            G->arcs[i][j] = k;
            G->arcs[j][i] = k;
            count++;
        }
    }
    return G;
}

//邻接表初始化
GraphList* initGraphList()
{
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接表。不需考虑输入的数字非法情况，输入顶点的信息*/
    GraphList* G = (GraphList*)malloc(sizeof(GraphList));
    int t, v, s;
    scanf("%d%d%d", &t, &v, &s);
    G->vcount = v;
    G->type = t;
    int i, j, k, l;
    char vex[N];
    char ch = getchar();
    for (i = 0; i < v; i++) {
        scanf("%c", &vex[i]);
    }
    for (i = 0; i < v; i++) {
        G->vexs[i] = (VexNode*)malloc(sizeof(VexNode));
        G->vexs[i]->vertex = vex[i];
        G->vexs[i]->edgelist = (EdgeList)malloc(sizeof(struct EdgeNode));
        G->vexs[i]->edgelist->nextedge = NULL;
    }
    for (i = 0; i < s; i++) {
        int head, tail, w;
        scanf("%d %d %d", &head, &tail, &w);
        if (t == 0) {
            for (k = 0; k < v; k++) {
                if (G->vexs[k]->vertex - '0' == head) {
                    EdgeList node1 = (EdgeList)malloc(sizeof(struct EdgeNode));
                    for (j = 0; j < v; j++) {
                        if (vex[j] - '0' == tail) {
                            node1->weight = w;
                            node1->endvex = j;
                            node1->nextedge = G->vexs[k]->edgelist->nextedge;
                            G->vexs[k]->edgelist->nextedge = node1;
                            break;
                        }
                    }
                    for (j = 0; j < v; j++) {
                        if (G->vexs[j]->vertex - '0' == tail) {
                            EdgeList node2 = (EdgeList)malloc(sizeof(struct EdgeNode));
                            for (l = 0; l < v; l++) {
                                if (vex[l] - '0' == head) {
                                    node2->weight = w;
                                    node2->endvex = l;
                                    node2->nextedge = G->vexs[j]->edgelist->nextedge;
                                    G->vexs[j]->edgelist->nextedge = node2;
                                    break;
                                }
                            }
                        }
                    }
                }


            }
        }
    }
    return G;
}

void Print(int a, int b)
{
    if (a > b)
        Print(b, a);
    else
        printf("%d %d\n", a, b);
}

int GetShortWeight(GraphList* G, ShortWeight* shortw) {
    int i;
    int min = MAX;
    int loc;
    for (i = 1; i < G->vcount; i++) {
        if (min > shortw[i].shortweight && shortw[i].shortweight != 0) {
            min = shortw[i].shortweight;
            loc = i;
        }
    }
    return loc;
}

//二选一即可（选择其中一个方法之后要把另一个函数完全删掉或注释掉）

// //邻接表
// void Prim_list(GraphList* G)
// {

// }

//邻接矩阵
void Prim_list(GraphMatrix* G)
{
    // 存储顶点到生成树的最小边的权重
    int lowcost[N];
    // 存储生成树中最靠近的新顶点
    int closest[N];
    // 标记顶点是否在生成树中
    int inMST[N] = {0};

    // 初始化，以顶点0为起点
    for (int i = 0; i < G->vnum; i++) {
        lowcost[i] = G->arcs[0][i];
        closest[i] = 0;
    }
    inMST[0] = 1;

    // 选择vnum-1条边
    for (int i = 1; i < G->vnum; i++) {
        int min = MAX;
        int v = -1;

        // 找到权重最小的边
        for (int j = 0; j < G->vnum; j++) {
            if (!inMST[j] && lowcost[j] < min) {
                min = lowcost[j];
                v = j;
            }
        }

        // 将该顶点加入到生成树中
        inMST[v] = 1;
        Print(closest[v], v);

        // 更新数组
        for (int j = 0; j < G->vnum; j++) {
            if (!inMST[j] && G->arcs[v][j] < lowcost[j]) {
                lowcost[j] = G->arcs[v][j];
                closest[j] = v;
            }
        }
    }
}


int main(void)
{
    //二选一
    GraphMatrix* G = initGraphMatrix();
    // GraphList* G = initGraphList();
    Prim_list(G);
}