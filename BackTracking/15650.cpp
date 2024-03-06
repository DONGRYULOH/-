#include<iostream>	
#include <algorithm>
using namespace std;


int N, M;
// N이 1부터 시작하니까 상태배열의 크기를 +1 증가해서 인덱스 1부터 상태체크(해당 숫자 사용 여부)
bool state[9];
int arr[8];

void func(int k) {

	if (k == M) {
		sort(arr, arr + M);
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int st = 1;
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i <= N; i++) {
		if (!state[i]) {
			arr[k] = i;
			state[i] = 1;
			func(k + 1);
			state[i] = 0;
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