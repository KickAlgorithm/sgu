/*************************************************************************
                        302. BHTML 1.0
 
                Time limit per test: 0.25 second(s)
                Memory limit: 65536 kilobytes
                        input: standard
                        output: standard
 
 
 
 The hypertext markup language BHTML 1.0 has only two paired tags. They are UP /UP and DOWN /DOWN. The UP /UP tag capitalizes all letters inside its body (between an open tag and a close one), and DOWN /DOWN makes all inside the body letters lowercase. You are given the text consisting of latin letters and tags. Your task is to write the text right as it will be shown in the Bernet Explorer browser window. Tags in the text are arranged correctly, i.e. they form correct bracket sequence. If a letter lays inside several tags, its case is defined by the most inner tag.
 
 Input
 The input contains the string S with the text. The length of the string is a natural number not exceeding 1000. Tags are always written in uppercase.
 
 Output
 Write to the output text after the processing.

 ************************************************************************/
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main ()
{
    string s1, s2;
    stack<int> mystack;
    while(cin>>s1)
    {
        s2.clear();
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] == '<' && s1[i+1] == 'U'){mystack.push(1); i+=3;}
            else if(s1[i] == '<' && s1[i+1] == 'D'){mystack.push(-1); i+=5;}
            else if(s1[i] == '<' && s1[i+1] == '/'){mystack.pop(); i+=(s1[i+2] == 'U'?4:6);}
            else
            {
                if(mystack.empty())
                s2 += s1[i];
                else if(mystack.top() == 1)
                s2 += toupper(s1[i]);
                else if(mystack.top() == -1)
                s2 += tolower(s1[i]);
            }
        }
        cout<<s2<<endl;
    }
    return 0;
}