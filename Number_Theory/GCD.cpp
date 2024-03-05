#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int Euclid_Gcd(int a,int b)
    {
        if(b==0)
            return a;
        return Euclid_Gcd(b,a%b);
    }
    int Euclide_Algo_Better(int a,int b)
    {
        if(a==0)
            return b;
        if(b==0)
            return a;
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        return a;
    }
    int GcdBrute(int a,int b)
    {
        if(a==0)
            return b;
        if(b==0)
            return a;
        int res=min(a,b);
        while(res>1)
        {
            if(a%res==0 && b%res==0)
                return res;
            res--;
        }
        return res;
    }
    int gcd(int a, int b)
    {
        return Euclid_Gcd(a,b);
        return Euclide_Algo_Better(a,b);
        return GcdBrute(a,b);
    }
};
