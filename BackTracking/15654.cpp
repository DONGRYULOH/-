#include<iostream>	
#include<algorithm>
using namespace std;

int N, M;
bool state[10000]; // ��뿩�� ����
int arr[10000];  // ���¿� ���� ������ �迭�� {1,2,3} ������ ���ĵǾ� ������ ���¹迭�� [0],[1],[2] ���� ��Ī��
int temp[10000]; // ����Լ��� ���鼭 ��� ����� ���� üũ�� ����ϱ� ���� �뵵

void func(int k) {

	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << temp[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (state[i] == 0) {
			temp[k] = arr[i];
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
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); // �������� ����
	func(0);
	
	return 0;
}