#include <iostream>
using namespace std;

void count_Frequency(int arr[], int size)
{
    int freq = 1;
    int i = 1;
    while (i < size)
    {
        while (i < size && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }
        cout << arr[i-1] << " : " << freq<<"\n";
        i++;
        freq = 1;
    }
    if (size == 1 || arr[size - 1] != arr[size - 2])
    {
        cout << arr[size - 1] << " : " << 1;
    }
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    count_Frequency(arr,size);
}
/*
The Intution is we have to traverse from the first element and in each iteration we need to check if the current element is equal to the previous element or not 
if they are equal we will increment the frequency variable and when the condition is violated then it means that we found a new element then we need to come out of the 
loop and print the element and its frequency and make the frequency as 1 which is the count of the next variable which we are at now the corner cases are if the array size is one
or we have the last element as unique then we out while loop will wont run because we are 1 position ahead so it will be out of out array size to handle that we kept a
if condition at the end of the code
*/
