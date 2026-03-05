#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int N, M;
    long long result=0, score[200000]={0,};
    cin>>N>>M;

    for (int i=0; i<M; i++) {
        int winner, loser;
        cin>>winner>>loser;
        score[winner-1]++;
    }

    sort(score, score+N);

    for (int i=1; i<N; i++) {
        if (score[i]<=score[i-1]) {
            result+=score[i-1]-score[i]+1;
            score[i]+=score[i-1]-score[i]+1;
        }
    }

    cout<<result;
    
    return 0;
}