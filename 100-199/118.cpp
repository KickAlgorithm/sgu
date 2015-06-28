/************************************************************
 
                    118. Digital Root
 
 
                    time limit per test: 0.25 sec.
                    memory limit per test: 4096 KB
 
 Let f(n) be a sum of digits for positive integer n. If f(n) is one-digit number then it is a digital root for n and otherwise digital root of n is equal to digital root of f(n). For example, digital root of 987 is 6. Your task is to find digital root for expression A1*A2*…*AN + A1*A2*…*AN-1 + … + A1*A2 + A1.
 
 Input
 
 Input file consists of few test cases. There is K (1<=K<=5) in the first line of input. Each test case is a line. Positive integer number N is written on the first place of test case (N<=1000). After it there are N positive integer numbers (sequence A). Each of this numbers is non-negative and not more than 109.
 
 Output
 
 Write one line for every test case. On each line write digital root for given expression.
 
 Sample Input
 
 1
 3 2 3 4
 Sample Output
 
 5
 
************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    while(N--)
    {
        int d;cin >> d;
        int sum(0);
        int tmp(1);
        while(d--)
        {
            int a; cin >> a;
            a %= 9;
            tmp *= a;
            tmp %= 9;
            sum += tmp;
        }
        sum %= 9;
        if(sum == 0) cout << 9 << endl;
        else cout << sum << endl;
    }

    return 0;
}
