/*
 There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . Given first N elements of that sequence. You must determine amount of numbers in it that are divisible by 3.
 
 Input
 
 Input contains N (1<=N<=231 - 1).
 
 Output
 
 Write answer to the output.
 
 Sample Input
 
 4
 Sample Output
 
 2
 */

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int ans = 0;
    if (N % 3 == 2)
    ans++;
    ans += 2 * (N / 3);
    cout << ans;
    
    return 0;
}
