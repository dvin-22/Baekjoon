#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int n, int A, int B, int C){
  if (n==1){
    cout<<A<<" "<<C<<"\n";
    return;
  }
  hanoi(n-1, A, C, B);
  cout<<A<<" "<<C<<"\n";
  hanoi(n-1, B, A, C);
}

int main() {
  int N;
  cin>>N;
  cout<<int(pow(2, N)-1)<<"\n";
  hanoi(N, 1, 2, 3);
  
  return 0;
}
