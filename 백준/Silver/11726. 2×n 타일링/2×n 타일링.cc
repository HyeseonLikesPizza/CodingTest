#include <iostream>
#include <set>
#include <unordered_set>
#include <fstream>
#include <queue>

using namespace std;

int arr[1000];

int D(int n)
{
    if (n==1)
        return 1;
    else if (n==2)
        return 2;

    for (int i=3; i<=n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;       
    }

    return arr[n];
}


int main()
{
    int n, result;

    cin >> n;

    arr[1] = 1;
    arr[2] = 2;

    result = D(n);

    cout << result;
    
    
    return 0;
}