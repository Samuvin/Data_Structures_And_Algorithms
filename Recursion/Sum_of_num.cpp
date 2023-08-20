#include<iostream>
using namespace std;


long long Decomposition_1(long long num)
{
    if(num==1)                                     //Base case
    {
        return 1;
    }
    else                
    {
        return Decomposition_1(num-1)+num;        //Recursive case
    }
}


long long Decomposition_2(long long num)
{
    if(num==1)
    {
        return 1;
    }
    else if((num&1)==0)
    {
        return 2*Decomposition_2(num/2)+(num*num/4);
    }
    else
    {
        return 2*Decomposition_2((num-1)/2)+((num+1)*(num+1)/4);
    }
}


long long Decomposition_3(long long num)
{
    if(num==1)
        return 1;
    if(num==2)
        return 3;
    else if((num&1)==0)
    {
        return 3*Decomposition_3(num/2) + Decomposition_3(num/2-1);
    }
    else
    {
        return 3*Decomposition_3((num-1)/2) + Decomposition_3((num+1)/2);
    }
}

int main()
{
    int num;
    cin>>num;
    cout<<"Answer For Decomposition 1 : "<<Decomposition_1(num)<<"\n";
    cout<<"Answer For Decomposition 2 : "<<Decomposition_2(num)<<"\n";
    cout<<"Answer For Decomposition 2 : "<<Decomposition_3(num)<<"\n";


}
