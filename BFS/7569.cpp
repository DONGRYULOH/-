#include<iostream>
#include<tuple>	
#include<queue>	
using namespace std;

int board[101][101][101];
int vis[101][101][101]; // �;�� �丶���� �湮���� ǥ��

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0 ,0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.�Է�	
	int M, N, H; // M(��), N(��), H(����)		
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
					// ������ �丶�丸 -1�� �ٲٰ� �����丶��� ���� ��� 0�̻����� ����
					vis[j][k][i] = -1;
				}
			}
		}
	}

	// 2.����
	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front(); 
		Q.pop();
			
		/*
			tie() ����**
			Ʃ�÷� ���� �������� ��ȯ���� �ѹ��� �޾Ƽ� ȣ���ϴ� tie() �ʿ��� �������� ������ �Ҵ�
			int nx = get<0>(cur) -> curX + dx[dir];
			int ny = get<1>(cur) -> curY + dy[dir];
			int nz = get<2>(cur) -> curZ + dz[dir];
		*/		
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur; 

		// �����¿�, ���Ʒ� üũ 
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			// ����üũ
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			// �丶�� ���� ĭ, �̹� ���� �丶�� üũ
			if (vis[nx][ny][nz] >= 0) continue;
			vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
			Q.push({ nx,ny,nz });
		}
	}

	// 3.���
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (vis[j][k][i] == -1) {
					cout << -1 << "\n";
					return 0;
				}

				// vis�� ��� �湮�ϸ鼭 ���� ū �ּ� �ϼ��� ����
				if (vis[j][k][i] > ans) {
					ans = vis[j][k][i];
				}
			}
		}
	}

	// ��� �丶�䰡 �̹� �;������� 0�� �����(vis���� 0���� ū ���ڰ� �־���� �ּ��ϼ��� �ٲ�� ������)
	cout << ans << "\n";

	return 0;
}