/*************************************************************************
                    180. Inversions
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 input: standard
 output: standard
 
 
 
 There are N integers (1<=N<=65537) A1, A2,.. AN (0<=Ai<=10^9). You need to find amount of such pairs (i, j) that 1<=i<j<=N and A[i]>A[j].
 
 Input
 The first line of the input contains the number N. The second line contains N numbers A1...AN.
 
 Output
 Write amount of such pairs.
 
 Sample test(s)
 
 Input
 5
 2 3 1 5 4
 
 Output
 3

 ************************************************************************/
#include<iostream>
using namespace std;

const int MAXX = 65540;
int A[MAXX] = {0};

long long merge(int A[], int p, int q, int r) {
    int i, j, k;
    long long inversions = 0;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int L[n1];
    int R[n2];
    
    for (i = 0; i < n1; i++) L[i] = A[p + i];
    for (j = 0; j < n2; j++) R[j] = A[q + j + 1];
    
    for(i = 0, j = 0, k = p; k <= r; k++) {
        if (i == n1) {
            A[k] = R[j++];
        } else if (j == n2) {
            A[k] = L[i++];
        } else if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            inversions += n1 - i;
        }
    }
    
    return inversions;
}

long long merge_sort(int A[], int p, int r) {
    if (p < r) {
        long long inversions = 0;
        int q = (p + r) / 2;
        inversions += merge_sort(A, p, q);
        inversions += merge_sort(A, q + 1, r);
        inversions += merge(A, p, q, r);
        return inversions;
    } else {
        return 0;
    }
}

int main()
{
    int N;cin >> N;
    for(int i = 0;i < N;i++)
    cin >> A[i];
    cout << merge_sort(A, 0, N-1);
    return 0;
}