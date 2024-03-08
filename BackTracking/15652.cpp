#include<iostream>	
using namespace std;


int N, M;
bool state[8][9]; // N�� ���´� 1���� ���� �ε��� 1���� ��
int arr[8];

void func(int k) {

	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int j = 1; // 1, 2 -> ���̰� 1�� ��� �񳻸����� ���� ���� X 
	if (k >= 1) j = arr[k - 1]; // 1 1(O), 1 2(O), 2 1(X) -> K�� 1���� ���� �ε����� �� �̻��̿��� ��
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

	// 1.�Է�	
	cin >> N >> M;	
	func(0);
	
	return 0;
}