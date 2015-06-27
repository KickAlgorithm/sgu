/*************************************************************************
                116. Index of super-prime


                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB

Let P1, P2, … ,PN, … be a sequence of prime numbers. Super-prime number is such a prime number that its current number in prime numbers sequence is a prime number too. For example, 3 is a super-prime number, but 7 is not. Index of super-prime for number is 0 iff it is impossible to present it as a sum of few (maybe one) super-prime numbers, and if such presentation exists, index is equal to minimal number of items in such presentation. Your task is to find index of super-prime for given numbers and find optimal presentation as a sum of super-primes.

Input

There is a positive integer number in input. Number is not more than 10000.

Output

Write index I for given number as the first number in line. Write I super-primes numbers that are items in optimal presentation for given number. Write these I numbers in order of non-increasing.

Sample Input

6
Sample Output

2
3 3
************************************************************************/
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    
    int super[201] = { 3, 5, 11, 17, 31, 41, 59, 67, 83, 109, 127, 157, 179, 191, 211, 241, 277, 283, 331, 353, 367, 401, 431, 461, 509, 547, 563, 587, 599, 617, 709, 739, 773, 797, 859, 877, 919, 967, 991, 1031, 1063, 1087, 1153, 1171, 1201, 1217, 1297, 1409, 1433, 1447, 1471, 1499, 1523, 1597, 1621, 1669, 1723, 1741, 1787, 1823, 1847, 1913, 2027, 2063, 2081, 2099, 2221, 2269, 2341, 2351, 2381, 2417, 2477, 2549, 2609, 2647, 2683, 2719, 2749, 2803, 2897, 2909, 3001, 3019, 3067, 3109, 3169, 3229, 3259, 3299, 3319, 3407, 3469, 3517, 3559, 3593, 3637, 3733, 3761, 3911, 3943, 4027, 4091, 4133, 4153, 4217, 4273, 4339, 4397, 4421, 4463, 4517, 4549, 4567, 4663, 4759, 4787, 4801, 4877, 4933, 4943, 5021, 5059, 5107, 5189, 5281, 5381, 5441, 5503, 5557, 5623, 5651, 5701, 5749, 5801, 5851, 5869, 6037, 6113, 6217, 6229, 6311, 6323, 6353, 6361, 6469, 6599, 6653, 6661, 6691, 6823, 6841, 6863, 6899, 7057, 7109, 7193, 7283, 7351, 7417, 7481, 7523, 7607, 7649, 7699, 7753, 7841, 7883, 8011, 8059, 8101, 8117, 8221, 8233, 8287, 8377, 8389, 8513, 8527, 8581, 8719, 8747, 8761, 8807, 8849, 8923, 8999, 9041, 9103, 9293, 9319, 9403, 9461, 9539, 9619, 9661, 9739, 9833, 9859, 9923, 9973 };

    int N; cin >> N;
    int *dp = new int[N+1];
    int *path = new int[N+1];
    fill(dp,dp+N+1,INT_MAX);
    fill(path,path+N+1,-1);
    dp[0] = 0;

    for(int i = 0;i <= N;i++)
    {
        for(int j = 0;j < 201 && (i + super[j] <= N);j++)
        {
            if(dp[i] < INT_MAX && dp[i+super[j]] > dp[i]+1)
            {
                dp[i + super[j]] = dp[i]+1;
                path[i+super[j]] = i;
            }
        }
    }
        
    if(dp[N] != INT_MAX) {  
        cout << dp[N] << endl;    
        while(N > 0) {  
            cout << N - path[N] << " ";  
            N = path[N];
        }  
    } else {
        cout << 0;
    }  
    
    return 0;
}
