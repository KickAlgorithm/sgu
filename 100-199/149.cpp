/*************************************************************************
                        149. Computer Network
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                        input: standard input
                        output: standard output
 
 
 
 A school bought the first computer some time ago. During the recent years the school bought N-1 new computers. Each new computer was connected to one of settled earlier. Managers of school are anxious about slow functioning of the net and want to know for each computer number Si - maximum distance, for which i-th computer needs to send signal (i.e. length of cable to the most distant computer). You need to provide this information.
 
 Input
 There is natural number N (N<=10000) in the first line of input, followed by (N-1) lines with descriptions of computers. i-th line contains two natural numbers - number of computer, to which i-th computer is connected and length of cable used for connection. Total length of cable does not exceed 10^9. Numbers in lines of input are separated by a space.
 
 Output
 Write N lines in output file. i-th line must contain number Si for i-th computer (1<=i<=N).
 
 Sample test(s)
 
 Input
 3
 1 1
 1 2
 
 Output
 2 
 3 
 3

 ************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
const int maxx = 10010;

struct Edge
{
    int p;
    int c;
    int v;
    Edge():p(-1),c(-1),v(-1){}
    Edge(int _p, int _c, int _v):p(_p),c(_c),v(_v){}
};

Edge edges[maxx];
vector<int> maps[maxx];
int plarge[maxx];
int slarge[maxx];
int from[maxx];
int res[maxx];

void dfs(int cur, int pathsum)
{
    res[cur] = max(plarge[cur], pathsum);
    int f = from[cur];
    for(int i = 0;i < maps[cur].size();i++)
    {
        Edge e = edges[maps[cur][i]];
        int c = e.c;
        int v = e.v;
        if(f == c) {
            dfs(c, max(slarge[cur], pathsum)+v);
        } else {
            dfs(c, max(plarge[cur], pathsum)+v);
        }
    }
}


int main() {
    fill(plarge, plarge+maxx, 0);
    fill(slarge, slarge+maxx, 0);
    cin >> N;
    for(int i = 1;i < N;i++)
    {
        int p;
        int v;
        cin >> p >> v;
        int c = i+1;
        edges[i] = Edge(p, c, v);
        maps[p].push_back(i);
    }
    
    for(int i = N;i >= 2;i--)
    {
        Edge e = edges[i-1];
        int p = e.p;
        if(plarge[p] == 0)
        {
            plarge[p] = plarge[i] + e.v;
            from[p] = i;
        } else {
            if(plarge[p] < plarge[i] + e.v)
            {
                int temp = plarge[p];
                plarge[p] = plarge[i] + e.v;
                from[p] = i;
                if(temp > slarge[p]) slarge[p] = temp;
            } else if (plarge[p] > plarge[i] + e.v) {
                if(plarge[i] + e.v > slarge[p])
                    slarge[p] = plarge[i] + e.v;
            } else {
                slarge[p] = plarge[p];
            }
        }
    }
    
    dfs(1,0);
    
    for(int i = 1;i <= N;i++)
        cout << res[i] << endl;

    return 0;
}
