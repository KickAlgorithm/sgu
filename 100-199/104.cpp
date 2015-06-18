/**********************************************************************************************************
                                    104. Little shop of flowers


                                    time limit per test: 0.25 sec.
                                    memory limit per test: 4096 KB


PROBLEM

You want to arrange the window of your flower shop in a most pleasant way. You have F bunches of flowers, each being of a different kind, and at least as many vases ordered in a row. The vases are glued onto the shelf and are numbered consecutively 1 through V, where V is the number of vases, from left to right so that the vase 1 is the leftmost, and the vase V is the rightmost vase. The bunches are moveable and are uniquely identified by integers between 1 and F. These id-numbers have a significance: They determine the required order of appearance of the flower bunches in the row of vases so that the bunch i must be in a vase to the left of the vase containing bunch j whenever i < j. Suppose, for example, you have bunch of azaleas (id-number=1), a bunch of begonias (id-number=2) and a bunch of carnations (id-number=3). Now, all the bunches must be put into the vases keeping their id-numbers in order. The bunch of azaleas must be in a vase to the left of begonias, and the bunch of begonias must be in a vase to the left of carnations. If there are more vases than bunches of flowers then the excess will be left empty. A vase can hold only one bunch of flowers.

Each vase has a distinct characteristic (just like flowers do). Hence, putting a bunch of flowers in a vase results in a certain aesthetic value, expressed by an integer. The aesthetic values are presented in a table as shown below. Leaving a vase empty has an aesthetic value of 0.

        

According to the table, azaleas, for example, would look great in vase 2, but they would look awful in vase 4.

To achieve the most pleasant effect you have to maximize the sum of aesthetic values for the arrangement while keeping the required ordering of the flowers. If more than one arrangement has the maximal sum value, any one of them will be acceptable. You have to produce exactly one arrangement.

ASSUMPTIONS

1 ≤ F ≤ 100 where F is the number of the bunches of flowers. The bunches are numbered 1 through F.
F ≤ V ≤ 100 where V is the number of vases.
-50 £ Aij £ 50 where Aij is the aesthetic value obtained by putting the flower bunch i into the vase j.

Input
The first line contains two numbers: F, V.
The following F lines: Each of these lines contains V integers, so that Aij is given as the j’th number on the (i+1)’st line of the input file.
                
 Output
 The first line will contain the sum of aesthetic values for your arrangement.
 The second line must present the arrangement as a list of F numbers, so that the k’th number on this line identifies the vase in which the bunch k is put.
******************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	vector<vector<int> >table(N+1, vector<int>(M+1, 0));
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
			cin >> table[i][j];
    vector<vector<int> >p = table;


	for(int i = 1;i <= N;i++)
	{
		for(int j = i;j <= M;j++)
		{
            if(i == j) table[i][j] += table[i-1][j-1];
            else table[i][j] = max(table[i-1][j-1]+table[i][j], table[i][j-1]);
		}
	}
    /*
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << table[N][M] << endl;

    int i(N),j(M);
    stack<int> _s;
    while(i > 0)
    {
        if(table[i][j] == table[i-1][j-1] + p[i][j])
        {
            _s.push(j);
            i--;
            j--;
        } else {
            j--;
        }
    }

    while(!_s.empty())
    {
        cout << _s.top() << " ";
        _s.pop();
    }
	
	return 0;
}
