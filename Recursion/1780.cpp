#include<iostream>	
using namespace std;

// 종이의 각 칸
int board[2188][2188];

// -1[0], 0[1], 1[2] 채워진 종이 개수
int cnt[3];

void func(int n, int x, int y) {

	// 종이의 각 칸이 모두 같은 수로 되어있는지 체크 
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
		// 1*1은 한칸이기 때문에 무조건 똑같은 수로 이루어져 있어서 조건을 체크할 필요 없음
		// 9등분에 대해서 재귀함수 실행 
		// 다른 값이랑 비교할 좌표를 각 9등분한 시작위치로 세팅하기 위해서는 x축, y축 방향으로 이동시 z를 더해줘야됨
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

	// 1.입력
	int N;
	cin >> N; // 3의 n승 형태

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 2.로직
	func(N, 0, 0);

	// 3.출력
	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];

	return 0;
}