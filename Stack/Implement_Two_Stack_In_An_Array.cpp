#include <iostream>
#include <vector>
using namespace std;
class STACK
{
private:
    int *arr;

public:
    int size;
    int top1;
    int top2;
    STACK(int cap)
    {
        arr = new int[cap];
        size = cap;
        top1 = -1;
        top2 = cap;
    }
    void push_st1(int data)
    {
        if (top1 + 1 != top2 && top1 + 1 < size)
        {
            arr[++top1] = data;
            cout << "Data Inserted\n";
        }
        else
        {
            cout << "OVERFLOW\n";
        }
    }
    void push_st2(int data)
    {
        if (top2 - 1 != top1 && top2 - 1 >= 0)
        {
            arr[--top2] = data;
            cout << "Data Inserted\n";
        }
        else
        {
            cout << "OVERFLOW\n";
        }
    }
    int pop_st1()
    {
        if (top1 != -1)
        {
            return arr[top1--];
        }
        else
        {
            cout << "UNDERFLOW\n";
            return -1e9;
        }
    }
    int pop_st2()
    {
        if (top2 == size)
        {
            return arr[top2++];
        }
        else
        {
            cout << "UNDERFLOW\n";
            return -1e9;
        }
    }
    int top_st1()
    {
        if (top1 == -1)
            return 1e9;
        else
            return arr[top1];
    }
    int top_st2()
    {
        if (top2 == size)
            return 1e9;
        else
            return arr[top2];
    }
    int size_st1()
    {
        return top1 + 1;
    }
    int size_st2()
    {
        return size - top2;
    }
};

int main()
{
    int tot_size;
    cin >> tot_size;
    STACK stac(tot_size);
    stac.push_st1(1);
    stac.push_st1(2);
    stac.push_st1(3);
    stac.push_st2(4);
    cout << stac.pop_st1() << "\n";
    cout << stac.pop_st1() << "\n";
    cout << stac.pop_st1() << "\n";
    stac.push_st2(5);
    stac.push_st2(6);
    cout << stac.size_st1() << "\n";
    cout << stac.size_st2() << "\n";
}
