#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, S=1000000001, L=-1000000001;
//opr : + - x /

void operate(int num[11], int opr[10], int c, int result){
  if (c==N-1){
    if (result<S) S=result;
    if (result>L) L=result;
    return;
  }
  
  if (opr[0]!=0){
    opr[0]--;
    operate(num, opr, c+1, result+num[c+1]);
    opr[0]++;
  }
  if (opr[1]!=0){
    opr[1]--;
    operate(num, opr, c+1, result-num[c+1]);
    opr[1]++;
  }
  if (opr[2]!=0){
    opr[2]--;
    operate(num, opr, c+1, result*num[c+1]);
    opr[2]++;
  }
  if (opr[3]!=0){
    opr[3]--;
    operate(num, opr, c+1, result/num[c+1]);
    opr[3]++;
  }
}

int main() {
  cin>>N;  //입력값 받기
  int num[N], opr[4];
  for (int i=0; i<N; i++)
    cin>>num[i];
  for (int i=0; i<4; i++){
    cin>>opr[i];
  }

  operate(num, opr, 0, num[0]);
  cout<<L<<endl;
  cout<<S;
  
  return 0;
}