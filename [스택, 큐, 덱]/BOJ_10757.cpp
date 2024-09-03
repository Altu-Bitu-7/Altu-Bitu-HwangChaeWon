#include<iostream>
#include<algorithm>

using namespace std;

string add(string a, string b) {
	string ans = ""; //결과값 담을 변수
	int temp = 0;

	int i, size = max(a.size(), b.size());

	if (a.size() < size) {
		for (int i = a.size(); i < size; i++) {
			a += '0';
		}
	}
	if (b.size() < size) {
		for (int i = b.size(); i < size; i++) {
			b += '0';
		}
	}
	//문자열 a,b 의 크기가 다를 경우, 크기가 더 작은 쪽 문자열에 '0'을 넣어 크기 맞춰주기.

	for (i = 0; i < size; i++) {
		temp += (int)(a[i] - '0') + (int)(b[i] - '0');
		ans += (char)(temp % 10 + '0');
		temp /= 10;
		//수의 올림을 고려하여 계산해주기
	}
	if ((char)(temp % 10 + '0') != '0') {
		ans += (char)(temp % 10 + '0');
	}//만약 마지막 수가 0 이라면 결과값에서 생략

	return ans;
}

int main() {
	string a, b, result;
	//문제의 조건이 long long 자료형의 범위도 벗어나기 때문에
	//문자열을 이용해 구현
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	//덧셈할 때 가장 낮은 자리수부터 더하기 때문에 
	//문자열 순서를 reverse

	result = add(a, b);

	reverse(result.begin(), result.end());

	cout << result;
}

