#include<iostream>
using namespace std;
void reverse(int arr[],int lo,int hi)
{
    while(lo<hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}
int main()
{
    int size;
    int D;
    cin>>size>>D;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    if(D>=size)
    {
        D%=size;
    }
    if(D!=0)
    {
        reverse(arr,0,D-1);
        reverse(arr,D,size-1);
        reverse(arr,0,size-1);
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
/*
The Intution is first if we have a array that is 1 2 3 4 5 and we need to rotate that array in 2 times then first we have to rotate d elements as 2 1 3 4 5
then we have to rotate element from d to size of the array that is 2 1 5 4 3 then we have to reverse the whole array as 3 4 5 1 2 

To avoid unnecessary rotation there is a if else condition to handle it if D is equal to the size or the Rotation is greater than the size as if D is 7 then it will be 2 rotation 

Time Complexity: O(n)
*/
