#include<iostream>
using namespace std;
long long gcd_method_1(int a,int b)
{
    if(a==0)return b;
    if(b==0)return a;
    else if(a>b)return gcd_method_1(a-b,b);
    else
    {
        return gcd_method_1(a,b-a);
    }
}

long long Euclid_gcd(int a,int b)
{
    if(a==0)return b;
    if(b==0)return a;
    else return Euclid_gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<Euclid_gcd(a,b);
}
