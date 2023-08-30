#include<iostream>
using namespace std;
int brute_force(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int count=1;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            
            {
                count++;
            }
        }
        if(count>size/2)
        {
            return arr[i];
        }
    }
    return -1;
}

int Moore(int arr[],int size)
{
    int res=1;
    for(int i=1;i<size;i++)
    {
        if(arr[res]==arr[i])
        {
            res++;
        }
        else
        {
            res--;
        }
        if(res==0)
        {
            res=1;
        }
    }
    return res;
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<brute_force(arr,size);

}
/*
Given an array we need to find the majority element 
a element is considered to be majority when it occured
more than half the size of the array;

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is greater than the half of the size of the array size.
*/
/*
The Algorithm States That we need to choose a candidate and we need to vote him that is we consider our first element
as the largest element and we need to traverse through the array from 1 and we need to make a check is the elements are
same then we need to increment the vote or else we need to decrement the vote and we need to reset the count to 1 when we 
out current voting goes 0
*/
