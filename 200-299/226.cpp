/*************************************************************************
                        226. Colored graph
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                        input: standard
                        output: standard
 
 
 
 You are given an oriented graph. Each edge of the graph is colored in one of the three colors. Your task is to find the length of the shortest path from the first vertex to the N-th. Note that any two successive edges in the path can't have the same color.
 
 Input
 The first line of the input file consists of two integers N and M (2 <= N <= 200; 0 <= M <= N*N). Next M lines contain descriptions of the edges. Each edge description is a list of three integers X, Y, C (1 <= X, Y <= N, 1 <= C <= 3), where X is the starting vertex of the edge, Y is the finishing vertex and C is the color of the edge.
 
 Output
 Output the length of the shortest path between the first and the N-th vertexes. Output "-1" if the path doesn't exist.
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int dis[210][4];
int N,M;

struct Edge
{
    int from;
    int to;
    int color;
    Edge(int f, int t, int c):from(f),to(t),color(c){}
    Edge():from(-1),to(-1),color(-1){}
};

Edge edges[40010];
vector<int> E[210];

int main() {
    for(int i = 0;i < 210;i++)
        for(int j = 0;j < 4;j++)
            dis[i][j] = 9999999;
    dis[1][1] = dis[1][2] = dis[1][3] = 0;
    scanf("%d%d", &N, &M);
    for(int i = 1;i <= M;i++)
    {
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].color);
        E[edges[i].from].push_back(i);
    }

    queue<int> myqueue;
    bool vis[210] = {false};
    int c[210] = {0};
    myqueue.push(1);
    vis[1] = true;
    c[1] = 1;
    
    //顶点入队vis要做标记，另外要统计顶点的入队次数
    int OK = 1;
    while(!myqueue.empty())
    {
        int x;
        x = myqueue.front(); myqueue.pop(); vis[x] = false;
        //队头元素出队，并且消除标记
        vector<int> v = E[x];
        for(int i = 0;i < v.size();i++) //遍历顶点x的邻接节点
        {
            int edgeindex = v[i];
            Edge e = edges[edgeindex];
            int y = e.to;
            int color = e.color;
            
            //printf("%d, %d, %d\n", x ,y ,color);
            
            int choosed;
            if(color == 1 && dis[x][2] <= dis[x][3]) choosed = 2;
            else if(color == 1 && dis[x][2] > dis[x][3]) choosed = 3;
            else if(color == 2 && dis[x][1] <= dis[x][3]) choosed = 1;
            else if(color == 2 && dis[x][1] > dis[x][3]) choosed = 3;
            else if(color == 3 && dis[x][1] <= dis[x][2]) choosed = 1;
            else choosed = 2;

                
            if( dis[x][choosed]+ 1 < dis[y][color])
            {
                dis[y][color] = dis[x][choosed]+ 1;  //松弛
                if(!vis[y])  //顶点y不在队内
                {
                    vis[y]=1;    //标记
                    c[y]++;      //统计次数
                    myqueue.push(y);   //入队
                    if(c[y] > 100)  //超过入队次数上限，说明有负环
                    {
                        printf("-1\n");
                        return 0;
                    }
                    
                }
            }

        }
    }
    
    int distance = min(dis[N][1], min(dis[N][2], dis[N][3]));
    if(distance < 9999999)
        printf("%d\n",distance);
    else
        printf("-1\n");

    return 0;
}
