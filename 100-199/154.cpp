/*************************************************************************
                154. Factorial
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                input: standard input
                output: standard output
 
 
 
 You task is to find minimal natural number N, so that N! contains exactly Q zeroes on the trail in decimal notation. As you know N! = 1*2*...*N. For example, 5! = 120, 120 contains one zero on the trail.
 
 Input
 One number Q written in the input (0<=Q<=10^8).
 
 Output
 Write "No solution", if there is no such number N, and N otherwise.
 
 Sample test(s)
 
 Input
 2
 
 Output
 10
 ************************************************************************/
#include<iostream>
using namespace std;

long long trailingZeroes(long long n, long long base, long long mul) {
    if(n < 5) return n*5;
    else if(n % base == 0 && n/base == 5) return -1;
    else if(n <= 5*base) return (n/base)*mul + trailingZeroes(n%base, (base-1)/5, mul/5);
    else return trailingZeroes(n, 5*base+1, mul*5);
}

int main() {
    long long n; cin >> n;
    long long v = trailingZeroes(n, 1, 5);
    if (v == 0) cout << 1;
    else if(v % 5 == 0) cout << v;
    else cout << "No solution";
    return 0;
}
