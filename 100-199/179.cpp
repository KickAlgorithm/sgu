/*************************************************************************
                        179. Brackets light
 
                time limit per test: 0.25 sec.
                memory limit per test: 131072 KB
                        input: standard
                        output: standard
 
 
 
 There is a correct brackets sequence. It's length doesn't exceed 10000 symbols.
 Your task is to find next (in lexicographic order) correct brackets sequence with the same length. You may assume that '(' < ')'.
 
 Input
 The first line of the input contains correct brackets sequence. There are only '(' and ')' symbols in the input.
 
 Output
 Write sought sequence in the single line of the output or 'No solution' if solution doesn't exist.
 
 Sample test(s)
 
 Input
 (())()
 
 Output
 ()(())

 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int f[11111], flag;
string s;

int main() {
    cin >> s;
    int s1 = 0, s2 = 0, len = s.size() - 1;

    for (int i = 0; i <= len; i++) {
        if (s[i] == '(')
            f[i] = s1++;
        else
            f[i] = s2++;
    }
    
    for (int i = len, t; i >= 0; i--) {
        if (s[i] == ')') t = i;
        else if (f[t] < f[i]) {
            swap (s[len], s[i]);
            reverse (s.begin() + i + 1, s.end() );
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "No solution";
    else
        cout << s;
}