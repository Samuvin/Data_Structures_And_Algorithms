#include<iostream>
using namespace std;
int main()
{
    string str,pattern;
    cin>>str>>pattern;
    for(int i=0;i<=str.size()-pattern.size();)
    {
        int j;
        for(j=0;j<pattern.size();j++)
        {
            if(pattern[j]!=str[j+i])
            {
                break;
            }
        }
        if(j==pattern.size())
        {
            cout<<i<<" ";
        }
        if(j==0)
            i++;
        else
        {
            i=i+j;
        }
    }
}
