#include <iostream>
using namespace std;

int m(int a, int b, int c){
  int temp=(a<b)?a:b;
  return (temp<c)?temp:c;
}

int main() {
  int size;
  cin >> size;
  int house[size][3], dp[size][3];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 3; j++)
      cin >> house[i][j];
  }

  dp[0][0]=house[0][0]; dp[0][1]=house[0][1]; dp[0][2]=house[0][2];
  for (int i=1; i<size; i++){
    dp[i][0]=min(dp[i-1][1], dp[i-1][2])+house[i][0];
    dp[i][1]=min(dp[i-1][0], dp[i-1][2])+house[i][1];
    dp[i][2]=min(dp[i-1][0], dp[i-1][1])+house[i][2];
  }

  cout<<m(dp[size-1][0], dp[size-1][1], dp[size-1][2]);
  
  return 0;
}