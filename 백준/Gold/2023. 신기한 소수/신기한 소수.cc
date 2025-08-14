#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <cmath>

using namespace std;
int N;
int nextDigits[4] = { 1,3,7,9 };

bool IsPrime(int num)
{
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

void DFS(int num, int length)
{
    if (length == N)
    {
        cout << num << '\n';
        return;
    }

    for (int d : nextDigits)
    {
        int nextNum = num * 10 + d;
        if (IsPrime(nextNum))
        {
            DFS(nextNum, length + 1);
        }
    }

}

int main() {

    FILE* fp;

    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    cin >> N;

    int firstDigits[4] = { 2,3,5,7 };

    for (int d : firstDigits)
    {
        DFS(d, 1);
    }



    return 0;
}