#include <iostream>
using namespace std;

int prime(int n) {
    if (n==2 || n==3 || n==5) return 1;
    if (n%2==0) return 0;
    for (int i=3; i<n/2; i++) {
        if (n%i==0) return 0;
    }
    return 1;
}

// B=N+1 -> 소인수
int main() {
    int T, N;
    cin>>T;

    for (int i=0; i<T; i++) {
        cin>>N;
        if (prime(N+1)==1) {
            cout<<1<<endl;
            cout<<1<<' '<<N+1<<endl;
            continue;
        }
        cout<<0<<endl;
    }

    return 0;
}