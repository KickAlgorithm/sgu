/*************************************************************************
                        168. Matrix
 
                time limit per test: 0.5 sec.
                memory limit per test: 16000 KB
                    input: standard
                    output: standard
 
 
 
 You are given N*M matrix A. You are to find such matrix B, that B[i,j]=min{ A[x,y] : (y>=j) and (x>=i+j-y) }
 
 Input
 On the first line of the input there are two integer numbers, N and M (1<=N,M<=1000). Then matrix A follows: next N lines contains M integers each (not greater than 32000 by absolute value). The j-th number on then i-th of this lines is A[i,j].
 
 Output
 Write matrix B in the same format as matrix A, but without N and M.
 
 Sample test(s)
 
 Input
 3 3
 1 2 3
 4 5 6
 7 8 9
 
 Output
 1 2 3 
 2 3 6 
 3 6 9
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;


int main() {
    
    int n,m;
    scanf("%d%d",&n,&m);
    int a[1010][1010];
    int b[1010][1010];
    
    for(int i = 0;i < n;i++)
        for(int j = 0; j < m;j++)
            scanf("%d", &a[i][j]);
    
    for(int k = m+n-2;k >= 0;k--)
    {
        for(int j = m-1;j >= 0;j--)
        {
            int i = k - j;
            if(i >= n) break;
            if(i < 0) continue;
            b[i][j] = a[i][j];
            
            if(i+1 < n) b[i][j] = min(b[i][j], b[i+1][j]);
            if(i >= 1 && j < m-1) b[i][j] = min(b[i][j], b[i-1][j+1]);
            if(j+1 < m) b[i][j] = min(b[i][j], b[i][j+1]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j)printf(" ");
            printf("%d",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}