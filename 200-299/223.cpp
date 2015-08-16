/*************************************************************************
                        223. Little Kings
 
                time limit per test: 0.5 sec.
                memory limit per test: 65536 KB
                        input: standard
                        output: standard
 
 
 
 After solving nice problems about bishops and rooks, Petya decided that he would like to learn to play chess. He started to learn the rules and found out that the most important piece in the game is the king.
 
 The king can move to any adjacent cell (there are up to eight such cells). Thus, two kings are in the attacking position, if they are located on the adjacent cells.
 
 Of course, the first thing Petya wants to know is the number of ways one can position k kings on a chessboard of size n × n so that no two of them are in the attacking position. Help him!
 
 Input
 
 The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).
 
 Output
 
 Print a line containing the total number of ways one can put the given number of kings on a chessboard of the given size so that no two of them are in attacking positions.
 
 Sample test(s)
 
 Input
 Test #1
 
 3 2
 
 Test #2
 
 4 4
 
 Output
 Test #1 
 
 16 
 
 Test #2 
 
 79
 ************************************************************************/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXM=520;
int n,k;
int s[MAXM];//状态数
int c[MAXM];//1的个数
long long f[13][MAXM][103];
int ck;
void dfs(int x,int val,int cnt)//DFS寻找每行的状态数
{
    if(x==n)
    {
        s[++ck]=val;
        c[ck]=cnt;
        return;
    }
    dfs(x+1,val<<1,cnt);
    if(!(val&1))
        dfs(x+1,val<<1|1,cnt+1);
}
bool cont(int s1,int s2)//判断与题意是否矛盾
{
    if(s1&s2) return false;//和正上方判断
    if(s1&(s2<<1))return false;//和右上方判断
    if(s1&(s2>>1))return false;//和左上方判断
    return true;
}
void dp()
{
    //初始化状态
    memset(f,0,sizeof(f));
    f[0][1][0]=1;
    //dp
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=ck;j++)
        {
            for(int g=1;g<=ck;g++)
            {
                for(int p=0;p<=k;p++)
                {
                    if((p >= c[j]) && cont(s[j],s[g]))
                        f[i][j][p]+=f[i-1][g][p-c[j]];
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        ck=0;
        dfs(0,0,0);
        dp();
        long long ans=0;
        
        for(int i=1;i<=ck;++i)
        {
            ans+=f[n][i][k];
        }
        
        cout << ans << endl;
        
    }
    
    
    return 0;
}