#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	vector<vector<int> >tables = vector(N, vector<int>(M, 0));
	vector<vector<int> >p = vector(N, vector<int>(M, 0));
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++)
			cin >> tables[i][j];

	for(int i = 0;i < N;i++)
	{
		for(int j = i;j < (M-N+1))
		{
			table	
		}
	}
	
	return 0;
}
