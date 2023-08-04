/*
An element is consider to be leader if its greater than all the elements to its right side and the rightmost element is always leader
*/
#include<iostream>
#include<vector>
using namespace std;

void Brute_Force(int arr[],int size)
{
    bool flag=true;
    for(int i=0;i<size;i++)
    {
        flag=true;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]<=arr[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<arr[i]<<" ";
        }
    }
}

void Optimised(int arr[],int size)
{
    vector<int> result;
    result.push_back(arr[size-1]);
    int current_Max=arr[size-1];
    for(int i=size-2;i>=0;i--)
    {
        if(arr[i]>current_Max)
        {
            current_Max=arr[i];
            result.push_back(arr[i]);
        }
    }
    for(int i=result.size()-1;i>=0;i--)
    {
        cout<<result[i]<<" ";
    }
}


int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)cin>>arr[i];
    //Brute_Force(arr,size);
    Optimised(arr,size);

}

/*
The Naive Method is to traverse the array one by one and through each Iteration Make a inner loop and traverse from the next element to the last of the array
thus if you found no element greater than tha current element in the inner loop then the current element is consider to be one of the leader
*/

/*
The Optimised solution in Array is To traverse from the last element always the last element will be leader because there will be no right element after it
and start a loop from the last second element and make the last element as the current greater element
through each iteration check if the current element is greater than the previous element if yes make the current element as the greater element and print it

The Drawback in this solution is it will print the array in reverse order so store it in a vector and print the vector in reverse order or reverse the vector 
*/
