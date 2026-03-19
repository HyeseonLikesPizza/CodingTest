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
#include <string>
#include <iomanip>

using namespace std;

float AverageScore(string grade)
{
    if (grade == "A+") return 4.5f;
    else if (grade == "A0") return 4.0f;
    else if (grade == "B+") return 3.5f;
    else if (grade == "B0") return 3.0f;
    else if (grade == "C+") return 2.5f;
    else if (grade == "C0") return 2.0f;
    else if (grade == "D+") return 1.5f;
    else if (grade == "D0") return 1.0f;
    else return 0.0f;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    float ScoreSum = 0;
    float Sum = 0;
    for (int i=0; i<20; i++)
    {
        string temp;
        float score;

        cin >> temp >> score >> temp;
        if (temp == "P") continue;

        Sum += score * AverageScore(temp);
        ScoreSum += score;
    }
    
    cout << fixed << setprecision(6) << Sum / ScoreSum;
    
    return 0;
}
