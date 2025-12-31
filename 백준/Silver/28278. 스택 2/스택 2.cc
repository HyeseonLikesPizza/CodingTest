#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>
#include <set>
#include <queue>
#include <string>

using namespace std;

class myStack
{
    public:
    void push_back(int num)
    {
        arr[size++] = num;
    }

    int top()
    {
        return (size != 0) ? arr[size-1] : -1;
    }

    void pop()
    {
        size = max(size-1, 0);
    }

    int empty()
    {
        return (size==0) ? 1 : 0;
    }

    int size=0;

    private:
    int arr[1000000];
};


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    int N;
    myStack* s = new myStack();
    
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int num, insertN;
        cin >> num;
        if (num == 1) cin >> insertN;

        switch(num)
        {
            case 1:
                s->push_back(insertN);
                break;
            case 2:
            cout << s->top() << '\n';
                s->pop();
                break;
            case 3:
                cout << s->size << '\n';
                break;
            case 4:
                cout << s->empty() << '\n';
                break;
            case 5:
                cout << s->top() << '\n';
                break;
        }
    }

    return 0;
}