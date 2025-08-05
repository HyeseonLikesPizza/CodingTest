#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <fstream>
#include <queue>
#include <string>

using namespace std;



string Add(string s1, string s2)
{
    string result = "";
    int carry = 0;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int length = max(s1.size(), s2.size());

    for (int i=0; i<length; i++)
    {
        int num1 = (i < s1.size()) ? s1[i]-'0' : 0;
        int num2 = (i < s2.size()) ? s2[i]-'0' : 0;

        int sum = num1+num2+carry;
        carry = sum/10;
        result += (sum%10) + '0';
    }

    if (carry)
    {
        result += carry + '0';
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    int n;
    
    cin >> n;

    if (n==0)
    {
        cout << "0";
        return 0;
    }
    else if (n==1)
    {
        cout << "1";
        return 0;
    }
    else if (n==2)
    {
        cout << "1";
        return 0;
    }

    vector<string> arr(n+1);

    arr[0]="0";
    arr[1]="1";
    arr[2]="1";

    for (int i=3; i<=n; i++)
    {
        arr[i] = Add(arr[i-1], arr[i-2]);
    }

    cout << arr[n];
    
    
    return 0;
}