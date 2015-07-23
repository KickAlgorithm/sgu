/*************************************************************************
                        146. The Runner
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                    input: standard input
                    output: standard output
 
 
 
 The runner moves along the ring road with length L. His way consists of N intervals. First he ran T1 minutes with speed V1, then T2 minutes with speed V2 and so on till the N-th interval, where he ran TN minutes with speed VN. Your task is to find the distance from start to finish along the ring road. The distance along the ring road is the length of the shortest way all points of which belongs to the ring road.
 
 Input
 Real number L (1<=L<=1000, with 4 signs after decimal point) and natural number N (N<=20000) are written in the first line. Each of the following N lines contains two integer numbers Ti and Vi (1<=Ti<=10^7, 1<=Vi<=10^6).
 
 Output
 Write the only one real number with 4 digits after decimal points: the distance from start to finish.
 
 Sample test(s)
 
 Input
 2 1
 1 3
 
 Output
 1.0000
 ************************************************************************/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
    double len;
    int N;
    long long res(0);
    long long C;
    
    cin >> len >> N;
    C = round(len*10000);
    long long t,s;
    for(int i = 0;i < N;i++)
    {
        cin >> s >> t;
        res = (res + s*t*10000)%C;
    }
    
    double ans = (res*1.0)/10000;
    
    if(ans <= len/2) printf("%.4f", ans);
    else printf("%.4f", len - ans);

    return 0;
}
