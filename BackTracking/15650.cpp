#include<iostream>	
#include <algorithm>
using namespace std;


int N, M;
// N�� 1���� �����ϴϱ� ���¹迭�� ũ�⸦ +1 �����ؼ� �ε��� 1���� ����üũ(�ش� ���� ��� ����)
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

	// 1.�Է�	
	cin >> N >> M;	
	func(0);
	
	return 0;
}