/*************************************************************************
                        152. Making round
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                        input: standard input
                        output: standard output
 
 
 
 Extraordinary things are around us! All citizens of democratic Berland provided election of president and nobody voted "against all candidates". All votes distributed between N candidates. You was charged to write a program to calculate the results of election. You must indicate a part of votes given to each of the candidates. You must write integer numbers, concidering two conditions:
 - Total sum of parts must be exactly 100%
 - Every part is an integer number and it must be equal to real part, rounded up or down.
 
 Input
 There is a natural number N (1<=N<=10000) written in the first line - amount of candidates. Second line contains sequence of non-negative integer numbers A1, A2,..., AN; Ai is amount of votes given to the i-th candidate (Ai<=10000). Numbers of sequence are separated by one or more spaces.
 
 Output
 Write sequence of sought parts. Separate numbers by a space. If solution does not exist, write "No solution". If there are several solutions write any of them.
 
 Sample test(s)
 
 Input
 2
 10 10
 
 Output
 50 50
 ************************************************************************/
#include<iostream>
using namespace std;


int main() {
    int a[10001];
    int N;cin >> N;
    int sum(0);
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int re(0);
    
    for(int i = 0;i < N;i++)
    {
        int temp = a[i] * 100 / sum;
        re += a[i] * 100 - temp * sum;
        if(re >= sum)
        {
            re -= sum;
            temp++;
        }
        cout << temp << " ";
    }

    return 0;
}