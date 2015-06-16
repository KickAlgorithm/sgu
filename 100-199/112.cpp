/****************************************************************************
				112. ab-ba


time limit per test: 0.25 sec. 
memory limit per test: 4096 KB

You are given natural numbers a and b. Find ab-ba.

Input

Input contains numbers a and b (1≤a,b≤100).

Output

Write answer to output.

Sample Input

 2 3
Sample Output

 -1
*****************************************************************************/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;

string d2s(int d)
{
	ostringstream ss;
	ss << d;
	return ss.str();
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

string strpow(int x, int n)
{
	string res("1");
	string base = d2s(x);
	while(n > 0)
	{
		if(n % 2 == 1)
			res = multiply(res, base);
		base = multiply(base, base);
		n /= 2;
	}
	return res;
}

int main()
{
	int a,b; cin >> a >> b;
	cout << sub(strpow(a,b), strpow(b,a)) << endl;
	return 0;
}
