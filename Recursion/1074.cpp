#include<iostream>	
using namespace std;

int func(int n, int x, int y) {
    if (n == 0) return 0;
    int half = 1 << (n - 1);

    // 1번 사각형
    if (x < half && y < half) {
        return func(n - 1, x, y);
    }

    // 2번 사각형
    if (x < half && y >= half) {
        return half * half + func(n - 1, x, y - half);
    }

    // 3번 사각형
    if (x >= half && y < half) {
        return 2 * half * half + func(n - 1, x - half, y);
    }

    // 4번 사각형
    if (x >= half && y >= half) {
        return 3 * half * half + func(n - 1, x - half, y - half);
    }
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력
	int N, r, c;
	cin >> N >> r >> c;
	
    cout << func(N, r, c);

	return 0;
}