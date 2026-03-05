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

int N;
string str;
int arr[513][513];

int idx = 0;

void parse(int x, int y, int length)
{
    char c = str[idx++];

    if (c == 'W')
    {
        // 전부 흰색
        for (int i=x; i<x+length; i++)
        {
            for (int j=y; j<y+length; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    else if (c == 'B')
    {
        // 전부 검정
        for (int i=x; i<x+length; i++)
        {
            for (int j=y; j<y+length; j++)
            {
                arr[i][j] = 1;
            }
        }
    }
    else
    {
        parse(x, y, length/2); // 왼쪽 위
        parse(x, y + length/2, length/2);
        parse(x + length/2, y, length/2); // 오른쪽 위
        parse(x+length/2, y+length/2, length/2);
    }
}

int main()
{
    //cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    cin >> N;
    cin >> str;

    // 배열 채우기
    parse(0, 0, N);

    // 출력문 출력
    cout << "#define quadtree_width " << N << '\n';
    cout << "#define quadtree_height " << N << '\n';
    cout << "static char quadtree_bits[] = {" << '\n';

    // 배열 요소 헥사 변환 후 출력
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j+=8)
        {
            int val = 0;
            int weight = 1;
            for (int k=0; k<8; k++)
            {
                val += arr[i][j+k] * weight;
                weight *= 2;
            }
            printf("0x%02x", val);
            cout << ",";
        }
        cout << '\n';
    }

    cout << "};";
    
    
    return 0;
}
