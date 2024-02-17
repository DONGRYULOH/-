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

	// 1.�Է�
	int T;
	cin >> T;

	while (T--) {
		int w, h; // w(��), h(��)
		cin >> w >> h;

		// fireMoveT, playerMoveT �ʱ�ȭ
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				fireMoveT[i][j] = -1;
				playerMoveT[i][j] = -1;
			}
		}

		queue<pair<int, int>> Q1; // �� ��ġ
		queue<pair<int, int>> Q2; // ����� ��ġ
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

		// 2.����
		// ����̰� ó������ �����ڸ��� �ִ� ���
		pair<int, int> start = Q2.front();
		if (start.first == 0 || start.first == h - 1 || start.second == 0 || start.second == w - 1) {
			cout << 1 << '\n';
			continue;
		}

		// ���� ��ü�� ���� �ٴ� �ð� 
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

		// ������� �̵��ð�
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
				// ������� �̵��ð��� ���� �̵��ð����� ������ �۾ƾ��� ����̰� �̵��� ���� (�̵��ð��� �����ϴٸ� ���ÿ� �����ϴ� ����̱� ������ �̵� X)
				// ��, ���� �ʱⰪ�� -1�� �����س��ұ� ������ ���� ���� ��� -1���� ���� ���� ������ �ʱ� ������ �̵��� �Ұ����ϹǷ� -1�� �����Ѵ�
				if (fireMoveT[nx][ny] != -1 && playerMoveT[cur.first][cur.second] + 1 >= fireMoveT[nx][ny]) continue;

				// �����ڸ��� �ִ� ��� ���� for������ Ż���ϴϱ� ���⼭ �̵��ð� üũ
				// **����̰� ó������ �����ڸ��� �ִ� ���� �� ���� ������ �ȵ�**
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