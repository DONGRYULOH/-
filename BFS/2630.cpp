#include<iostream>	
using namespace std;

// 종이의 각 칸
int board[130][130];

// 0[0], 1[1] 채워진 종이 개수
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

	// 모두 같은 값으로 이루어진 종이인지 체크 
	if (valSameCk(n, x, y)) {
		cnt[board[x][y]] += 1;
	}
	else {
		int half = n / 2;
		// 4등분을 하고 각 지점의 시작위치를 잡아주기 
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				// 4*4 -> 2*2 변환하는 과정에서 (0,2의 위치를 4등분할때 생각)
				// func(2, 0, 2) -> 종이가 나누어지면 기존에 분할한 x, y 위치부터 값을 체크하기 때문에 x, y를 추가해줘야 함
				func(half, x + half * i, y + half * j);
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력
	int N;
	cin >> N; // 2의 n승 형태

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 2.로직
	func(N, 0, 0);

	// 3.출력
	cout << cnt[0] << '\n' << cnt[1];

	return 0;
}