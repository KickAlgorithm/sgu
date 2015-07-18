/*************************************************************************
                        172. eXam
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
                        input: standard
                        output: standard
 
 
 
 In Russia school pupils must do some exams before leaving school. Among others, they must do two "selective" exams. This means that school provides a list of available subjects; each pupil selects two different subjects from this list and is going to do this exams. According to rules, pupil isn't allowed to do both exams at the same day, so the school must schedule the exams, i.e. provide some days when pupils will be able to do exams.
 
 One school does not want to warn teachers too much. They want to schedule all the exams into two days in such way that exams on some subjects are on the first day, and exams on all other (and only on them) are on second. You are to write a program, which will determine, if it is possible to schedule exams in this way so that all pupils will be able to do all their selected exams.
 
 Input
 On the first line of input there are two integers N and M (1<=N<=200, 1<=M<=30000) - the number of available subjects and the number of pupils. Then M lines follows; on i-th of them there are two integers - the numbers of exams, which were selected by i-th pupil. Exams are numerated from 1 to N.
 
 Output
 If the solution exists, write on the first line of output only one word "yes". On the second line write the total number of exams, which must be held on first day, and on the third line - the numbers of subjects of this exams. If there exist several solutions, output any. If no solution exists, write to output only one word "no".
 
 Sample test(s)
 
 Input
 4 4
 1 2
 3 4
 2 4
 1 3
 
 Output
 yes 
 2 
 1 4
 ************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M;

struct Node{
    int color;
    vector<int> edges;
    Node():color(0){}
};

struct Edge{
    int v1,v2;
    bool visited;
    Edge(){};
    Edge(int _v1, int _v2, bool _vis){
        v1 = _v1;v2 = _v2;visited = _vis;
    }
};

struct Edge Edges[30010];
struct Node nodes[300];

bool BFS(int start)
{
    queue<int> myqueue;
    myqueue.push(start);
    
    while(!myqueue.empty())
    {
        int node1 = myqueue.front();
        myqueue.pop();
        vector<int> edges = nodes[node1].edges;
        for(int i = 0;i < edges.size();i++)
        {
            int e = edges[i];
            if(Edges[e].visited) continue;
            Edges[e].visited = true;
            int node2 = node1 ^ Edges[e].v1 ^ Edges[e].v2;
            int c1 = nodes[node1].color;
            int c2 = nodes[node2].color;
            if(c2 > 0 && c1 == c2) return false;
            if(c2 == 0)
            {
                nodes[node2].color = 3 - c1;
                myqueue.push(node2);
            }

        }
    }
    return true;
}



int main() {
    int front,back;
    cin >> N >> M;
    
    int index = 0;
    while(index < M)
    {
        cin >> front >> back;
        Edges[index] = Edge(front,back,false);
        nodes[front].edges.push_back(index);
        nodes[back].edges.push_back(index);
        index++;
    }
    
    for(int i = 1;i <= N;i++)
    {
        if(nodes[i].color == 0)
        {
            nodes[i].color = 1;
            bool fff = BFS(i);
            
            if(!fff) {
                cout << "no";
                return 0;
            }
        }
    }

    
    vector<int>res;
    for(int i = 1;i <= N;i++)
        if(nodes[i].color != 2)
            res.push_back(i);
    
    cout << "yes" << endl << res.size() << endl;
    for(int i = 0;i < res.size();i++)
        cout << res[i] << " ";


    return 0;
}
