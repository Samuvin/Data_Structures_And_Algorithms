#include<iostream>
using namespace std;

int sum(long long n)
{
    if(n==0)
        return 0;
    else{
        return sum(n/10)+n%10;
    }
}
int main()
{
    long long n;
    cin>>n;
    cout<<sum(n);
}
