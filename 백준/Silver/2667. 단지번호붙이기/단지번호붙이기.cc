#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[25][25]={0,}, idx=-1;
vector<int> total;

void find_size(int N, int r, int c){
  if (r<0 || r>=N || c<0 || c>=N)
    return;
  else if (map[r][c]==1){
    total[idx]++;
    map[r][c]=0;
    find_size(N, r, c+1);
    find_size(N, r+1, c);
    find_size(N, r, c-1);
    find_size(N, r-1, c);
  }
  return;
}

void solve(int N, int r, int c){
  if (r<0 || r>=N || c<0 || c>=N || map[r][c]==-1)
    return;
  else if (map[r][c]==0){
    map[r][c]=-1;
    solve(N, r, c+1);
    solve(N, r+1, c);
    solve(N, r, c-1);
    solve(N, r-1, c);
  }
  else if (map[r][c]==1){
    idx++;
    total.push_back(0);
    find_size(N, r, c);
    solve(N, r, c+1);
    solve(N, r+1, c);
    solve(N, r, c-1);
    solve(N, r-1, c);
  }
}

int main() {
  int N;
  cin>>N;
  for (int i=0; i<N; i++){
    string temp;
    cin>>temp;
    for (int j=0; j<N; j++){
      map[i][j]=temp[j]-'0';
    }
  }

  solve(N, 0, 0);
  sort(total.begin(), total.end());
  cout<<total.size()<<endl;
  for (int i=0; i<total.size(); i++)
    cout<<total[i]<<endl;
  
  return 0;
}