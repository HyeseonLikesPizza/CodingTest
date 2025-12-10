#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    
    int result = 0;
    int current_num = 0;
    bool minus_flag = false;
    
    for(int i = 0; i <= str.size(); i++)
    {
        // 숫자인 경우 누적
        if(i < str.size() && isdigit(str[i]))
        {
            current_num = current_num * 10 + (str[i] - '0');
        }
        // 연산자이거나 문자열 끝인 경우
        else
        {
            if(minus_flag)
            {
                result -= current_num;
            }
            else
            {
                result += current_num;
            }
            
            current_num = 0;
            
            // - 만나면 이후로 계속 빼기
            if(i < str.size() && str[i] == '-')
            {
                minus_flag = true;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}