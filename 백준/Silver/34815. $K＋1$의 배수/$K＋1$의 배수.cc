#include <iostream>
using namespace std;

int main() {
    long long N, K;
    cin>>N>>K;
    long long min=0, max=0;

    if (K%2==0) {
        min=(1+K)*(K/2);
        max=(N-K+1+N)*(K/2);
    } else {
        min=(K/2+1)*K;
        max=(N-(K/2))*K;
    }

    long long j=1;
    while ((K+1)*j<=max) { 
        if ((K+1)*j>=min) { 
            cout<<"YES";
            return 0;
        }
        j++;
    }
    cout<<"NO";

    return 0;
}