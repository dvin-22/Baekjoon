#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int t[n+1][n+1];
  for (int i=1; i<=n; i++){
    for (int j=1; j<=i; j++) cin>>t[i][j];
  }

  for (int i=n-1; i>0; i--){
    for (int j=1; j<=i; j++){
      t[i][j]+=max(t[i+1][j], t[i+1][j+1]);
    }
  }
  
  cout<<t[1][1];
  
  return 0;
}