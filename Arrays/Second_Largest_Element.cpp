#include<iostream>
using namespace std;
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int largest=arr[0];
    int Second_Largest=-1;
    for(int i=1;i<size;i++)
    {
        if(largest<arr[i])
        {
            Second_Largest=largest;
            largest=arr[i];
        }
        else if (largest!=arr[i])
        {
            if(Second_Largest==-1 || Second_Largest<arr[i])
            {
                Second_Largest=arr[i];
            }
        }
    }
    cout<<Second_Largest;
}
/*
The Intution is that first we need to consider the first element as the largest element and during every iteration if we found a geater element then we need to make the old largest element as the second largest element and the current
largest element as the new largest element
*/
