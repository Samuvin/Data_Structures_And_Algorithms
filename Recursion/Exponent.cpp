#include<iostream>
using namespace std;

long long exponent(int base,int power)
{
    if(power==0)return 1;
    return base*exponent(base,power-1);
}

long long exp(long long base,long long power)
{
    if(power>0)
    {
        if((power&1)==0){
            return exp(base*base,power/2);
        }
        else
        {
            return exp(base,power-1)*base;
        }
    }
    else{
        return 1;
    }
}
int main()
{
    int num,pow;
    cin>>num>>pow;
    cout<<exponent(num,pow)<<" ";
    cout<<exp(num,pow)<<" ";
}
