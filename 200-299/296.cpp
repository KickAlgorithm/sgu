/*************************************************************************
                296. Sasha vs. Kate
 
        Time limit per test: 0.5 second(s)
        Memory limit: 65536 kilobytes
                input: standard
                output: standard
 
 
 
 During the regular Mars's World Finals Subregional Programming Contest a boy Sasha lost N "Mars" bars of chocolate to a girl Kate. But for two years already Sasha does not hurry to pay his debt. And now Sasha and Kate decided that Sasha will give Kate P chocolate bars, where number P can be obtained from the number N by removing exactly K decimal digits. Sasha generously let Kate to choose digits to be removed. Your task is to find out how many bars Sasha will give Kate. Of course Kate will choose K digits from the number N in such a way that the resulting number P would be maximal.
 
 Input
 The first line of the input file contains two integer numbers N and K (1≤ N≤ 101000; 0≤ K≤ 999). Number K is strictly less than the number of digits in N. N will not have any leading zeros.
 
 Output
 Output the unknown P.
 ************************************************************************/
#include <cstdio>
#include <cstring>

int main()
{
    char s[1100];
    int k;
    scanf("%s",s);
    scanf("%d",&k);
    int len=strlen(s);
    while(k)
    {
        int flag=1;
        for(int i=1;i<len;i++)
            if(s[i-1]<s[i])
            {
                flag=0;
                strcpy(s+i-1,s+i);
                len--;
                break;
            }
        if(flag)
        {
            s[len-1]='\0';
            len--;
        }
        k--;
    }
    printf("%s\n",s);
}