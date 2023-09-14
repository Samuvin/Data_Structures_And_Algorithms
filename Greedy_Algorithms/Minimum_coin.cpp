#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int coin;
    cin >> coin;
    int cash[]={1,2,5,10,20,50,100,500,1000};
    int cash_cnt=9;
    vector<int> ans;
    for(int i=cash_cnt-1;i>=0;i--)
    {
        while(coin>=cash[i])
        {
            coin-=cash[i];
            ans.push_back(cash[i]);
        }
        if(coin==0)break;
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
