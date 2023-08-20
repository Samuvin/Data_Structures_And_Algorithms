#include<iostream>
using namespace std;
void binary(int n)
{
    if(n>=1)
    {
        binary(n/2);
        cout<<(n%2);
    }
}

void binary_method_2(int num,int i)
{
    if(i==32)return;
    else{
        int digit=(num>>i)&1;
        binary_method_2(num,i+1);
        cout<<digit<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    binary_method_2(n,0);   
}
/*
  To print in a number in binary 
  Method _ 1
  For example we need to divide the number by 2 and we need to take modulo by 2 and print it in reverse order
  as 
   6
   3
   2
   1
  as we divided by recursion in tha ascending phase and we need to take modulo by 2 in descending phase as 
  0
  1
  1
  and we print from bottom as 110

  Method - 2
  We are using bit wise and we are checking every 32 bit by using right shift
  as if we have 6
  then its bits will we 110 in first we are right shifting by 1 and & with 1 
  as 
  1 shift (0 & 1)  we get 0
  2 shift (1 & 1) we get 1
  3 shift (1 & 1) we get 1
  as we get the bitwise of the number 6 as we do it for every 32 bit
/*
