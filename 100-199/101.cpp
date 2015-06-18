/****************************************************************************************
					101. Domino
				time limit per test: 0.25 sec. 
				memory limit per test: 4096 KB
Dominoes – game played with small, rectangular blocks of wood or other material, each identified by a number of dots, or pips, on its face. The blocks usually are called bones, dominoes, or pieces and sometimes men, stones, or even cards.
The face of each piece is divided, by a line or ridge, into two squares, each of which is marked as would be a pair of dice...
The principle in nearly all modern dominoes games is to match one end of a piece to another that is identically or reciprocally numbered.
ENCYCLOPÆDIA BRITANNICA
Given a set of domino pieces where each side is marked with two digits from 0 to 6. Your task is to arrange pieces in a line such way, that they touch through equal marked sides. It is possible to rotate pieces changing left and right side.
Input
The first line of the input contains a single integer N (1 ≤ N ≤ 100) representing the total number of pieces in the domino set. The following N lines describe pieces. Each piece is represented on a separate line in a form of two digits from 0 to 6 separated by a space.
Output
Write “No solution” if it is impossible to arrange them described way. If it is possible, write any of way. Pieces must be written in left-to-right order. Every of N lines must contains number of current domino piece and sign “+” or “-“ (first means that you not rotate that piece, and second if you rotate it).
Sample Input
5
1 2
2 4
2 4
6 4
2 1
Sample Output
2 -
5 +
1 +
3 +
4 -
*******************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

int N = 0;
int occ[7] = {0};
int START = 0;

struct Edge{
	int v1,v2;
	bool visited;
	Edge(){};
	Edge(int _v1, int _v2, bool _vis){
		v1 = _v1;v2 = _v2;visited = _vis;
	}
};
struct Edge Edges[110];
map< int , vector<int> >maps;

/*
 * 返回一个节点的所有边
 */
vector<int> getEdge(int n){
	vector<int> set;
	for(int i = 0;i < N;i++){
		if(n == Edges[i].v1 || n == Edges[i].v2){
			set.push_back(i);
		}
	}
	return set;
}

void res(int start,vector<int>& s){
		for(int i = s.size()-1;i >= 0;i--){
			int front = Edges[s[i]].v1;
			int back = Edges[s[i]].v2;
			if(start == front){
				cout << s[i]+1 << " +" << endl;
				start = back;
			} else {
				cout << s[i]+1 << " -" << endl;
				start = front;
			}
		}
}

void through(int start, vector<int>& s){
	vector<int>e = maps[start];
	for(int i = 0;i < e.size();i++){
		if(Edges[e[i]].visited)
			continue;
		else{
			Edges[e[i]].visited = true;
			if(start == Edges[e[i]].v1){
				through(Edges[e[i]].v2, s);
				s.push_back(e[i]);
			} else {
				through(Edges[e[i]].v1, s);
				s.push_back(e[i]);
			}
		}
	}
	return;
}


int main()
{
	int front,back;
	cin >> N;

	int index = 0;
	while(cin >> front && cin >> back)
	{
		Edges[index] = Edge(front,back,false);
		index++;
		occ[front]++;
		occ[back]++;
	}

	int odd_pot = 0, start = Edges[0].v1;
	for(int i = 0;i < 7;i++){
		if(occ[i] % 2 == 1){
			odd_pot++;
			start = i;
		}
		maps[i] = getEdge(i);
	}
	START = start;
	if(odd_pot != 0 && odd_pot != 2){
		cout << "No solution";
		return 0;
	}

	vector<int>results;
	through(start,results);
	//如果不是联通图
	if(results.size() < N)cout << "No solution";
	else res(START,results);

	return 0;
}
