#include<iostream>	
#include<algorithm>
using namespace std;

int N, M;
bool state[10000]; // 사용여부 상태
int arr[10000];  // 상태에 대한 데이터 배열이 {1,2,3} 순으로 정렬되어 있으면 상태배열에 [0],[1],[2] 각각 매칭됨
int temp[10000]; // 재귀함수를 돌면서 모든 경우의 수를 체크해 출력하기 위한 용도

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

	// 1.입력	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); // 오름차순 정렬
	func(0);
	
	return 0;
}