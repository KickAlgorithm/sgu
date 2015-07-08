/*************************************************************************
                106. The equation
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 There is an equation ax + by + c = 0. Given a,b,c,x1,x2,y1,y2 you must determine, how many integer roots of this equation are satisfy to the following conditions : x1<=x<=x2,   y1<=y<=y2. Integer root of this equation is a pair of integer numbers (x,y).
 
 Input
 
 Input contains integer numbers a,b,c,x1,x2,y1,y2 delimited by spaces and line breaks. All numbers are not greater than 108 by absolute value.
 
 Output
 
 Write answer to the output.
 
 Sample Input
 
 1 1 -3
 0 4
 0 4
 Sample Output
 
 4
 ************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;

long long x0,yy0;

long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a % b);
}

void exgcd(long long a,long long b)
{
    if (b==0){x0=1;yy0=0;return;}
    exgcd(b,a%b);
    long long t=x0;x0=yy0;yy0=t-a/b*yy0;
    return;
}

int main()
{
    long long a,b,c,x1,x2,y1,y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    c=-c;
    if (c<0) {a=-a;b=-b;c=-c;}
    if (a<0) {a=-a;long long t=x1;x1=-x2;x2=-t;}
    if (b<0) {b=-b;long long t=y1;y1=-y2;y2=-t;}
    if (a==0 && b==0)
    {
        if (c==0)
        {
            cout << (x2-x1+1)*(y2-y1+1);
            return 0;
        }
        cout << 0;
        return 0;
    }
    else if (a==0)
    {
        if (c %b ==0)
            if (c/b<=y2 && c/b>=y1) {cout << x2-x1+1;return 0;}
        cout << 0;return 0;
    }
    else if (b==0)
    {
        if (c%a==0)
            if (c/a<=x2 && c/a>=x1) {cout << y2-y1+1;return 0;}
        cout << 0;return 0;
    }
    
    long long d=gcd(a,b);
    if (c%d!=0){cout << 0;return 0;}
    
    a=a/d;b=b/d;c=c/d;
    exgcd(a,b);
    x0=x0*c;yy0=yy0*c;
    
    double tx2=x2,tx1=x1,tx0=x0,ta=a,tb=b,tc=c,ty1=y1,ty2=y2,ty0=yy0;
    long long down1=floor(((tx2-tx0)/tb)),down2=floor(((ty0-ty1)/ta));
    long long r=min(down1,down2);
    long long up1=ceil(((tx1-tx0)/tb)),up2=ceil(((ty0-ty2)/ta));
    long long l=max(up1,up2);
    if (r<l) cout << 0;
    else cout << r-l+1;
    return 0;
}
