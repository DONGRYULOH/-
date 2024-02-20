#include<iostream>
using namespace std;

using LL = long long;

LL func1(LL a, LL b , LL m) {
    if (b == 1) return a % m;
    LL val = func1(a, b / 2, m);

    // 짝수개인 경우 or 홀수개인 경우
    val = val * val % m;
    if (b % 2 == 0) return val;
    else return val * a % m;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    LL a, b, c;
    cin >> a >> b >> c;
    cout << func1(a, b, c);

    return 0;
}