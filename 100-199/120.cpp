/*************************************************************************
                        120. Archipelago
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 Archipelago Ber-Islands consists of N islands that are vertices of equiangular and equilateral N-gon. Islands are clockwise numerated. Coordinates of island N1 are (x1, y1), and island N2 – (x2, y2). Your task is to find coordinates of all N islands.
 
 Input
 
 In the first line of input there are N, N1 and N2 (3£ N£ 150, 1£ N1,N2£N, N1¹N2) separated by spaces. On the next two lines of input there are coordinates of island N1 and N2 (one pair per line) with accuracy 4 digits after decimal point. Each coordinate is more than -2000000 and less than 2000000.
 
 Output
 
 Write N lines with coordinates for every island. Write coordinates in order of island numeration. Write answer with 6 digits after decimal point.
 
 Sample Input
 
 4 1 3
 1.0000 0.0000
 1.0000 2.0000
 Sample Output
 
 1.000000 0.000000
 0.000000 1.000000
 1.000000 2.000000
 2.000000 1.000000
 ************************************************************************/
#include<cstdio>
#include<cmath>
#include<algorithm>

#define pf(x) ((x)*(x))
const double EPS=1e-9;
using namespace std;

void rotate(double &vx,double &vy,double theta)
{
    double tx=cos(theta)*vx+sin(theta)*vy;
    double ty=cos(theta)*vy-sin(theta)*vx;
    vx=tx,vy=ty;
}

int main()
{
    int n,n1,n2,i;
    double a,b,r,d,vx,vy,x1,y1,x2,y2,h,dx,dy,theta;
    scanf("%d%d%d",&n,&n1,&n2);
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    
    if(n1>n2)
    {
        swap(n1,n2);
        swap(x1,x2);
        swap(y1,y2);
    }
    d=sqrt(pf(x2-x1)+pf(y2-y1));
    a=(x1+x2)/2;
    b=(y1+y2)/2;
    
    if(2*(n2-n1)!=n)
    {
        theta=2*M_PI/n*(n2-n1);
        if(theta>M_PI)
            theta=2*M_PI-theta;
        r=d*sin((M_PI-theta)/2)/sin(theta);  //正弦定理
        vx=x2-x1,vy=y2-y1;
        h=sqrt(r*r-pf(d/2));
        
        //相似三角形
        dx=-h*vy/d;
        dy=h*vx/d;
        
        a+=dx,b+=dy;
        if(((x1-a)*(y2-b)-(x2-a)*(y1-b))*(2*(n2-n1)-n)<0)
            a-=2*dx,b-=2*dy;
    }
    
    vx=x1-a,vy=y1-b;
    theta=2*M_PI/n;
    rotate(vx,vy,-theta*n1);
    for(i=1;i<=n;++i)
    {
        rotate(vx,vy,theta);
        if(abs(vx+a)<EPS)
            printf("0.000000 ");
        else
            printf("%.6lf ",vx+a);
        if(abs(vy+b)<EPS)
            puts("0.000000");
        else
            printf("%.6lf\n",vy+b);
    }
    return 0;
}