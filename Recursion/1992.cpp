#include<iostream>	
using namespace std;

int board[65][65];

bool valSameCk(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[x][y] != board[i][j]) return false;
		}
	}
	return true;
}

void func(int n, int x, int y) {
	
	if (valSameCk(n, x, y)) {
		cout << board[x][y];
	}
	else {
		cout << '(';
		int half = n / 2;
		// 4등분을 하고 각 지점의 시작위치를 잡아주기 
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(half, x + half * i, y + half * j);
			}
		}
		cout << ')';
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력
	int N;
	cin >> N; // 2의 n승 형태

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			board[i][j] = str[j] - '0'; // 문자 1 아스키 코드 값 49 - 문자 0 아스키 코드 값 48 = 1이 나오게 됨
		}	
	}

	// 2.로직	
	func(N, 0, 0);		

	return 0;
}