#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    priority_queue<int> q;
    int N;

    cin >> N;

    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (q.empty())
            {
                cout << 0 <<'\n';
                continue;
            }
            cout << q.top() << '\n';
            q.pop();
        }
        else
        {
            q.push(num);
        }
    }

    return 0;
}