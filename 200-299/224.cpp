/*************************************************************************
                        224. Little Queens
 
                time limit per test: 0.75 sec.
                memory limit per test: 65536 KB
                        input: standard
                        output: standard
 
 
 
 Well, you might have heard about a curious boy Petya who likes to learn the number of ways one can put k identical chess pieces on a chessboard of size n× n so that no two of them are in the attacking positions. He have solved the problems for bishops, rooks and kings. Recently he has met Farmer John and told him about that.
 
 Impressed FJ has decided to teach his cows to play chess. The first question Bessie asked on the first lesson was: "What about the number of ways one can put k queens on a chessboard of size n × n, so that no two of them are in the attacking positions?"
 
 The queen can move diagonally, horizonatally and vertically, thus combining the properties of a bishop and a rook. Two queens are in the attacking positions if they are on the path of each other.
 
 Input
 
 The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).
 
 Output
 
 Print a line containing the total number of ways one can put the given number of queens on a chessboard of the given size so that no two of them are in attacking positions.
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;

int n, sum, max, k, m;
void dfs (int line , int row, int l, int r, int k) {
    int pos, p, i;
    if (line > n){
        if(k == m) sum++;
        return;
    }
    dfs (line + 1, row, l>>1, r<<1, k);
    if (row != max) {
        pos = max & (~ (row | l | r) );
        while (pos != 0) {
            p = pos & -pos;
            pos = pos - p;
            dfs (line+1,row | p, (l | p) >> 1, (r | p) << 1, k + 1);
        }
    }
}
int main() {
    scanf ("%d %d", &n, &m);
    max = (1 << n) - 1;
    dfs (1, 0, 0, 0, 0);
    printf ("%d", sum);
}