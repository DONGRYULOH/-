#include<iostream>	
using namespace std;

// N, M�� 1~8 ������ �� 
int N, M;

// N�� M�� 8�϶� �ִ� ���̰� 8ĭ�� ���� ���´� �ε��� 1���� �����ϰԲ� �����ϹǷ� ũ�⸦ �� �÷���
int arr[10];
int state[10]; // 0(��밡��), 1(�����)

void func(int k) {

	// 1. base condition(��� �Լ� Ż�� ����)
	// M�� ���̸�ŭ ���ڰ� ��� ���� �� 
	// ex) M=1 �϶� ���ڰ� �ϳ��� ���� Ż���ؾ� ��
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 2. ��ͽ�
	// N��ŭ �ݺ����� ���鼭 ��밡���� ���ڰ� �ִ��� üũ
	for (int i = 1; i <= N; i++) {
		if (state[i] == 0) {
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

	// 2.����
	// ���� �Լ� ���ڰ��� 0�� �ִ� ������ �迭�� �ε��� 0���� ���� ���� ����
	func(0);
	
	return 0;
}