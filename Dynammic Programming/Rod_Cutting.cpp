class Solution{
  public:
    vector<int>dp;
    int memo(int price[] ,int i,int n)
    {
        if(i==0)
            return 0;
        
        int &ans=dp[i];
        if(ans!=-1)
            return ans;
        
        ans=0;
        
        for(int ind=0;ind<n;ind++)
        {
            if(i-ind-1<0)
                break;
            int tot=price[ind]+memo(price,i-ind-1,n);
            ans=max(ans,tot);
        }
        return ans;
    }
    int cutRod(int price[], int n) {
        dp=vector<int>(n+1,0);
        
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int curr=0;
            for(int j=1;j<=i;j++)
            {
                curr=max(curr,price[j-1]+dp[i-j]);
            }
            dp[i]=curr;
        }
        
        return dp[n];
    }
};
