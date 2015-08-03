/*************************************************************************
                        186. The Chain
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                    input: standard input
                    output: standard output
 
 
 
 Smith has N chains. Each chain is the sequence of successively connected links. The length of each chain is known: the first chain contains L1 links, the second - L2, ..., the last one - LN.
 He can make a following series of actions in a minute:
 1.	to unchain one link
 2.	to remove or to put into the unchained link some other links of any chain
 3.	to chain the link
 Your task is to determine the minimum time which will take the smith to connect all the chains in one line, i.e. the chain will look like a chain made up of successively connected links.
 
 Input
 The first line contains natural number N<=100. The second line contains L1, L2, ..., LN (1<=Li<=100, for all i = 1..N).
 
 Output
 Output the only integer number - the solution to the problem.
 
 Sample test(s)
 
 Input
 2 
 3 4
 
 Output
 1
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int a[110], n, l, r, ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    r = n - 1;
    sort (a, a + n);
    while (l < r) {
        a[l]--, r--;
        if (!a[l]) l++;
        ans++;
    }
    cout << ans;
    return 0;
}