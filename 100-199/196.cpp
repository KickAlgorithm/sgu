/*************************************************************************
                        196. Matrix Multiplication
 
                    time limit per test: 0.25 sec.
                    memory limit per test: 65536 KB
                            input: standard
                            output: standard
 
 
 
 Let us consider an undirected graph G = <V, E> which has N vertices and M edges. Incidence matrix of this graph is an N × M matrix A = {aij}, such that aij is 1 if i-th vertex is one of the ends of j-th edge and 0 in the other case. Your task is to find the sum of all elements of the matrix ATA where AT is A transposed, i.e. an M × N matrix obtained from A by turning its columns to rows and vice versa.
 
 Input
 
 The first line of the input file contains two integer numbers — N and M (2 le N le 10,000, 1 le M le 100,000). 2M integer numbers follow, forming M pairs, each pair describes one edge of the graph. All edges are different and there are no loops (i.e. edge ends are distinct).
 
 Output
 
 Output the only number — the sum requested.
 
 Sample test(s)
 
 Input
 4 4
 1 2
 1 3
 2 3 
 2 4 
 
 Output
 18
 ************************************************************************/
#include<cstdio>
int sum[10009], n, m, x, y;
int main() {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf ("%d %d", &x, &y);
        sum[x]++, sum[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += sum[i] * sum[i];
    printf ("%d", ans);
    return 0;
}