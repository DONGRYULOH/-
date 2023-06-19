// Algo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 백준 : 10808
#include <iostream>
using namespace std;

int main()
{	
	string S; // 단어 
	int sCount[26]; // 단어에 포함되어 있는 알파벳의 개수

	// 입력 
	cin >> S;

	for (auto i : S) {
		// i의 값이 a라면 아스키 코드 계산표에 의해서 97(a) - 97(a) = 0  		
		// a 알파벳 개수는 배열의 0번째 인덱스 위치에 저장된다.
		sCount[i - 'a']++;
	}

	// 출력 
	for (int i : sCount) {
		cout << i << " ";
	}
}

