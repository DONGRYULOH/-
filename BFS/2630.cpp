#include<iostream>	
using namespace std;

// ������ �� ĭ
int board[130][130];

// 0[0], 1[1] ä���� ���� ����
int cnt[2];

bool valSameCk(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[x][y] != board[i][j]) return false;
		}
	}
	return true;
}

void func(int n, int x, int y) {

	// ��� ���� ������ �̷���� �������� üũ 
	if (valSameCk(n, x, y)) {
		cnt[board[x][y]] += 1;
	}
	else {
		int half = n / 2;
		// 4����� �ϰ� �� ������ ������ġ�� ����ֱ� 
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				// 4*4 -> 2*2 ��ȯ�ϴ� �������� (0,2�� ��ġ�� 4����Ҷ� ����)
				// func(2, 0, 2) -> ���̰� ���������� ������ ������ x, y ��ġ���� ���� üũ�ϱ� ������ x, y�� �߰������ ��
				func(half, x + half * i, y + half * j);
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.�Է�
	int N;
	cin >> N; // 2�� n�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 2.����
	func(N, 0, 0);

	// 3.���
	cout << cnt[0] << '\n' << cnt[1];

	return 0;
}