/*************************************************************************
                        403. Scientific Problem
 
                Time limit per test: 0.25 second(s)
                Memory limit: 65536 kilobytes
                        input: standard
                        output: standard
 
 
 
 Once upon a time Professor Idioticideasinventor was travelling by train. Watching cheerless landscape outside the window, he decided to invent the theme of his new scientific work. All of a sudden a brilliant idea struck him: to develop an effective algorithm finding an integer number, which is x times less than the sum of all its integer positive predecessors, where number x is given. As far as he has no computer in the train, you have to solve this difficult problem.
 
 Input
 The first line of the input file contains an integer number x (1 ≤ x ≤ 109).
 
 Output
 Output an integer number — the answer to the problem.

 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int x;
    while(scanf("%d", &x) != EOF) {
        printf("%d\n", 2*x+1);
    }
    return 0;
}
