#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int N, M;
vector<int> picked;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N;
    string str;

    cin >> N;
    cin.ignore();

    for(int i=0; i<N; i++)
    {
        getline(cin, str);
        if (str.size()>=6 && str.size()<=9)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
        str.clear();
    }

    return 0;
}