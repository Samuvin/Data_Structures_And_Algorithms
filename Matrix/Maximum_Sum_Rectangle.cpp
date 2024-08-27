#include <bits/stdc++.h> 
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	int res=-1e9;
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			for(int k=i;k<arr.size();k++)
			{
				for(int l=j;l<arr[0].size();l++)
				{
					int sum=0;
					for(int x=i;x<=k;x++)
					{
						for(int y=j;y<=l;y++)
						{
							sum+=arr[x][y];
						}
					}
					res=max(res,sum);
				}
			}
		}
	}
	return res;
}
