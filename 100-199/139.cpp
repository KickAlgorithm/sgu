/*************************************************************************
                        139. Help Needed!
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 Little Johnny likes puzzles a lot! Just a few days ago, he found out about the 'traditional' 4x4 puzzle. For this puzzle, you have all the numbers from 0 to 15 arranged in 4 rows and 4 columns. You are allowed to switch two adjacent elements (horizontally or vertically), only if one of them has the value 0. The purpose of the puzzle is to reach the following final state:
 
 1  2  3  4
 5  6  7  8
 9 10 11 12
 13 14 15  0
 
 Given the initial state of the puzzle, you have to decide whether there exists a sequence of moves which brings the puzzle into the final state.
 
 Input
 
 The input will consist of  4 lines, each of them containing 4 integers, describing the initial state of the puzzle.
 
 Output
 
 For every initial state, you should print "YES" if the final state can be reached after several moves or "NO", if such a thing is impossible.
 
 Sample Input #1
 
 1 2 3 4
 5 6 7 8
 9 10 11 0
 13 14 15 12
 Sample Output #1
 
 YES
 Sample Input #2
 
 2 1 3 4
 5 6 7 8
 9 10 11 12
 0 13 14 15
 Sample Output #2
 
 NO
 ************************************************************************/
#include<iostream>
using namespace std;

int main() {
    int a[16];
    int row = 0;
    for(int i = 0;i < 16;i++)
    {
        cin >> a[i];
        if(a[i] == 0)
            row = i/4;
    }
    row = 3 - row;
    
    int inv = 0;
    for(int i = 0;i < 15;i++)
        for(int j = i + 1;j < 16;j++)
            if(a[j] < a[i] && a[j] != 0)
                inv++;

    if( (inv % 2 == 0 && row % 2 == 0) || (inv % 2 == 1 && row % 2 == 1))
        cout << "YES";
    else
        cout << "NO";
    

    return 0;
}
