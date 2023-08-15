#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Three_sum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if(i!=0 && arr[i]==arr[i-1])continue;
        int lo = i + 1;
        int hi = size - 1;
        while (lo < hi)
        {
            long long sum = arr[i] + arr[hi] + arr[lo];
            if (sum > 0)
            {
                hi--;
            }
            else if (sum < 0)
            {
                lo++;
            }
            else
            {
                res.push_back({arr[i], arr[lo], arr[hi]});
                lo++;
                hi--;
                while (lo < hi && arr[lo] == arr[lo - 1])
                    lo++;
                while (lo < hi && arr[hi] == arr[hi + 1])
                    hi--;
            }
        }
    }
    return res;
}


vector<vector<int>> Three_sum_method_2(vector<int> arr)
{
    int size=arr.size();
    set<vector<int>>st;
    for(int i=0;i<size;i++)
    {
        set<int>hashset;
        for(int j=i+1;j<size;j++)
        {
            int third=-(arr[i]+arr[j]);
            if(hashset.find(third)!=hashset.end())
            {
                vector<int>temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


int main()
{
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> res=Three_sum_method_2(v);
    for(auto it:res)
    {
        for(auto re : it)
        {
            cout<<re<<" ";
        }
        cout<<'\n';
    }
}
/*
The Question is you have given a array of elements you have to find three numbers whose sum is equal to 0

The intution is first sort the array
For example:
Input : -1 0 1 2 -1 -4
Output : -1 -1 2      -1 0 1


The intuition is to first sort the array after sorting our array looks like -4 -1 -1 0 1 2
we have to take three pointers one slow moving pointer and 2 moving pointers
as slow moving pointer moves from start to end and first moving pointer pointes the next element of the slow moving pointer
and the last pointer holds the position at the last
At first 
-4 -1 2  = -3 
the answer is less than our expected answer so we have to move the first pointer forward
-4 -1 2 = -3
since same move forward
-4 0 2 = -2 
since same move forward
-4 1 2 = -1 
since same move forward if we move forward the two moving pointers are in the same place so we need to stop 
the current flow and start moving the slow pointer towards
hence
-1 -1 2 =0
hence the sum is 0 so we have to store the current triplet in a vector and hence continue the flow
if sum is greater move the last moving pointer 
is sum is lesser move the first moving pointer
if first moving pointer is greater than or equal to the second moving pointer stop the flow and start moving the slow pointer


*/

/*
The method two is we are using a set data structure to store our unique pairs

We are using two loops and traversing through the array while traversing we are 
storing the visited elements between i and j into a set
we need a+b+c=0 if we have two values we need the third one 
then the we consider the equation as
a+b+c=0   a=-b-c  a=-(b+c) we have two values we need the third one
but the third value should lie between the two values
so is we traverse through the array as
-1 0 1 2 -1 -4
i   j   hashset
-1  0
-1  1     0
-1  2     0 1
-1  -1    0 1 2 
since we have two values -1 -1 we need the third value
c=-(-1-1)
c=2
we have to find is 2 exists between these elements if yes we found a triplet
and we sort it and push it into the set vector we use set vector so that it 
do contains only unique pairs
*/
