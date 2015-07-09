/*************************************************************************
	> File Name: 111.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Thu Jul  9 17:39:35 2015
 ************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int compare(string s1, string s2)
{
    if(s1.length() > s2.length()) return 1;
    else if(s1.length() < s2.length()) return -1;
    for(int i = 0;i < s1.length();i++)
    {
        if(s1[i] > s2[i]) return 1;
        if(s1[i] < s2[i]) return -1;
    }
    return 0;
}

string multiply(string num1, string num2) {
    string s(num1.length()+num2.length(),'0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    for(int i = 0;i < num1.length();i++)
    {
        int flag = 0;
        for(int j = 0;j < num2.length();j++)
        {
            int digit = s[i+j] - '0';
            int num = (num1[i] - '0') * (num2[j] - '0');
            int res = digit + num + flag;
            s[i+j] = (res % 10) + '0';
            flag = res / 10;
        }
        
        int index = i + num2.size();
        while(flag)
        {
            int digit = s[index] - '0';
            int res = digit + flag;
            s[index] = (res % 10) + '0';
            flag = res / 10;
        }
    }
    
    reverse(s.begin(), s.end());
    
    while(s[0] == '0' && s.length() > 1)
        s = s.substr(1);
    return s;
}

string add(string num1, string num2)
{
    int len = max(num1.length(),num2.length());
    string res(len+1,'0');
    int remain(0);
    int i = 0;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    while(i < len || remain != 0)
    {
        int tmp = remain + ( i >= num1.length()? 0 : (num1[i] - '0') ) + ( i >= num2.length()? 0 : (num2[i] - '0') );
        res[i] = ('0' + tmp%10);
        remain = tmp/10;
        i++;
    }
    reverse(res.begin(), res.end());
    while(res[0] == '0' && res.length() > 1)
        res = res.substr(1);
    return res;
}

string sub(string num1, string num2) {
    string s(max(num1.length(),num2.length())+1,'0');
    bool flag(false);
    
    if(num1.length() > num2.length()) flag = false;
    else if(num1.length() < num2.length()) flag = true;
    else {
        if(num1 >= num2) flag = false;
        else flag = true;
    }
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    if(flag) swap(num1, num2);
    
    bool lend(false);
    for(int i = 0;i < num1.length();i++)
    {
        int tmp = (num1[i] - '0') - ( i >= num2.length()? 0 : (num2[i] - '0') );
        if(lend) tmp--;
        if(tmp < 0) {
            tmp += 10;
            lend = true;
        } else lend = false;
        s[i] = ('0'+tmp);
    }
    
    reverse(s.begin(), s.end());
    
    while(s[0] == '0' && s.length() > 1)
        s = s.substr(1);
    if(flag) s.insert(0, "-");
    return s;
}

string shiftRight(string s)
{
    int remain(0);
    for(int i = 0;i < s.length();i++)
    {
        int d = (s[i] - '0');
        s[i] = ('0' + d/2) + remain;
        if(d % 2 == 1) remain = 5;
        else remain = 0;
    }
    while(s[0] == '0' && s.length() > 1)
        s = s.substr(1);
    return s;
}

int main()
{
    string x; cin >> x;
    string mid,ans("1");
    string l("1");
    string r((x.length()+1)/2,'0');
    r = "1" + r;
    string one("1");
    while(true){
        mid = shiftRight(add(l,r));
        int llen = mid.length()+mid.length()-1;
        int mlen = llen + 1;
        if(llen > x.length()){
            r = sub(mid,one);
        }else if(mlen < x.length()){
            ans = mid;
            l = add(mid,one);
        }else{
            int cmp = compare(multiply(mid,mid),x);
            if(cmp > 0)
            {
                r = sub(mid,one);
            } else if(cmp < 0){
                ans = mid;
                l = add(mid,one);
            } else {
                cout << mid;
                return 0;
            }
        }
        if(compare(l,r) > 0)
            break;
    }
    cout << ans;
    return 0;
}