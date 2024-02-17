#include<iostream>
#include<queue>	
using namespace std;

char board[1001][1001];
int fireMoveT[1001][1001];
int playerMoveT[1001][1001];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력
	int T;
	cin >> T;

	while (T--) {
		int w, h; // w(열), h(행)
		cin >> w >> h;

		// fireMoveT, playerMoveT 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				fireMoveT[i][j] = -1;
				playerMoveT[i][j] = -1;
			}
		}

		queue<pair<int, int>> Q1; // 불 위치
		queue<pair<int, int>> Q2; // 상근이 위치
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];				
				if (board[i][j] == '*') {
					fireMoveT[i][j] = 0;
					Q1.push({ i,j });
				} else if (board[i][j] == '@') {
					playerMoveT[i][j] = 0;
					Q2.push({ i,j });
				}
			}
		}		

		// 2.로직
		// 상근이가 처음부터 가장자리에 있는 경우
		pair<int, int> start = Q2.front();
		if (start.first == 0 || start.first == h - 1 || start.second == 0 || start.second == w - 1) {
			cout << 1 << '\n';
			continue;
		}

		// 지도 전체에 불이 붙는 시간 
		while (!Q1.empty()) {
			pair<int, int> cur = Q1.front();
			Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#' || fireMoveT[nx][ny] >= 0) continue;
				fireMoveT[nx][ny] = fireMoveT[cur.first][cur.second] + 1;
				Q1.push({ nx, ny });
			}
		}

		// 상근이의 이동시간
		bool notMove = false;
		while ( (!Q2.empty()) && (!notMove) ) {
			pair<int, int> cur = Q2.front();
			Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#') continue;
				if (playerMoveT[nx][ny] >= 0) continue;
				// 상근이의 이동시간이 불의 이동시간보다 무조건 작아야지 상근이가 이동이 가능 (이동시간이 동일하다면 동시에 접근하는 경우이기 때문에 이동 X)
				// 단, 불의 초기값을 -1로 세팅해놓았기 때문에 불이 없는 경우 -1보다 작은 값이 나오지 않기 때문에 이동이 불가능하므로 -1은 제외한다
				if (fireMoveT[nx][ny] != -1 && playerMoveT[cur.first][cur.second] + 1 >= fireMoveT[nx][ny]) continue;

				// 가장자리에 있는 경우 다음 for문에서 탈출하니까 여기서 이동시간 체크
				// **상근이가 처음부터 가장자리에 있는 경우는 이 식이 실행이 안됨**
				if (nx == 0 || nx == h-1 || ny == 0 || ny == w-1) {
					cout << playerMoveT[cur.first][cur.second] + 2 << "\n";
					notMove = true;
					break;
				}
				
				playerMoveT[nx][ny] = playerMoveT[cur.first][cur.second] + 1;
				Q2.push({ nx, ny });
			}
		}

		if (notMove == false) cout << "IMPOSSIBLE" << "\n";
	}


	return 0;
}