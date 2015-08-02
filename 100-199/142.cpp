/*************************************************************************
                        142. Keyword
 
 
                time limit per test: 0.5 sec.
                memory limit per test: 16384 KB
 
 Kevin has invented a new algorithm to crypt and decrypt messages, which he thinks is unbeatable. The algorithm uses a very large key-string, out of which a keyword is found out after applying the algorithm. Then, based on this keyword, the message is easily crypted or decrypted. So, if one would try to decrypt some messages crypted with this algorithm, then knowing the keyword would be enough. Someone has found out how the keyword is computed from the large key-string, but because he is not a very experienced computer programmer, he needs your help. The key-string consists of N characters from the set {'a','b'}. The keyword is the shortest non-empty string made up of the letters 'a' and 'b', which is not contained as a contiguous substring (also called subsequence) inside the key-string. It is possible that more than one such string exists, but the algorithm is designed in such a way that any of these strings can be used as a keyword. Given the key-string, your task is to find one keyword.
 
 Input
 
 The first line contains the integer number N, the number of characters inside the key-string (1 <= N <= 500 000). The next line contains N characters from the set {'a','b'} representing the string.
 
 Output
 
 The first line of output should contain the number of characters of the keyword. The second line should contain the keyword.
 
 Sample Input
 
 11
 aabaaabbbab
 Sample Output
 
 4
 aaaa
 ************************************************************************/
#include <cstdio>
#include <cmath>
char ch;
int g[1 << 19];
bool f[20][1 << 19];
int k, n, len, fid;

int main() {
    scanf ("%d", &n);
    ch = getchar();
    for (int i = 1; i <= n; i++)
        g[i] = (getchar() == 'a');
    
    for (int i = 1; i <= n; i++) {
        k = 0;
        for (int j = 0; j <= 18; j++) {
            if (i + j <= n) {
                k = k << 1 | g[i + j];
                f[j + 1][k] = 1;
            }
            else break;
        }
    }
    
    for (len = 1; len <= 19; len++) {
        for (k = 0; k < (1<<len); k++)
            if (!f[len][k]) {
                fid = 1;
                break;
            }
        if (fid) break;
    }
    
    printf ("%d\n", len);
    for (int i = len - 1; i >= 0; i--)
        printf ("%c", k & (1 << i) ? 'a' : 'b');
}