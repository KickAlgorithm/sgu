/*************************************************************************
                        358. Median of Medians

                Time limit per test: 0.25 second(s)
                Memory limit: 65536 kilobytes
                        input: standard
                        output: standard
 
 
 
 Vasya learned definition of median of three numbers. He says, "Median of three numbers is the number located in the middle when numbers are ordered in non-descending order". Subtle Pete gave him much more difficult task. Vasya has to find median of each of three triples and then find the median of three numbers he found. Please help Vasya with the task.
 
 Input
 The input file contains three lines. Each line contains three integers. Each number is not less than -1000 and is not greater than 1000.
 
 Output
 Print one number - median of three medians.
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5];
int ans[5];

int main() {
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &a[j]);
        }
        sort(a, a + 3);
        ans[i] = a[1];    
    }

    sort(ans, ans + 3);
    printf("%d\n", ans[1]);
    return 0;
} 
