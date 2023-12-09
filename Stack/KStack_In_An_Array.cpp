#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class kstack
{
private:
    int *arr;
    int *next;
    int *top;
    int kst;

public:
    int freetop;
    kstack(int size, int ktop)
    {
        kst = ktop;
        arr = new int[size];
        next = new int[size];
        top = new int[ktop + 1];
        for (int i = 0; i < size - 1; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        for (int i = 0; i <= ktop; i++)
        {
            top[i] = -1;
        }
        freetop = 0;
    }
    void pushst(int data, int k)
    {
        if (k > kst || k < 0)
        {
            cout << "Stack does not exist\n";
            return;
        }
        if (freetop == -1)
        {
            cout << "OVERFLOW!\n";
            return;
        }
        int i = freetop;
        freetop = next[i];
        next[i] = top[k];
        top[k] = i;
        arr[i] = data;
        cout << "Data " << data << " is inserted in stack " << k << "\n";
    }
    void popst(int k)
    {
        if (k > kst || k < 0)
        {
            cout << "Stack does not exist\n";
            return;
        }
        if (top[k] == -1)
        {
            cout << "UNDERFLOW!\n";
        }
        else
        {
            int element = arr[top[k]];
            int i = top[k];
            top[k] = next[i];
            next[i] = freetop;
            freetop = i;
            cout << "Data " << element << " removed from stack " << k << "\n";
        }
    }
    void topst(int k)
    {
        if (k > kst || k < 0)
        {
            cout << "Stack does not exist\n";
            return;
        }
        if (top[k] == -1)
        {
            cout << "UNDERFLOW!\n";
            return;
        }
        else
        {
            cout << "The Data at the top of the stack " << k << " is : " << arr[top[k]] << "\n";
        }
    }
    void isEmpty(int k)
    {
        if (k > kst || k < 0)
        {
            cout << "Stack does not exist\n";
            return;
        }
        if (top[k] == -1)
        {
            cout << "The stack " << k << " is empty\n";
        }
        else
        {
            cout << "The stack " << k << " is not empty\n";
        }
    }
    void isFull()
    {
        if (freetop == -1)
        {
            cout << "The Array is Empty\n";
        }
        else
        {
            cout << "The Array is not Empty\n";
        }
    }
    ~kstack()
    {
        delete[] top;
        delete[] arr;
        delete[] next;
    }
};
int main()
{
    int totsize;
    int k;
    cin >> totsize >> k;
    kstack kst(totsize, k);
    kst.pushst(1, 1);
    kst.pushst(2, 1);

    kst.pushst(3, 2);
    kst.pushst(4, 2);

    kst.pushst(5, 3);
    kst.pushst(5, 3);

    kst.popst(1);
    kst.topst(1);

    kst.popst(2);
    kst.topst(2);

    kst.popst(3);
    kst.topst(3);

    kst.pushst(6, 5);
}
