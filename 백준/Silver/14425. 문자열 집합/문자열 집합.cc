#include <iostream>
#include <set>
#include <unordered_set>
#include <fstream>

using namespace std;

int main()
{
    int N, M, cnt=0;
    unordered_set<string> s;
    string temp;
    
    cin >> N >> M;

    for (int i=0; i<N; i++)
    {
        cin >> temp;
        s.insert(temp);
    }

    for (int i=0; i<M; i++)
    {
        cin >> temp;
        if (s.find(temp)!=s.end()) cnt++;
    }

    cout << cnt;
    
    return 0;
}