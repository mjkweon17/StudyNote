//https://shoark7.github.io/programming/algorithm/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EC%9D%84-%ED%95%B4%EA%B2%B0%ED%95%98%EB%8A%94-5%EA%B0%80%EC%A7%80-%EB%B0%A9%EB%B2%95.html
//�� ��α׿� ���� ���̽� �ڵ带 C++�� ����
//��� ������ Ȱ���� Ǯ�̴� ���� ���� ����
//https://www.geeksforgeeks.org/c-program-for-n-th-fibonacci-number/
//���߿� �� ����Ʈ�� �����ϸ� ���� �� ����

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int fibonacci_1(int num);	//�⺻ ����� Ǯ��
int fibonacci_2(int num);	//�ݺ��� Ǯ��
int fibonacci_3(int num);	//�ݺ��� ���� ��ȹ�� Ǯ��
int fibonacci_4(int num);	//�Ϲ��� ��� Ǯ��
int fibonacci_5(int num);	//��� ������ Ȱ���� Ǯ�� (���� ���� ����)

int main() {

	clock_t start, end;
	double result;

	cout << "===============�⺻ ����� Ǯ��===============" << endl;

	start = clock();	//�⺻ ����� Ǯ��

	cout << fibonacci_1(30) << endl;
	
	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============�ݺ��� Ǯ��===============" << endl;

	start = clock();

	cout << fibonacci_2(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============�ݺ��� ���� ��ȹ�� Ǯ��===============" << endl;

	start = clock();

	cout << fibonacci_3(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============�Ϲ��� ��� Ǯ��===============" << endl;

	start = clock();

	cout << fibonacci_4(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	cout << "===============��� ������ Ȱ���� Ǯ��===============" << endl;

	start = clock();

	cout << "�̱��� �˰���" << endl;
	//cout << fibonacci_5(30) << endl;

	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl << endl;

	return 0;
}

//�⺻ ����� Ǯ��
int fibonacci_1(int num) {
	if (num < 2) {
		return num;
	}
	else {
		return fibonacci_1(num - 1) + fibonacci_1(num - 2);
	}
}

//�ݺ��� Ǯ��
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

//�ݺ��� ���� ��ȹ�� Ǯ��
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

//�Ϲ��� ��� Ǯ��
int fibonacci_4(int num) {

	double sqrt_5 = pow(5.0, 1.0 / 2.0);
	double answer = 1 / sqrt_5 * ((pow(((1 + sqrt_5) / 2), num)) - pow(((1 - sqrt_5) / 2 ), num));

	return (int)answer;
}

//��� ������ Ȱ���� Ǯ�� (���� ���� ����)
int fibonacci_5(int num) {
	return 0;
}