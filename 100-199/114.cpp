/***********************************************************************
                    114. Telecasting station


                    time limit per test: 0.25 sec.
                    memory limit per test: 4096 KB

Every city in Berland is situated on Ox axis. The government of the country decided to build new telecasting station. After many experiments Berland scientists came to a conclusion that in any city citizens displeasure is equal to product of citizens amount in it by distance between city and TV-station. Find such point on Ox axis for station so that sum of displeasures of all cities is minimal.

Input

Input begins from line with integer positive number N (0<N<15000) – amount of cities in Berland. Following N pairs (X, P) describes cities (0<X, P<50000), where X is a coordinate of city and P is an amount of citizens. All numbers separated by whitespace(s).

Output

Write the best position for TV-station with accuracy 10-5.

Sample Input

4
1 3
2 1
5 2
6 2
Sample Output

3.00000
*************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
    int a;
    int b;
    point()
    {
        a = 0;
        b = 0;
    }
    bool operator < (const point& other) const
    {
        return a < other.a;
    }
};

int main()
{
    int N; cin >> N;
    vector<point>points(N);
    int total = 0;

    while(N--)
    {
        cin >> points[N].a;
        cin >> points[N].b;
        total += points[N].b;
    }

    sort(points.begin(), points.end());
    int v = 0,i = 0;
    while(v < (total+1)/2)
    {
        v += points[i].b;
        i++;
    }
    cout << points[i-1].a << ".00000";


    return 0;
}
