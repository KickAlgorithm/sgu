/**************************************************************
                133. Border
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 Along the border between states A and B there are N defence outposts. For every outpost k, the interval [Ak,Bk] which is guarded by it is known. Because of financial reasons, the president of country A decided that some of the outposts should be abandoned. In fact, all the redundant outposts will be abandoned. An outpost i is redundant if there exists some outpost j such that Aj<Ai and Bi<Bj. Your task is to find the number of redundant outposts.
 
 Input
 
 The first line of the input will contain the integer number N (1<=N<=16 000). N lines will follow, each of them containing 2 integers: Ak and Bk (0<= Ak < Bk <= 2 000 000 000), separated by blanks. All the numbers Ak will be different. All the numbers Bk will be different.
 
 Output
 
 You should print the number of redundant outposts.
 
 Sample Input
 
 5
 0 10
 2 9
 3 8
 1 15
 6 11
 Sample Output
 
 3
 **************************************************************/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval a, Interval b)
{
    return (a.start < b.start);
}

int merge(vector<Interval> &intervals) {
        
    int res(0);
    sort(intervals.begin(),intervals.end(),compareInterval);
        
    Interval now = intervals[0];
    for(int i = 1;i < intervals.size();i++)
    {
        Interval then = intervals[i];
            
        if(now.end >= then.start)
        {
            if(now.end > then.end) res++;
            now.end = max(now.end, then.end);
        } else {
            now = then;
        }
    }
    return res;
}

int main()
{
    int N;cin >> N;
    vector<Interval> intervals;
    while(N--)
    {
        int a,b;
        cin >> a;
        cin >> b;
        intervals.push_back(Interval(a, b));
    }
    merge(intervals);
    return 0;
}