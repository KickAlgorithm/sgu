/*************************************************************************
                        175. Encoding
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
input: standard
output: standard
 
 
 
 Let phi(W) is the result of encoding for algorithm:
 1.	If the length of W is 1 then phi(W) is W;
 2.	Let coded word is W = w1w2...wN and K = N / 2 (rounded down);
 3.	phi(W) = phi(wNwN-1...wK+1) + phi(wKwK-1...w1).
 For example, phi('Ok') = 'kO', phi('abcd') = 'cdab'.
 Your task is to find position of letter wq in encoded word phi(W).
 
 Input
 Given integers N, q (1 <= N <= 10^9; 1<= q <= N), where N is the length of word W.
 
 Output
 Write position of letter wq in encoded word phi(W).
 
 Sample test(s)
 
 Input
 9 4
 
 Output
 8

 ************************************************************************/
#include<iostream>
using namespace std;

int help(int N, int p)
{
    if(N == 1) return 1;
    int k = N/2;
    if(p > k) return help(N-k, N-p+1);
    else return (N-k) + help(k, k-p+1);
}


int main() {
    int N,q; cin >> N >> q;
    cout << help(N, q);
    return 0;
}
