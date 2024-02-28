#include<iostream>	
using namespace std;

// ������ �� ĭ
int board[2188][2188];

// -1[0], 0[1], 1[2] ä���� ���� ����
int cnt[3];

void func(int n, int x, int y) {

	// ������ �� ĭ�� ��� ���� ���� �Ǿ��ִ��� üũ 
	bool sameValCk = true;
	for (int i = x; i < n + x; i++) {
		for (int j = y; j < n + y; j++) {
			if (board[x][y] != board[i][j]) {
				sameValCk = false;
				break;
			}
		}
		if (!sameValCk) break;
	}

	if (sameValCk) {
		cnt[board[x][y] + 1] += 1;
		return;
	}
	else {
		int z = n / 3;
		// 1*1�� ��ĭ�̱� ������ ������ �Ȱ��� ���� �̷���� �־ ������ üũ�� �ʿ� ����
		// 9��п� ���ؼ� ����Լ� ���� 
		// �ٸ� ���̶� ���� ��ǥ�� �� 9����� ������ġ�� �����ϱ� ���ؼ��� x��, y�� �������� �̵��� z�� ������ߵ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {				
				func(z, x + i*z, y + j*z);
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.�Է�
	int N;
	cin >> N; // 3�� n�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 2.����
	func(N, 0, 0);

	// 3.���
	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];

	return 0;
}