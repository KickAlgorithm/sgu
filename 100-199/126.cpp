/************************************************************
                126. Boxes
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 There are two boxes. There are A balls in the first box, and B balls in the second box (0 < A + B < 2147483648). It is possible to move balls from one box to another. From one box into another one should move as many balls as the other box already contains. You have to determine, whether it is possible to move all balls into one box.
 
 Input
 
 The first line contains two integers A and B, delimited by space.
 
 Output
 
 First line should contain the number N - the number of moves which are required to move all balls into one box, or -1 if it is impossible.
 
 Sample Input
 
 Sample Output
 
 2 6
 Sample Output
 
 2
 ************************************************************/

#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main()
{
    int a,b; cin >> a >> b;
    int v = (a+b)/gcd(min(a,b),max(a,b));

    for(int i = 0;i < 32;i++)
    {
        if(abs(pow(2, i) - v) < 1e-5)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
