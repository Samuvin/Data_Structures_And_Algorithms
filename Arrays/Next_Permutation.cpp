#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Next_Permutation(vector<int>&vec)
{
    int index=-1;
    for(int i=vec.size()-2;i>=0;i--)
    {
        if(vec[i]<vec[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(vec.begin(),vec.end());
    }
    else
    {
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(vec[i]>vec[index])
            {
                swap(vec[i],vec[index]);
                break;
            }
        }
        reverse(vec.begin()+index+1,vec.end());
    }
}
int main()
{
    int size;
    cin>>size;
    vector<int> vec(size);
    for(int i=0;i<size;i++)cin>>vec[i];
    Next_Permutation(vec);
    for(auto value : vec)
    {
        cout<<value<<" ";
    }
}
/*
We need to find the next permutation for the given array
Permutations will be in ascending order that is
for 3 1 2

The Permutations are

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2  //
3 2 1

The Next permutation is 3 2 1

If we have the array as 3 2 1 the next permutations will be 1 2 3

The Intution is we have the array 2 1 5 4 3 0 0

We have to have the array to next greater array

So We need to Do Three Steps
First We need to find the break point
Which is 
in the array 2 1 5 4 3 0 0
We traverse from last we need to find where the element is decreasing
as 
0 < 0
3 < 0
4 < 0
5 < 4
1 > 5 We found the break point

If we need to change the array to next greater we need to 
place the next greater element of the breakpoint to it

There are three greater elements 3 4 5
from here we need to choose the next greater element that is 3

since we have 2 3 then we need to place the elements in ascending order
we can neither sort or we can reverse it

that is if we replace the element

the out array looks like 2 3 5 4 1 0 0
                             ----------
They are in descending order so we can reverse it
if we reverse it we get 2 3 0 0 1 4 5
which is out next permutation
*/
