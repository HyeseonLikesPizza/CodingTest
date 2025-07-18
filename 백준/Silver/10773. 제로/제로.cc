#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int K;
    cin >> K;
    long int cnt=0;
    int temp;
    stack<int> s;
    
    for (int i=0; i<K; i++)
    {
        cin >> temp;
        if (temp==0)
        {
            cnt -= s.top();
            s.pop();
        }
        else
        {
            s.push(temp);
            cnt += temp;
        }
    }

    cout << cnt;

    return 0;
}