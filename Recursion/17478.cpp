#include<iostream>	
using namespace std;

void func2(int cnt, int answer) {
	if (answer == 1) {
		cout << "��� �亯�Ͽ���." << '\n';
		return;
	}

	for (int i = 0; i < cnt; i++) cout << '_';
	cout << "��� �亯�Ͽ���." << '\n';
	func2(cnt - 4, answer - 1);
}

void func(int k, int cnt, int answer) {
	if (answer == 1) {
		cout << "\"����Լ��� ������?\"" << '\n';
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
		return;
	}

	func(k, cnt - 4, answer - 1);
	for (int i = 0; i < cnt; i++) cout << '_';
	cout << "\"����Լ��� ������?\"" << '\n';
	for (int i = 0; i < cnt; i++) cout << '_';

	if (k + 1 == answer) {
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		// "��� �亯�Ͽ���." ����Լ� ȣ�� 
		func2(cnt, answer);
	}
	else {
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
		for (int i = 0; i < cnt; i++) cout << '_';
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
		for (int i = 0; i < cnt; i++) cout << '_';
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.�Է�
	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	func(N, 4 * N, N + 1);



	return 0;
}