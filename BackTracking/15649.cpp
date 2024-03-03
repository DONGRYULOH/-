#include<iostream>	
using namespace std;

// N, M은 1~8 사이의 값 
int N, M;

// N과 M이 8일때 최대 길이가 8칸이 나옴 상태는 인덱스 1부터 시작하게끔 설정하므로 크기를 더 늘려줌
int arr[10];
int state[10]; // 0(사용가능), 1(사용중)

void func(int k) {

	// 1. base condition(재귀 함수 탈출 조건)
	// M의 길이만큼 숫자가 모두 들어갔을 때 
	// ex) M=1 일때 숫자가 하나만 들어가면 탈출해야 됨
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 2. 재귀식
	// N만큼 반복문을 돌면서 사용가능한 숫자가 있는지 체크
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

	// 1.입력	
	cin >> N >> M;

	// 2.로직
	// 최초 함수 인자값에 0을 넣는 이유는 배열에 인덱스 0부터 값이 들어가기 때문
	func(0);
	
	return 0;
}