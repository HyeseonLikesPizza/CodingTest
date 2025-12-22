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
    
    int N;

    cin >> N;

    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a>> b;
        cout << a+b << '\n';
    }
    

    return 0;
}