#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
bool mycomp(struct meeting a,struct meeting b)
{
    if(a.end < b.end)return true;
    else if(a.end>b.end)return false;
    else if(a.pos < b.pos)return true;
    return false;
}
int main()
{
    int meetings;
    cin>>meetings;
    struct meeting meet[meetings];
    for(int i=0;i<meetings;i++)
    {
        cin>>meet[i].start;
        meet[i].pos = i+1;
    }
    for(int i=0;i<meetings;i++)
    {
        cin>>meet[i].end;
    }
    sort(meet,meet+meetings,mycomp);
    int limit=meet[0].end;
    vector<int> ans;
    ans.push_back(meet[0].pos);
    for(int i=1;i<=meetings;i++)
    {
        if(meet[i].start>limit)
        {
            limit=meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
