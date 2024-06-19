#include <iostream>
using namespace std;

bool check(int list[][64], int row, int col, int size){
  int c=list[row][col];
  if (size==1) return 1;
  for (int i=row; i<row+size; i++){
    for (int j=col; j<col+size; j++){
      if (c!=list[i][j]) return 0;
    }
  }
  return 1;
}

void solve(int list[][64], int row, int col, int size){
  if (check(list, row, col, size)){ cout<<list[row][col]; return; }
  cout<<"(";
  solve(list, row, col, size/2); solve(list, row, col+size/2, size/2);
  solve(list, row+size/2, col, size/2); solve(list, row+size/2, col+size/2, size/2);
  cout<<")";
}

int main() {
  int N;
  cin>>N;
  int list[64][64];
  
  for (int i=0; i<N; i++){
    string str;
    cin>>str;
    for (int j=0; j<N; j++){
      list[i][j]=str[j]-'0';
    }
  }

  solve(list, 0, 0, N);
  
  return 0;
}