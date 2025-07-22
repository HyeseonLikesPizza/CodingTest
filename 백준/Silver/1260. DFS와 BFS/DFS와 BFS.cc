
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

int map[1001][1001];
int N;
int ch[1001];

void DFS(int V) {

    cout << V << " ";

    for (int i = 1; i <= N; i++) {
        if (map[V][i] == 1 && ch[i] == 0) {
            ch[i] = 1;
            DFS(i);
        }
    }
}

void BFS(int V) {

    queue<int> q;

    q.push(V);
    ch[V] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";
        for (int i = 1; i <= N; i++) {
            if (map[top][i] == 1 && ch[i] == 0) {
                ch[i] = 1;
                q.push(i);
            }
        }
    }


}


int main() {

    int M, V, a,b;

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    ch[V] = 1;
    DFS(V);
    cout << endl;
    fill(ch, ch + 1001, 0);

    BFS(V);

    
    return 0;
}

