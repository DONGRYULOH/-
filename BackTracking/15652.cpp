#include<iostream>	
using namespace std;


int N, M;
bool state[8][9]; // N의 상태는 1부터 시작 인덱스 1부터 들어감
int arr[8];

void func(int k) {

	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int j = 1; // 1, 2 -> 길이가 1인 경우 비내림차순 정렬 적용 X 
	if (k >= 1) j = arr[k - 1]; // 1 1(O), 1 2(O), 2 1(X) -> K가 1부터 이전 인덱스의 값 이상이여야 함
	for (int i = j; i <= N; i++) {
		if (state[k][i] == 0) {
			arr[k] = i;
			state[k][i] = 1;
			func(k + 1);
			state[k][i] = 0;
		}
	}	

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.입력	
	cin >> N >> M;	
	func(0);
	
	return 0;
}