/*************************************************************************
                        316. Code Tanks
 
                Time limit per test: 0.25 second(s)
                Memory limit: 65536 kilobytes
                        input: standard
                        output: standard
 
 
 
 Hopefully yesterday you participated in the fascinating Code Game Challenge event. And now you have a unique chance to play on the side of the organizers team. You need to solve one of the many challenging tasks organizers have met during the Code Game Challenge preparation process.
 
 The problem is the following. You are given the log of one match with N tanks participating. The log is a sequence of successful bullet shots, i.e. hits. Shots are listed in the log in the order of the corresponding bullet hit the target tank as this happened in the match. You need to calculate the number of hit points and the score of each tank at the end of the match.
 
 Here are the Code Game Challenge rules essential for this problem:
 
 Each tank has 100 hit points and 0 score points at the beginning of the match.
 
 Each shot always reduces the hit points of the target tank by 8, and if the number of hit points of the target before the shot was greater than zero, the shooting tank receives 3 score points.
 
 Only "active" tanks (with a positive number of hit points) can shoot, so you can expect to find only shots fired by the "active" tanks in the log.
 
 At the end of the match each tanks with positive hit points additionally receive the number of score points equal to the half of its hit points.
 
 
 
 Input
 The first line of the input contains two integer numbers N and M (2 ≤ N ≤ 6; 1 ≤ M ≤ 4000), where N is the number of tanks participating in the match and M is the number of shots fired. The following M lines contain the descriptions of the shots. Each description consists of two different integer numbers from 1 to N. The first one is the number of the tank which fired the shot and the second one is the number of the tank which was hit by the shot.
 
 Output
 Write N lines to the output, one line for each tank, in the order of the tank numbers. Write two integer numbers to each line — the number of hit points and the number of score points of the corresponding tank at the end of the match.
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    int hit;
    int score;
}tank[10];

int N, M;

int main() {
    while(scanf("%d %d", &N, &M) != EOF) {
        for(int i = 1; i <= N; i++) {
            tank[i].hit = 100;
            tank[i].score = 0;
        }
        
        for(int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if(tank[a].hit > 0) {
                if(tank[b].hit > 0) tank[a].score += 3;
                tank[b].hit -= 8;
            }
        }
        for(int i = 1; i <= N; i++) {
            if(tank[i].hit > 0)
            tank[i].score += (tank[i].hit / 2);
        }
        
        for(int i = 1; i <= N; i++) {
            printf("%d %d\n", tank[i].hit, tank[i].score);
        }
    }
    return 0;
}
