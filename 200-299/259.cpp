/*************************************************************************
                        259. Printed PR
 
                time limit per test: 0.25 sec.
                memory limit per test: 65536 KB
                        input: standard
                        output: standard
 
 
 
 Small PR-agency got an order to print a very big lot of agitational materials. Agency should print and deliver N leaflets. Agency is very small and has only one printer, but it can print any leaflet. Leaflets can be different, so it is possible that times of printing of leaflets will differ. To print i-th leaflet the printer needs Ti minutes. When leaflet is printed, it should be immediately delivered to its addressee. The agency has unlimited number of couriers, so the courier gets the leaflet as soon as it printed and goes to the addressee. It takes Li minutes to deliver i-th leaflet. You were hired by agency to calculate the minimal time required to finish the job (this is an interval of time from the beginning of printing to the moment when the last leaflet is delivered), considering that the leaflets can be printed in any order.
 
 Input
 The first line contains a number of leaflets - integer number N (1 <= N <= 100). The second line contains N integer numbers Ti (1 <= i <= N). Third line contains N integer numbers Li (1 <= i <= N). You can assume that 1 <= Ti, Li <= 1000.
 
 Output
 You should output only one number - the answer for the problem.
 
 Sample test(s)
 
 Input
 2
 2 1 
 2 1
 
 Output
 4

 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node{
    int t,l;
    node(){}
    node(int tt, int ll):t(tt),l(ll){}
    bool operator < (const node & rhs) const{
        return l > rhs.l;
    }
} ev[110];

int main(void)
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    cin >> ev[i].t;
    for(int i = 0; i < N; ++i)
    cin >> ev[i].l;
    sort(ev,ev+N);
    
    int ans = 0,cur = 0;
    for(int i = 0; i < N; ++i){
        cur += ev[i].t;
        ans = max(ans,cur + ev[i].l);
    }
    cout << ans;
    return 0;
}