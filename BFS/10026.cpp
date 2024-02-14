#include<iostream>
#include<queue>	
using namespace std;

// define �ڿ� ; �Ἥ Ʋ�� 
// #define X first
// #define Y second

char board[101][101];
bool vis[101][101];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main(void) {

	// 1.�Է�
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 2.����
	int notColorBlind = 0;
	int colorBlind = 0;

	// ���ϻ��� �ƴ� ���� ã��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] == 0) {
				queue<pair<int, int>> Q1;
				Q1.push({ i, j });
				vis[i][j] = 1;
				notColorBlind++;
				char curColor = board[i][j]; // ������ �Ǵ� color
				while (!Q1.empty()) {
					pair<int, int> cur = Q1.front(); Q1.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[nx][ny] == 1 || curColor != board[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q1.push({ nx, ny });
					}
				}
			}
		}
	}

	// vis �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vis[i][j] = 0;
		}
	}

	// ���ϻ��� ���� ã��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] == 0) {
				queue<pair<int, int>> Q1;
				Q1.push({ i, j });
				colorBlind++;
				char curColor = board[i][j]; // ������ �Ǵ� color
				while (!Q1.empty()) {
					pair<int, int> cur = Q1.front(); Q1.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[nx][ny] == 1) continue;
						if ((curColor == 'R' || curColor == 'G') && board[nx][ny] != 'B') {
							vis[nx][ny] = 1;
							Q1.push({ nx, ny });
						}
						else if (curColor == 'B' && board[nx][ny] == 'B') {
							vis[nx][ny] = 1;
							Q1.push({ nx, ny });
						}
					}
				}
			}
		}
	}

	cout << notColorBlind << " " << colorBlind;

	return 0;
}