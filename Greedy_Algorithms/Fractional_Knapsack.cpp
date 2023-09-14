#include<iostream>
#include<algorithm>
using namespace std;

typedef struct _item
{
    int volume;
    int weight;
}Item;

bool mycomp(Item a,Item b)
{
    double we1=(double)a.volume/(double)a.weight;
    double we2=(double)b.volume/(double)b.weight;
    return we1>we2;
}

int main()
{
    int n,w;
    cin >> n >> w;
    Item weight[n];
    for(int i=0;i<n;i++)
    {
        cin >> weight[i].volume;
    }
    for(int i=0;i<n;i++)
    {
        cin >> weight[i].weight;
    }
    sort(weight,weight+n,mycomp);

    int current_weight=0;
    double final_weight=0.0;

    for(int i=0;i<n;i++)
    {
        if(current_weight+weight[i].weight<=w)
        {
            current_weight+=weight[i].weight;
            final_weight+=weight[i].volume;
        }
        else
        {
            int rem=w-current_weight;
            final_weight+=(weight[i].volume/(double)weight[i].weight)*(double)rem;
            break;
        }
    }
    cout<<final_weight<<"\n";
}
