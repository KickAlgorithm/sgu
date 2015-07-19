/*************************************************************************
                        124. Broken line
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 There is a closed broken line on a plane with sides parallel to coordinate axes, without self-crossings and self-contacts. The broken line consists of K segments. You have to determine, whether a given point with coordinates (X0,Y0) is inside this closed broken line, outside or belongs to the broken line.
 
 Input
 
 The first line contains integer K (4 Ј K Ј 10000) - the number of broken line segments. Each of the following N lines contains coordinates of the beginning and end points of the segments (4 integer xi1,yi1,xi2,yi2; all numbers in a range from -10000 up to 10000 inclusive). Number separate by a space. The segments are given in random order. Last line contains 2 integers X0 and Y0 - the coordinates of the given point delimited by a space. (Numbers X0, Y0 in a range from -10000 up to 10000 inclusive).
 
 Output
 
 The first line should contain:
 
 INSIDE - if the point is inside closed broken line,
 
 OUTSIDE - if the point is outside,
 
 BORDER - if the point belongs to broken line.
 
 Sample Input
 
 4
 0 0 0 3
 3 3 3 0
 0 3 3 3
 3 0 0 0
 2 2
 Sample Output
 
 INSIDE
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn(10030);
int x1[maxn],x2[maxn],y1[maxn],y2[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (x1[i]==x2[i] && y1[i] > y2[i])
            swap(y1[i], y2[i]);
        if (y1[i]==y2[i] && x1[i] > x2[i])
            swap(x1[i],x2[i]);
    }
    
    int x0,y0;
    cin >> x0 >> y0;
    for (int i=1;i<=n;i++)
    {
        if ((x1[i]==x2[i]) && (x1[i]==x0) && (y1[i]<=y0) && (y2[i]>=y0))
        {
            cout << "BORDER";
            return 0;
        }
        if ((y1[i]==y2[i]) && (y1[i]==y0) && (x1[i]<=x0) && (x2[i]>=x0))
        {
            cout << "BORDER";
            return 0;
        }
    }
    
    int t=0;
    for (int i=1;i<=n;i++)
        if ((y1[i]==y2[i]) && (y1[i]>y0) && (x1[i]<x0) && (x2[i]>=x0)) t++;
    
    if (t % 2 == 1) cout << "INSIDE";
    else cout << "OUTSIDE";
    
    return 0;
}