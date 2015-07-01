/*******************************************************
                130. Circle
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 On a circle border there are 2k different points A1, A2, ..., A2k, located contiguously. These points connect k chords so that each of points A1, A2, ..., A2k is the end point of one chord. Chords divide the circle into parts. You have to find N - the number of different ways to connect the points so that the circle is broken into minimal possible amount of parts P.
 
 Input
 
 The first line contains the integer k (1 <= k <= 30).
 
 Output
 
 The first line should contain two numbers N and P delimited by space.
 
 Sample Input
 
 2
 Sample Output
 
 2 3
 *******************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long p[31];

int main(){

    int k;cin >> k;
    fill(p, p+31, 0);
    p[0]=1;
    for(int i = 1;i <= k;i++)
        for(int j = 0;j < i;j++)
            p[i] += p[j]*p[i-j-1];
    cout << p[k] << " " << k+1;

    return 0;
}