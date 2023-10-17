#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
bool predicate(const vector<int>&books,int amount,int students)
{
    int noOfStudent=1;
    int sum=0;
    for(auto i:books)
    {
        if(sum+i>amount)
        {
            noOfStudent++;
            sum=i;
        }
        else
        {
            sum+=i;
        }
    }
    return noOfStudent<=students;
}
int Allocate_Books(vector<int>&books , int students)
{
    if(students>books.size())
        return -1;
    int lo=*max_element(books.begin(),books.end());
    int hi=accumulate(books.begin(),books.end(),0);
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(predicate(books,mid,students))
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return lo;
}


int main()
{
    int size,students;
    cin>>size>>students;
    vector<int>books(size);
    for(int i=0;i<size;i++)cin>>books[i];
    cout<<Allocate_Books(books,students);
}
