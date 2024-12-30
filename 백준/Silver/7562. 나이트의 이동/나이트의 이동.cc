#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // min 함수 사용을 위해 추가
using namespace std;

struct coord {
  int r;
  int l;
};

int mr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};  // row 이동
int ml[8] = {-1, 1, -2, 2, -2, 2, -1, 1};  // column 이동

int main() {
  int N;
  cin >> N;

  // N번 테스트 케이스 처리
  for (int n = 0; n < N; n++) {
    int I;
    struct coord start, end;
    cin >> I;
    cin >> start.r >> start.l;
    cin >> end.r >> end.l;

    // 동적 배열로 map 크기 설정
    vector<vector<int>> map(I, vector<int>(I, 0));

    queue<coord> q;
    q.push(start);
    map[start.r][start.l] = 1;  // 시작 지점 방문 처리

    while (!q.empty()) {
      struct coord temp = q.front();
      q.pop();

      // 목적지에 도달하면 종료
      if (end.r == temp.r && end.l == temp.l) {
        break;
      }

      // 8방향으로 이동
      for (int i = 0; i < 8; i++) {
        struct coord move;
        move.r = temp.r + mr[i];
        move.l = temp.l + ml[i];

        // 유효한 위치인지 확인
        if (move.r >= 0 && move.r < I && move.l >= 0 && move.l < I) {
          // 방문하지 않은 곳만 처리
          if (map[move.r][move.l] == 0) {
            q.push(move);
            map[move.r][move.l] = map[temp.r][temp.l] + 1;
          }
        }
      }
    }

    // 결과 출력
    cout << map[end.r][end.l] - 1 << endl;  // 시작점도 포함되어 있으므로 -1
  }

  return 0;
}
