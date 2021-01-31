//https://shoark7.github.io/programming/algorithm/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EC%9D%84-%ED%95%B4%EA%B2%B0%ED%95%98%EB%8A%94-5%EA%B0%80%EC%A7%80-%EB%B0%A9%EB%B2%95.html
//위 블로그에 적힌 파이썬 코드를 C++로 구현
//행렬 곱셍을 활용한 풀이는 추후 구현 예정
//https://www.geeksforgeeks.org/c-program-for-n-th-fibonacci-number/
//나중에 위 사이트도 참고하면 좋을 거 같음

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int fibonacci_1(int num);	//기본 재귀적 풀이
int fibonacci_2(int num);	//반복적 풀이
int fibonacci_3(int num);	//반복적 동적 계획법 풀이
int fibonacci_4(int num);	//일반항 사용 풀이
int fibonacci_5(int num);	//행렬 곱셈을 활용한 풀이 (추후 구현 예정)

int main() {

	clock_t start, end;
	double result;

	cout << "===============기본 재귀적 풀이===============" << endl;

	start = clock();	//기본 재귀적 풀이

	cout << fibonacci_1(30) << endl;
	
	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============반복적 풀이===============" << endl;

	start = clock();

	cout << fibonacci_2(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============반복적 동적 계획법 풀이===============" << endl;

	start = clock();

	cout << fibonacci_3(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============일반항 사용 풀이===============" << endl;

	start = clock();

	cout << fibonacci_4(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============행렬 곱셈을 활용한 풀이===============" << endl;

	start = clock();

	cout << "미구현 알고리즘" << endl;
	//cout << fibonacci_5(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	return 0;
}

//기본 재귀적 풀이
int fibonacci_1(int num) {
	if (num < 2) {
		return num;
	}
	else {
		return fibonacci_1(num - 1) + fibonacci_1(num - 2);
	}
}

//반복적 풀이
int fibonacci_2(int num) {
	if (num < 2) {
		return num;
	}
	
	int a = 0;
	int b = 1;
	int temp;

	for (int i = 0; i < num - 1; i++) {
		temp = b;
		b = a + b;
		a = temp;
	}

	return b;
}

//반복적 동적 계획법 풀이
int fibonacci_3(int num) {

	if (num < 2) {
		return num;
	}

	int* cache = new int[num + 1];
	cache[0] = 0;
	cache[1] = 1;

	for (int i = 2; i <= num + 1; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
	}

	return cache[num];
}

//일반항 사용 풀이
int fibonacci_4(int num) {

	double sqrt_5 = pow(5.0, 1.0 / 2.0);
	double answer = 1 / sqrt_5 * ((pow(((1 + sqrt_5) / 2), num)) - pow(((1 - sqrt_5) / 2 ), num));

	return (int)answer;
}

//행렬 곱셈을 활용한 풀이 (추후 구현 예정)
int fibonacci_5(int num) {
	return 0;
}