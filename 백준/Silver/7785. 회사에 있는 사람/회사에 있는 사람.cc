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


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    set<string> s;
    

    for(int i=0; i<N; i++)
    {
        string first, second;
        //getline(cin, str);
        cin >> first >> second;

        if (second == "enter")
            s.emplace(first);
        else{
            if(s.find(first)!=s.end())
            {
                s.erase(first);
            }
        }
    }

    for (auto it = s.rbegin(); it !=s.rend(); ++it)
    {
        cout << *it << '\n';
    }


    return 0;
}