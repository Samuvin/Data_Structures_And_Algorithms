#include <bits/stdc++.h> 
int Kadane(vector<int>&col)
{
	int res=col[0];
	int curr=col[0];
	for(int i=1;i<col.size();i++)
	{
		curr=max(curr+col[i],col[i]);
		res=max(res,curr);
	}
	return res;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	int res=INT_MIN;
	for(int i=0;i<m;i++)
	{
		vector<int>col(n,0);
		for(int j=i;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				col[k]+=arr[k][j];
			}
			res=max(res,Kadane(col));
		}
	}
	return res;
}
