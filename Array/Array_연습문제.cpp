// Algo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void insert(int idx, int num, int arr[], int& len) {
    // 1.배열의 길이를 늘림 
    // 어떻게 배열의 길이를 늘리지?? 
    

    // 포인터 배열의 길이 가져오는 방법 
    // 포인터 배열의 크기를 포인터 자료형의 크기로 나누면 배열 요소의 개수를 얻을 수 있습니다. 그 후, 각 요소에 대해 배열의 크기를 계산하여 배열의 길이를 가져옵니다.포인터 배열의 크기를 포인터 자료형의 크기로 나누면 배열 요소의 개수를 얻을 수 있습니다. 
    // 그 후, 각 요소에 대해 배열의 크기를 계산하여 배열의 길이를 가져옵니다.

    // 8byte / int자료형 크기 4byte

    cout << sizeof(len); // 8byte 
    cout << sizeof(arr[0]);

    int length = sizeof(arr);

    

    
}

void erase(int idx, int arr[], int& len) {
    
}

void printArr(int arr[], int& len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
}

int arrSum(int array[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && array[i] + array[j] == 100) return 1;
        }
    }

    return 0;
}

int arrSum2(int array[], int N) {
    int ocuurChk[101] = {}; 
    // 배열의 공간을 100칸 만든 이유는 무엇인가? 
    // 두 원소의 합이 100이 될 수 있는 공간을 만들고 등장 여부를 체크 
    // 0 + 100, 1 + 99, ~ 49 + 51 --> 총 100개의 배열 공간이 필요 

    // 입력값으로 주어진 배열의 인덱스를 순회하면서 해당 인덱스의 값과 X(미지수)을 더했을 때 100이 되는 수의 X의 값이 이전에 등장한 적이 있는지 체크 
    // 이전에 등장한 적이 있으면 해당 배열에서 두 개의 원소의 합이 100이 되는 조건임 
    for (int i = 0; i < N; i++) {
        if (ocuurChk[100 - array[i]] == 1) {
            return 1;
        }
        ocuurChk[array[i]] = 1;
    }

    return 0;
}

int main()
{
   // 합이 100인 서로 다른 두 원소 존재하면 1을 반환 
   // 조건 : O(N) 

    int array[5] = { 1, 52, 48 };
    int result = arrSum(array, 3);

    cout << result;
}









