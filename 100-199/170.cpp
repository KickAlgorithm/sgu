/*************************************************************************
	> File Name: 170.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Fri Jul 17 10:13:09 2015
 ************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;


int main() {
    
    int a[5000] = {0};
    int b[5000] = {0};
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.length() != s2.length())
    {
        cout << -1;
        return 0;
    }
    
    int temp1(0),temp2(0);
    for(int i = 0;i < s1.length();i++)
    {
        if(s1[i] == '-')
            a[temp1++] = i;
        if(s2[i] == '-')
            b[temp2++] = i;
    }
    
    if(temp1 != temp2)
    {
        cout << -1;
        return 0;
    }
    
    int res(0);
    for(int i = 0;i < temp1;i++)
        res += abs(a[i]-b[i]);
    
    cout << res;
    return 0;
}