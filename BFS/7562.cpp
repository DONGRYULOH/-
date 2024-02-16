#include<iostream>
#include<queue>	
using namespace std;

int dist[301][301];

// 나이트가 이동할 수 있는 모든 방향
int dx[8] = { -2, -1, -2, -1, 1, 2, 1, 2 };
int dy[8] = { -1, -2, 1, 2, -2, -1, 2, 1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int size;
		int startPtX, startPtY; 
		int	endPtX, endPtY;
		cin >> size;
		cin >> startPtX >> startPtY;
		cin >> endPtX >> endPtY;
		
		// 2.로직
		// dist 초기화 
		for (int a = 0; a < size; a++) {
			for (int b = 0; b < size; b++) {
				dist[a][b] = 0;
			}
		}

		queue<pair<int, int>> Q;
		dist[startPtX][startPtY] = 1;
		Q.push({ startPtX, startPtY });
		while (!Q.empty()) {
			pair<int, int> cur = Q.front();
			Q.pop();

			int nx, ny;
			for (int dir = 0; dir < 8; dir++) {
				nx = cur.first + dx[dir];
				ny = cur.second + dy[dir];

				// 범위, 방문여부 체크
				if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
				if (dist[nx][ny] > 0) continue;

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx, ny });
			}
		}

		// 3.결과
		cout << dist[endPtX][endPtY] - 1 << "\n";
	}


	return 0;
}