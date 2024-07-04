#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N + 1);
  vector<int> in(N + 1, 0);

  for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      in[b]++;
  }

  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (in[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int x = q.front();
    cout << x << ' ';
    q.pop();
    for (int i = 0; i < adj[x].size(); i++) {
      int k = adj[x][i];
        in[k]--;
        if (in[k] == 0) q.push(k);
    }
  }

  return 0;
}
