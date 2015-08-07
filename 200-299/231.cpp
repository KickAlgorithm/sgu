/*************************************************************************
                        231. Prime Sum
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                        input: standard
                        output: standard
 
 
 
 Find all pairs of prime numbers (A, B) such that A<=B and their sum is also a prime number and does not exceed N.
 
 Input
 The input of the problem consists of the only integer N (1<=N<=10^6).
 
 Output
 On the first line of the output file write the number of pairs meeting the requirements. Then output all pairs one per line (two primes separated by a space).
 
 Sample test(s)
 
 Input
 4
 
 Output
 0

 ************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double c = sqrt(n);
    bool *bv = new bool[n];
    for(int i = 3; i <= c; i += 2)
        if (!bv[i])
            for(int j = i*i, k = i << 1; j <= n; j += k)
                bv[j] = 1;
    
    int out[10000];
    int num = 0;
    for(int i = 3; i <= n-2; i += 2)
        if(!bv[i] && !bv[i+2])
            out[num++] = i;
    
    cout << num << endl;
    for(int i = 0;i < num;i++)
        cout << 2 << " " << out[i] << endl;

    return 0;
}