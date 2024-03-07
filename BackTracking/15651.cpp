#include<iostream>	
using namespace std;


int N, M;
bool state[7][7];
int arr[7];

void func(int k) {

	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (state[k][i] == 0) {
			arr[k] = i + 1;
			state[k][i] = 1;
			func(k + 1);
			state[k][i] = 0;
		}
	}	

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 1.ют╥б	
	cin >> N >> M;	
	func(0);
	
	return 0;
}