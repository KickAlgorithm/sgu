/*****************************************************************
 
                199. Beautiful People
 
            time limit per test: 0.25 sec.
            memory limit per test: 65536 KB
                input: standard
                output: standard
 
 
 
 The most prestigious sports club in one city has exactly N members. Each of its members is strong and beautiful. More precisely, i-th member of this club (members being numbered by the time they entered the club) has strength Si and beauty Bi . Since this is a very prestigious club, its members are very rich and therefore extraordinary people, so they often extremely hate each other. Strictly speaking, i-th member of the club Mr X hates j-th member of the club Mr Y if Si ≤ Sj and Bi ≥ Bj or if Si ≥ Sj and Bi ≤ Bj (if both properties of Mr X are greater then corresponding properties of Mr Y, he doesn't even notice him, on the other hand, if both of his properties are less, he respects Mr Y very much).
 
 To celebrate a new 2003 year, the administration of the club is planning to organize a party. However they are afraid that if two people who hate each other would simultaneouly attend the party, after a drink or two they would start a fight. So no two people who hate each other should be invited. On the other hand, to keep the club presti≥ at the apropriate level, administration wants to invite as many people as possible.
 
 Being the only one among administration who is not afraid of touching a computer, you are to write a program which would find out whom to invite to the party.
 
 Input
 
 The first line of the input file contains integer N — the number of members of the club. ( 2 ≤ N ≤ 100,000 ). Next N lines contain two numbers each — Si and Bi respectively ( 1 ≤ Si, Bi ≤ 109 ).
 
 Output
 
 On the first line of the output file print the maximum number of the people that can be invited to the party. On the second line output N integers — numbers of members to be invited in arbitrary order. If several solutions exist, output any one.
 
 Sample test(s)
 
 Input
 
 4
 1 1
 1 2
 2 1 
 2 2 
 
 Output
 
 2 
 1 4
 
 *****************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    int first, second, id;
};

struct node a[100009];
int c[100009];
int pre[100009] = {-1};

bool cmp (node a, node b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int find(int len, int i)
{
    int left(1),right(len),mid = (left+right)/2;
    while(left <= right)
    {
        if (a[i].second > a[c[mid]].second)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
        mid = (left + right)/2;
    }
    return left;
}

int main()
{
    int n, i, j, len;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        a[i].id = i;
    }
    sort (a + 1, a + 1 + n, cmp);
    
    c[1] = 1;
    len = 1;
    
    for(i = 2;i <= n;i++)
    {
        j = find(len, i);
        c[j] = i;
        if(j > 1)
            pre[a[i].id] = a[c[j-1]].id;
        if(j > len)
            len = j;
    }

    printf("%d\n",len);
    
    for(int i = a[c[len]].id; i > 0;i = pre[i])
        printf("%d ",i);
    return 0;
}