/*************************************************************************
                        134. Centroid
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 You are given an undirected connected graph, with N vertices and N-1 edges (a tree). You must find the centroid(s) of the tree.
 In order to define the centroid, some integer value will be assosciated to every vertex. Let's consider the vertex k. If we remove the vertex k from the tree (along with its adjacent edges), the remaining graph will have only N-1 vertices and may be composed of more than one connected components. Each of these components is (obviously) a tree. The value associated to vertex k is the largest number of vertices contained by some connected component in the remaining graph, after the removal of vertex k. All the vertices for which the associated value is minimum are considered centroids.
 
 Input
 
 The first line of the input contains the integer number N (1<=N<=16 000). The next N-1 lines will contain two integers, a and b, separated by blanks, meaning that there exists an edge between vertex a and vertex b.
 
 Output
 
 You should print two lines. The first line should contain the minimum value associated to the centroid(s) and the number of centroids. The second line should contain the list of vertices which are centroids, sorted in ascending order.
 
 Sample Input
 
 7
 1 2
 2 3
 2 4
 1 5
 5 6
 6 7
 Sample Output
 
 3 1
 1
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXX=16010;

int dp[MAXX];//dp[i]以i为根的子树总共包含的节点数。
int weight[MAXX];
bool vis[MAXX];
vector<int> tree[MAXX];//存树的逻辑结构
int n;
int res(INT_MAX);

void DFS(int root)
{
    int v;
    int localmax(-1);
    vis[root]=true;
    for(int i=0;i<tree[root].size();i++){
        v=tree[root][i];
        if(vis[v])continue;
        DFS(v);
        dp[root]+=dp[v];
        localmax = max(localmax, dp[v]);
    }
    localmax = max(localmax, n - dp[root]);
    weight[root] = localmax;
    res = min(res, localmax);
}

int main()
{
    fill(dp,dp+MAXX,1);
    fill(weight, weight+MAXX, 0);
    fill(vis,vis+MAXX,false);
    
    int x,y;
    cin >> n;
    
    for(int i = 1;i < n;i++)
    {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    DFS(1);
    int num(0);
    vector<int> nums;
    for(int i = 1;i <= n;i++)
    {
        if(weight[i] == res)
        {
            num++;
            nums.push_back(i);
        }
    }
    cout << res << " " << num << endl;
    for(int i = 0;i < nums.size();i++)
        cout << nums[i] << endl;
    return 0;
}