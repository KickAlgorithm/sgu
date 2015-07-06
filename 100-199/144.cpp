/***********************************************************
144. Meeting


time limit per test: 0.25 sec.
memory limit per test: 4096 KB

Two of the three members of the winning team of one of the ACM regional contests are going to meet in order to train for the upcoming World Finals. They decided that they will meet sometime between X o'clock and Y o'clock. Because they never get anywhere on time (they were late even on the day of the regional contest), they did not set an exact time when they will meet. However, they decided that the one who gets first at the meeting point will not wait more than Z minutes for the other one (they calculated that, if the other one will not come within Z minutes from the arrival of the first of them, then it is very probable that he will not show up at all).
Knowing that, in the end, both of them will show up at some time between X o'clock and Y o'clock (not necessarily after an integer number of minutes), compute which is the probability that they will actually meet.

Input

The input will contain 2 integer numbers X and Y (0<=X<Y<=24) and one real number Z ( 0 < Z <= 60*(Y-X) ).

Output

You should output the required probability with 7 decimal digits (rounded according to the 8th decimal digit).

Sample Input

11 12 20.0
Sample Output

0.5555556
 ***********************************************************/
#include<iostream>
#include<cstdio>
using namespace std;


int main() {
    int a,b;
    double v;
    cin >> a >> b >> v;
    
    double total = (b-a)*(b-a)*3600;
    double s = (b-a)*60-v;
    double f = s*s;
    double res = total - f;
    res = res/total;
    printf("%.7f",res);
    return 0;
}
