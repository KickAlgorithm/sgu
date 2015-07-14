/*************************************************************************
                    103. Traffic Lights
 
                Time limit per test: 0.25 second(s)
                Memory limit: 4096 kilobytes
                input: standard
                output: standard
 
 
 
 In the city of Dingilville the traffic is arranged in an unusual way. There are junctions and roads connecting the junctions. There is at most one road between any two different junctions. There is no road connecting a junction to itself. Travel time for a road is the same for both directions. At every junction there is a single traffic light that is either blue or purple at any moment. The color of each light alternates periodically: blue for certain duration and then purple for another duration. Traffic is permitted to travel down the road between any two junctions, if and only if the lights at both junctions are the same color at the moment of departing from one junction for the other. If a vehicle arrives at a junction just at the moment the lights switch it must consider the new colors of lights. Vehicles are allowed to wait at the junctions. You are given the city map which shows:
 the travel times for all roads (integers)
 the durations of the two colors at each junction (integers)
 and the initial color of the light and the remaining time (integer) for this color to change at each junction.
 
 Your task is to find a path which takes the minimum time from a given source junction to a given destination junction for a vehicle when the traffic starts. In case more than one such path exists you are required to report only one of them.
 
 Input
 The first line contains two numbers: The id-number of the source junction and the id-number of the destination junction. The second line contains two numbers: N, M. The following N lines contain information on N junctions. The (i+2)'th line of the input file holds information about the junction i : Ci, riC, tiB, tiP where Ci is either B for blue or P for purple, indicating the initial color of the light at the junction i. Finally, the next M lines contain information on M roads. Each line is of the form: i, j, lij where i and j are the id-numbers of the junctions which are connected by this road. 2 ≤ N ≤ 300 where N is the number of junctions. The junctions are identified by integers 1 through N. These numbers are called id-numbers. 1 ≤ M ≤ 14000 where M is the number of roads. 1 ≤ lij ≤ 100 where lij is the time required to move from junction i to j using the road that connects i and j. 1 ≤ tiC ≤ 100 where tiC is the duration of the color c for the light at the junction i. The index c is either 'B' for blue or 'P' for purple. 1 ≤ riC ≤ tiC where riC is the remaining time for the initial color c at junction i.
 
 Output
 If a path exists:
 The first line will contain the time taken by a minimum-time path from the source junction to the destination junction.
 Second line will contain the list of junctions that construct the minimum-time path you have found. You have to write the junctions to the output file in the order of travelling. Therefore the first integer in this line must be the id-number of the source junction and the last one the id-number of the destination junction.
 
 If a path does not exist:
 A single line containing only the integer 0.
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<queue>

using namespace std;

int n,m,st,ed;
int r[310],c[310],ans[310],dist[310],last[310];
int t[310][2];
int map[310][310];
bool v[310];
int q[30010];

inline int cmin(const int &x,const int &y) {return x<y?x:y;}

void init()
{
    scanf("%d%d%d%d",&st,&ed,&n,&m);
    for (int i=1;i<=n;i++)
    {
        char ch[5];
        scanf("%s%d%d%d",ch,&r[i],&t[i][0],&t[i][1]);
        if (ch[0]=='B') c[i]=0;else c[i]=1;
    }
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        map[x][y]=z;map[y][x]=z;
    }
}

void color(int a,int time,int& ca,int& ta)
{
    if (time<r[a]) {ta=r[a];ca=c[a];return;}
    else
    {
        int temp=(time-r[a])%(t[a][0]+t[a][1]);
        int now=time-temp;
        if (c[a]==1)
        {
            if (temp<t[a][0]) {ca=0;ta=now+t[a][0];return;}
            else {ca=1;ta=now+t[a][0]+t[a][1];return;}
        }
        else
        {
            if (temp<t[a][1]) {ca=1;ta=now+t[a][1];return;}
            else {ca=0;ta=now+t[a][0]+t[a][1];return;}
        }
    }
}

int calctime(int a,int b,int time,int f)
{
    int ca,cb,ta,tb;
    color(a,time,ca,ta);color(b,time,cb,tb);
    if (ca==cb) return time;
    if (ta==tb)
    {
        if (f==0) {return calctime(a,b,ta,1);}
        else if (time<=r[a]||time<=r[b]) return calctime(a,b,ta,1);
        else return INT_MAX;
    }
    return cmin(ta,tb);
}

void spfa()
{
    fill(v, v+310, false);
    for (int i=1;i<=n;i++) dist[i]=INT_MAX;
    int head=0,tail=1;
    v[st]=true;q[1]=st;dist[st]=0;last[st]=0;
    while (head<tail)
    {
        head++;
        int now=q[head];
        for (int i=1;i<=n;i++)
        {
            if (map[now][i]>0)
            {
                int temp=calctime(now,i,dist[now],0);
                if (temp>=INT_MAX) continue;
                if (temp+map[now][i]<dist[i])
                {
                    dist[i]=temp+map[now][i];
                    last[i]=now;
                    if (!v[i]) {tail++;q[tail]=i;v[i]=true;}
                }
            }
        }
        v[q[head]]=false;
    }
    if (dist[ed]>=INT_MAX) {printf("0");return;}
    printf("%d\n",dist[ed]);
    int now=ed,len=0;
    while (now!=0) {len++;ans[len]=now;now=last[now];}
    for (int i=len;i>=2;i--) printf("%d ",ans[i]);
    printf("%d\n",ans[1]);
    return;
}

int main()
{
    init();
    spfa();
    return 0;
}