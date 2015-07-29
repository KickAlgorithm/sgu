/*************************************************************************
                        131. Hardwood floor
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 The banquet hall of Computer Scientists' Palace has a rectangular form of the size M x N (1<=M<=9, 1<=N<=9). It is necessary to lay hardwood floors in the hall. There are wood pieces of two forms:
 1) rectangles (2x1)
 2) corners (squares 2x2 without one 1x1 square)
 You have to determine X - the number of ways to cover the banquet hall.
 Remarks. The number of pieces is large enough. It is not allowed to leave empty places, or to cover any part of a surface twice, or to saw pieces.
 Input
 
 The first line contains natural number M. The second line contains a natural number N.
 
 Output
 
 First line should contain the number X, or 0 if there are no solutions.
 
 Sample Input
 
 2 3
 Sample Output
 
 5
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x;
long long f[10][1 << 10];

void dfs (int k, int last, int now, int b1, int b2) {
    if (k == m){
        if(!b1 && !b2)
        f[x][now] += f[x - 1][last];
        return;
    }
    if (!b1 && !b2) {
        dfs (k + 1, last << 1 , now << 1 | 1, 0, 0);
        dfs (k + 1, last << 1 , now << 1 | 1, 1, 0);
        dfs (k + 1, last << 1 , now << 1 | 1, 0, 1);
    }
    if (!b1)
    dfs (k + 1, last << 1 , now << 1 | b2, 1, 1);
    if (!b2) {
        dfs (k + 1, last << 1 | (1-b1), now << 1 | 1, 0, 1);
        dfs (k + 1, last << 1 | (1-b1), now << 1 | 1, 1, 1);
    }
    dfs (k + 1, last << 1 | (1-b1), now << 1 | b2, 0, 0);
}

int main() {
    cin >> n >> m;
    if (n < m) swap (n, m);
    f[0][ (1 << m) - 1] = 1;
    for ( x = 1; x <= n; x++)
    dfs (0, 0, 0, 0, 0);
    
    cout << f[n][(1 << m) - 1];
}