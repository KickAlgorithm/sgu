/*************************************************************************
                        125. Shtirlits
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 
 There is a checkered field of size N x N cells (1 Ј N Ј 3). Each cell designates the territory of a state (i.e. N2 states). Each state has an army. Let A [i, j] be the number of soldiers in the state which is located on i-th line and on j-th column of the checkered field (1£i£N, 1£j£N, 0 £  A[i, j] £  9). For each state the number of neighbors, B [i, j], that have a larger army, is known. The states are neighbors if they have a common border (i.e. 0 £  B[i, j]  £  4). Shtirlits knows matrix B. He has to determine the number of armies for all states (i.e. to find matrix A) using this information for placing forces before the war. If there are more than one solution you may output any of them.
 
 Input
 
 The first line contains a natural number N. Following N lines contain the description of matrix B - N numbers in each line delimited by spaces.
 
 Output
 
 If a solution exists, the output file should contain N lines, which describe matrix A. Each line will contain N numbers delimited by spaces. If there is no solution, the file should contain NO SOLUTION.
 
 Sample Input
 
 3
 1 2 1
 1 2 1
 1 1 0
 Sample Output
 
 1 2 3
 1 4 5
 1 6 7
 ************************************************************************/
#include<iostream>
using namespace std;

int n;
int a[4][4];
int b[4][4];

bool dfs(int ci, int cj)
{
    if(ci >= n)
    {
        if (a[n-1][n-1] == 0) return true;
        return false;
    }
    int ni,nj;
    if(cj == n-1) {
        ni = ci+1;
        nj = 0;
    } else {
        ni = ci;
        nj = cj+1;
    }
    
    for(int k = 0;k <= 9;k++)
    {
        b[ci][cj] = k;
        int lefti(-1),leftj(-1),upi(-1),upj(-1);
        int r1(-1),c1(-1),r2(-1),c2(-1);
        bool f1(false),f2(false);
        bool check = true;
        
        if(cj != 0 && n > 1)
        {
            lefti = ci;
            leftj = cj-1;
            if(k > b[lefti][leftj])
            {
                r1 = lefti;
                c1 = leftj;
            } else if(k < b[lefti][leftj]) {
                r1 = ci;
                c1 = cj;
            }
        }
        
        if(ci != 0 && n > 1)
        {
            upi = ci-1;
            upj = cj;
            if(k > b[upi][upj])
            {
                r2 = upi;
                c2 = upj;
            } else if(k < b[upi][upj]) {
                r2 = ci;
                c2 = cj;
            }
        }
        
        if(upi != -1)
        {
            if(a[upi][upj] > 1) return false;
            if(a[upi][upj] == 1 && k <= b[upi][upj]) continue;
        }
        
        if(lefti != -1)
        {
            if(a[lefti][leftj] > 2) return false;
            if(a[lefti][leftj] == 2 && ci == n-1) return false;
            if(a[lefti][leftj] == 2 && k <= b[lefti][leftj]) continue;
            if(a[lefti][leftj] == 1 && ci == n-1 && k <= b[lefti][leftj]) continue;
        }
        
        
        if(r1 != -1)
        {
            if(a[r1][c1] > 0)
            {
                
                a[r1][c1]--;
                f1 = true;
            }
            else check = false;
        }
        
        if(r2 != -1)
        {
            if(a[r2][c2] > 0)
            {
                a[r2][c2]--;
                f2 = true;
            }
            else check = false;
        }
        
        bool fff = false;
        
        if(check)
        {
            fff = dfs(ni, nj);
            if(fff)
                return true;
        }
        if(f1) a[r1][c1]++;
        if(f2) a[r2][c2]++;
        
    }
    
    return false;
}

int main() {
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> a[i][j];
    
    bool fff = dfs(0,0);
    if(n == 1)
    {
        if(a[0][0] > 0) cout << "NO SOLUTION";
        else cout << 0 << endl;
        return 0;
    }
    if(!fff) {
        cout << "NO SOLUTION";
        return 0;
    } else {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}