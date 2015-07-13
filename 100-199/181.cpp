/*************************************************************************
                    181. X-Sequence
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                    input: standard
                    output: standard
 
 
 
 Let {xi} be the infinite sequence of integers:
 1)	x0 = A;
 2)	xi = (alpha * xi-1^2 + beta * xi-1 + gamma) mod M, for i >= 1.
 Your task is to find xk if you know A, alpha, beta, gamma, M and k.
 
 Input
 Given A (1 <= A <= 10000), alpha (0 <= alpha <= 100), beta (0 <= beta <= 100), gamma (0 <= gamma <= 100), M (1 <= M <= 1000), k (0 <= k <= 10^9). All numbers are integer.
 
 Output
 Write xk.
 
 Sample test(s)
 
 Input
 1 1 1 1 10 1
 
 Output
 3

 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXX = 1010;
bool flag[MAXX];
int ans[MAXX];

long long A, alpha, beta, gamma, M, k;

inline long long  get (long long x) {
    return (alpha * x * x  + beta * x  + gamma) % M;
}


int main() {
    
    cin >> A >> alpha >> beta >> gamma >> M >> k;
    fill(flag, flag+MAXX, false);
    
    if(k == 0)
    {
        cout << A;
        return 0;
    }
    
    int t = 0;
    int x = get(A);
    while(!flag[x])
    {
        flag[x] = true;
        t++;
        ans[t] = x;
        x = get(x);
    }
    
    int i = 1;
    for(;i <= t;i++)
        if(ans[i] == x)
            break;
    
    int loop = t - i + 1;
    int d = t - loop;
    if(k <= t) cout << ans[k];
    else cout << ans[(1+(k - d - 1) % loop) + d];
    return 0;
}
