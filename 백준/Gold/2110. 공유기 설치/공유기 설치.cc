#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int N, C, maxNum = INT_MIN;

    cin >> N >> C;
    vector<int> vec(N);

    for(int i=0; i<N; i++)
    {
        cin >> vec[i];
        maxNum = max(vec[i], maxNum);
    }

    sort(vec.begin(), vec.end());

    int left = 1;
    int right = vec[N-1]-vec[0];
    int answer = 0;


    while (left <= right)
    {
        int mid = (left+right)/2;

        int cnt = 1;
        int lastPos = vec[0];
        for(int i=1; i<N; i++)
        {
            if (vec[i] - lastPos >= mid)
            {
                cnt++;
                lastPos = vec[i];
            } 
        }

        if (cnt >= C)
        {
            answer = mid;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    cout << answer;
    

    return 0;
}