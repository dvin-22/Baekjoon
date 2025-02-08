#include <iostream>
#include <vector>
using namespace std;
int sum=0;

void DFS(int N, int r, int c, vector<vector<int>> map){
  for (int i=r; i<N; i++)  map[i][c]=1;
  for (int i=1; r+i<N && c+i<N; i++)  map[r+i][c+i]=1;
  for (int i=1; r+i<N && c-i>=0; i++)  map[r+i][c-i]=1;

  if (r+1<N){
    for (int j=0; j<N; j++){
      if (map[r+1][j]==0){
        if (r+1<N-1) DFS(N, r+1, j, map);
        else sum++;
      }
    }
  }
}

int main() {
  int N;
  cin>>N;
  if (N==1) cout<<1;
  else if (N%2==0){
    for (int i=0; i<N/2; i++){
      vector<vector<int>> map(15,vector<int>(15,0));
      DFS(N, 0, i, map);
    }
    cout<<sum*2;
  }
  else{
    int r_sum=0;
    for (int i=0; i<N/2; i++){
      vector<vector<int>> map(15,vector<int>(15,0));
      DFS(N, 0, i, map);
    }
    r_sum+=(sum*2);
    sum=0;
    vector<vector<int>> map(15,vector<int>(15,0));
    DFS(N, 0, N/2, map);
    cout<<r_sum+sum;
  }

  return 0;
}