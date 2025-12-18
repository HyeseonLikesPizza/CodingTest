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
    
    int N, cnt=0, result, middle, min=INT_MAX, minIdx;

    cin >> N;

    vector<int> vec(N);

    for(int i=0; i<N; i++)
    {
        cin >> vec[i];
        cnt += vec[i];
    }

    sort(vec.begin(), vec.end());

    middle = N/2;

    // N이 짝수라면
    if (N%2==0)
    {
        middle = N/2-1;
    }
    
    
    cout << vec[middle];

    return 0;
}