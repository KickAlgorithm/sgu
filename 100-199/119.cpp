/*************************************************************************
                        119. Magic Pairs
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 “Prove that for any integer X and Y if 5X+4Y is divided by 23 than 3X+7Y is divided by 23 too.” The task is from city Olympiad in mathematics in Saratov, Russia for schoolchildren of 8-th form. 2001-2002 year.
 
 
 For given N and pair (A0, B0) find all pairs (A, B) such that for any integer X and Y if A0X+B0Y is divided by N then AX+BY is divided by N too (0<=A,B<N).
 
 Input
 
 Each input consists of positive integer numbers N, A0 and B0 (N,A0,B0£ 10000) separated by whitespaces.
 
 Output
 
 Write number of pairs (A, B) to the first line of output. Write each pair on a single line in order of non-descreasing A (and B in case of equal A). Separate numbers by single space.
 
 Sample Input
 
 3
 1 2
 Sample Output
 
 3 
 0 0
 1 2
 2 1
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    
    pair<int, int> ans[10010];
    int n,a0,b0;
    scanf("%d%d%d",&n,&a0,&b0);
    
    int i = a0 %= n;
    int j = b0 %= n;
    int num = 0;
    
    do {
        ans[num++] = make_pair(i, j);
        i = (i+a0)%n;
        j = (j+b0)%n;
    } while(i != a0 || j != b0);
    
    sort(ans, ans+num);
    printf("%d\n",num);
    for(i = 0;i < num;i++)
        printf("%d %d\n",ans[i].first,ans[i].second);

    return 0;
}
