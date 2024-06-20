#include <iostream>
using namespace std;

int main() {
  int N;
  cin>>N;
  int P[N+1];
  P[0]=0;
  for (int i=1; i<=N; i++) cin>>P[i];

  for (int i=2; i<=N; i++){
    for (int j=0; j<=i/2; j++){
      P[i]=max(P[i], P[i-j]+P[j]);
    }
  }
  
  cout<<P[N];
  
  return 0;
}