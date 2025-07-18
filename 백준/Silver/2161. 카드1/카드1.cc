#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    vector<int> v;
    int N;

    cin >> N;

    for (int i=1; i<=N; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        //위에 있는 카드를 버린다
        v.push_back(q.front());
        q.pop();
        
        // 제일 위에 있는 카드를 맨 아래로 옮긴다
        q.push(q.front());
        q.pop();
    }
    
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << q.front();

    return 0;
}