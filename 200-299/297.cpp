/*************************************************************************
                        297. Fair-play
 
                Time limit per test: 0.25 second(s)
                Memory limit: 65535 kilobytes
                        input: standard
                        output: standard
 
 
 
 Once after the regular working week a group of N friends gathered and went to the best local pub. After the party they decided to divide the total bill in equal parts. It is not always possible to divide the total sum (S1 rub.) to N parts without the remainder. So each of the friends pays the integer amount of rubles and the remainder from the division of S1 by N is paid only by some of them by adding one additional ruble. Using this scheme the maximum difference between any of two friends is not more then 1 rub. After the first pub they decided to continue their tour and visited all M pubs in the city. Visiting each pub they followed the same strategy of paying their bills. As the result the maximum difference for any of two friends between total sums they paid should be minimal. Obviously the value will not be more then 1 rub. Your task is to find the number of friends X who paid 1 rub more then the others.
 
 Input
 The first line of the input contains two integer numbers N (1≤ N≤ 100) and M (1≤ M≤ 100). Each of the following M lines contains the total bill in the i-th pub — integer number Si (1≤ Si≤ 104, for all i from 1 to M).
 
 Output
 Write to the output the only number X.

 ************************************************************************/
#include <cstdio>

int main() {
    int n, m;
    scanf ("%d%d", &n, &m);
    int i, tmp, sum = 0;
    for (i = 0; i < m; ++i) {
        scanf ("%d", &tmp);
        sum += tmp;
    }
    printf ("%d\n", sum%n);
    return 0;
}