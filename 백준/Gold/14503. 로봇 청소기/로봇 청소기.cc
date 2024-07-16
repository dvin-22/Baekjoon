#include <iostream>
using namespace std;

int main() {
  int N, M, r, c, d, count=0;
  bool on=true;
  cin>>N>>M;
  cin>>r>>c>>d;
  int room[N][M];
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      cin>>room[i][j];
    }
  }

  while (on){
    if (room[r][c]==0){ count++; room[r][c]=2; }
    if (room[r-1][c]==0 || room[r+1][c]==0 || room[r][c-1]==0 || room[r][c+1]==0){
      d=(d+3)%4;
      if (d==0 && room[r-1][c]==0) r--;
      else if (d==3 && room[r][c-1]==0) c--;
      else if (d==2 && room[r+1][c]==0) r++;
      else if (d==1 && room[r][c+1]==0) c++;
    }
    else if (room[r-1][c]!=0 && room[r+1][c]!=0 && room[r][c-1]!=0 && room[r][c+1]!=0){
      if (d==0 && room[r+1][c]!=1) r++;
      else if (d==3 && room[r][c+1]!=1) c++;
      else if (d==2 && room[r-1][c]!=1) r--;
      else if (d==1 && room[r][c-1]!=1) c--;
      else on=false;
    }
  }

  cout<<count;
  return 0;
}