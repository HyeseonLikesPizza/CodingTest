
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    int S=0;

    for (auto num : scoville)
    {
        pq.push(num);
    }
    
    while (pq.size() >= 2 && pq.top() < K)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        S = a+b*2;
        pq.push(S);
        answer++;
    }

    if (!pq.empty() && pq.top() >= K) return answer;
    

    return -1;
}
