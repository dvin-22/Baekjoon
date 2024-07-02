#include <iostream>
using namespace std;

void DC(int n, int row, int col) {
  if ((row/n)%3==1 && (col/n)%3==1) cout<<' ';
  else if (n<3) cout<<'*';
  else DC(n/3, row, col);
  return;
}

int main() {

  int N;
  cin >> N;

  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      DC(N, i, j);
    }
    cout<<endl;
  }

  return 0;
}