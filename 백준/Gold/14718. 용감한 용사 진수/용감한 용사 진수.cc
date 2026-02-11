#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>
#include <tuple>
#include <cmath>
#include <map>

using namespace std;
int N, K;


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> K;

    vector<vector<int>> arr(N, vector<int>(3,0));
    

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<3; j++)
            cin >> arr[i][j];
    }

    int minNum = INT_MAX;

    // 1. a,b 를 선정
    for (int i=0; i<N; i++)
    {
        int a = arr[i][0];
        for (int j=0; j<N; j++)
        {
            int b = arr[j][1];

            vector<int> Selected;
            
            for (int k=0; k<N; k++)
            {
                // 2. a,b가 최대가 되는 c들을 모두 Selected 벡터에 넣음 
                if (arr[k][0]<=a && arr[k][1]<=b)
                {
                    Selected.push_back(arr[k][2]);
                }
            }

            if (Selected.size()<K) continue;

            // 3. Selected 벡터 정렬
            sort(Selected.begin(), Selected.end());

            // 4. Selected 벡터의 K번째 수가 c가 됨
            int c = Selected[K-1];

            // 5. a+b+c 더한 값이 최소가 되는지 확인
            minNum = min(minNum, a+b+c); 
        }
    }

    // 6. 출력
    cout << minNum;


    
    return 0;
}
