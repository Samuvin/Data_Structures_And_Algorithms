#include <iostream>
#include <queue>
#include <stack>
using namespace std;
inline void reverse(queue<int> &qu)
{
    if (!qu.empty())
    {
        int data = qu.front();
        qu.pop();
        reverse(qu);
        qu.push(data);
    }
}
inline void reverse_iterative(queue<int> &qu)
{
    stack<int> st;
    while (!qu.empty())
    {
        st.push(qu.front());
        qu.pop();
    }
    while (!st.empty())
    {
        qu.push(st.top());
        st.pop();
    }
}
int main()
{
    int size;
    cin >> size;
    int data;
    queue<int> qu;
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        qu.push(data);
    }
    reverse_iterative(qu);
    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
}
