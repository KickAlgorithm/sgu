/*************************************************************************
                        143. Long Live the Queen
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 The Queen of Byteland is very loved by her people. In order to show her their love, the Bytelanders have decided to conquer a new country which will be named according to the queen's name. This new country contains N towns. The towns are connected by bidirectional roads and there is exactly ONE path between any two towns, walking on the country's roads. For each town, the profit it brings to the owner is known. Although the Bytelanders love their queen very much, they don't want to conquer all the N towns for her. They will be satisfied with a non-empty subset of these towns, with the following 2 properties: there exists a path from every town in the subset to every other town in the subset walking only through towns in the subset and the profit of the subset is maximum. The profit of a subset of the N towns is equal to the sum of the profits of the towns which belong to the subset. Your task is to find the maximum profit the Bytelanders may get.
 
 Input
 
 The first line of input will contain the number of towns N (1<=N<=16 000). The second line will contain N integers: the profits for each town, from 1 to N. Each profit is an integer number between -1000 and 1000. The next N-1 lines describe the roads: each line contains 2 integer numbers a and b, separated by blanks, denoting two different towns between which there exists a road.
 
 Output
 
 The output should contain one integer number: the maximum profit the Bytelanders may get.
 
 Sample Input
 
 5
 -1 1 3 1 -1
 4 1
 1 3
 1 2
 4 5
 Sample Output
 
 4
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#define INf 16010

using namespace std;
vector<int> g[INf];
int val[INf], f[INf];

int dfs (int x, int fa) {
    f[x] = val[x];
    for (int i = 0; i < g[x].size(); i++) {
        int temp = 0;
        if (g[x][i] != fa)
        temp = dfs (g[x][i], x);
        if (temp > 0) f[x] += temp;
    }
    return f[x];
}
int main() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    cin >> val[i];
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back (y);
        g[y].push_back (x);
    }
    
    dfs (1, -1);
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    ans = max (ans, f[i]);
    
    cout << ans;
    return 0;
}