#include<iostream>
#include<tuple>	
#include<queue>	
using namespace std;

int board[101][101][101];
int vis[101][101][101]; // 익어가는 토마토의 방문여부 표시

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0 ,0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력	
	int M, N, H; // M(열), N(행), H(높이)		
	cin >> M >> N >> H;	
	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[j][k][i];
				if (board[j][k][i] == 1) {
					Q.push({ j,k,i });
				}
				else if (board[j][k][i] == 0) {
					// 안익은 토마토만 -1로 바꾸고 익은토마토와 벽은 모두 0이상으로 세팅
					vis[j][k][i] = -1;
				}
			}
		}
	}

	// 2.로직
	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front(); 
		Q.pop();
			
		/*
			tie() 사용법**
			튜플로 부터 여러개의 반환값을 한번에 받아서 호출하는 tie() 쪽에서 여러개의 변수에 할당
			int nx = get<0>(cur) -> curX + dx[dir];
			int ny = get<1>(cur) -> curY + dy[dir];
			int nz = get<2>(cur) -> curZ + dz[dir];
		*/		
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur; 

		// 상하좌우, 위아래 체크 
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			// 범위체크
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			// 토마토 없는 칸, 이미 익은 토마토 체크
			if (vis[nx][ny][nz] >= 0) continue;
			vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
			Q.push({ nx,ny,nz });
		}
	}

	// 3.결과
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (vis[j][k][i] == -1) {
					cout << -1 << "\n";
					return 0;
				}

				// vis를 모두 방문하면서 가장 큰 최소 일수를 구함
				if (vis[j][k][i] > ans) {
					ans = vis[j][k][i];
				}
			}
		}
	}

	// 모든 토마토가 이미 익어있으면 0을 출력함(vis에서 0보다 큰 숫자가 있어야지 최소일수가 바뀌기 때문에)
	cout << ans << "\n";

	return 0;
}