#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>

using namespace std;

int BinarySearch(const vector<int>& arr, int num)
{
    int middle = arr.size() / 2;
    int startIdx = 0;
    int endIdx = arr.size()-1;
    int size = endIdx - startIdx + 1;

    while (size>1)
    {
        if (num < arr[middle])
        {
            endIdx = middle-1;
        }
        else if (num > arr[middle])
        {
            startIdx = middle+1;
        }
        else return 1;

        size = endIdx - startIdx + 1;

        if (endIdx == startIdx) middle = endIdx;
        else middle = (endIdx + startIdx)/2;
    }
    if (num == arr[middle]) return 1;
    else return 0;
}


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N, M;

    cin >> N;

    vector<int> arr(N);

    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> M;
    vector<int> vec(M);

    for (int i=0; i<M; i++)
    {
        cin >> vec[i];
        cout << BinarySearch(arr, vec[i]) << '\n';
    }
    

    

    return 0;
}