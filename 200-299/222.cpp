/*************************************************************************
                        222. Little Rooks
 
                time limit per test: 0.25 sec.
                memory limit per test: 65536 KB
                        input: standard
                        output: standard
 
 
 Inspired by a "Little Bishops" problem, Petya now wants to solve problem for rooks.
 
 A rook is a piece used in the game of chess which is played on a board of square grids. A rook can only move horizontally and vertically from its current position and two rooks attack each other if one is on the path of the other.
 
 Given two numbers n and k, your job is to determine the number of ways one can put k rooks on an n × n chessboard so that no two of them are in attacking positions.
 
 Input
 
 The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).
 
 Output
 
 Print a line containing the total number of ways one can put the given number of rooks on a chessboard of the given size so that no two of them are in attacking positions.
 
 Sample test(s)
 
 Input
 4 4 
 
 Output
 24
 ************************************************************************/
#include <iostream>
using namespace std;

long long mul(int start, int end)
{
    long long res(1);
    while(start <= end)
    {
        res *= start;
        start++;
    }
    return res;
}

int main()
{
    int n,k;
    cin >> n >> k;
    
    if(k > n)
    {
        cout << 0;
        return 0;
    }
    
    long long res = mul(n-k+1, n);
    res /= mul(1, k);
    res *= mul(n-k+1,n);
    cout << res << endl;
    
    return 0;
}