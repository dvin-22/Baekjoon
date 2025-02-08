#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

struct RC {  int r, c;  };
struct RC rc;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N+1, vector<int>(M+1,0));
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
    for (int j = 1; j <= M; j++)  map[i][j]=s[j-1] - '0';
    }
    map[1][1]=-1;

    queue<RC> q;
    rc.r=1;
    rc.c=1;
    q.push(rc);
  
    while (!q.empty()){
        int r=q.front().r, c=q.front().c;
        q.pop();

    if (r+1<=N){
        if (map[r+1][c]==1) {
            map[r+1][c]=abs(map[r][c])+1;
            rc.r=r+1; rc.c=c;
            q.push(rc);
        }
        else if (map[r+1][c]>map[r][c]+1) map[r+1][c]=map[r][c]+1;
    }
    if (c+1<=M){
        if (map[r][c+1]==1) {
            map[r][c+1]=abs(map[r][c])+1;
            rc.r=r; rc.c=c+1;
            q.push(rc);
        }
        else if (map[r][c+1]>map[r][c]+1) map[r][c+1]=map[r][c]+1;
    }
    if (r-1>=1){
        if (map[r-1][c]==1) {
            map[r-1][c]=map[r][c]+1;
            rc.r=r-1; rc.c=c;
            q.push(rc);
        }
        else if (map[r-1][c]>map[r][c]+1) map[r-1][c]=map[r][c]+1;
    }
    if (c-1>=1){
        if (map[r][c-1]==1) {
            map[r][c-1]=map[r][c]+1;
            rc.r=r; rc.c=c-1;
            q.push(rc);
        }
        else if (map[r][c-1]>map[r][c]+1) map[r][c-1]=map[r][c]+1;
        }
    }
  
    cout<<map[N][M];
  
    return 0;
}