//���α׷��ӽ� k�������� �Ҽ� ���� ���ϱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/92335
#include<iostream>
#include<cmath>
#include<stack>

using namespace std;

//3. ���� ��� �Լ�
void print_stack(stack<int> nums) {
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		cout << nums.top() << " ";
		nums.pop();
	}
	cout << endl;
}

//2. �Ҽ� �Ǻ� �Լ�
bool is_prime(stack<int> nums) {
	long long num = 0;
	int k = 10;
	int size = nums.size();

	//2.1. ���ÿ� �ִ� ����� ���� ����
	//cout << "make num: "<<endl;
	for (int i = 0;i < size;i++) {
		int temp = nums.top();
		if (i != 0)
			num *= k;

		num += temp;
		//cout << "num: " << num << endl;
		nums.pop();
	}
	//cout << "-----" << endl;

	//2.2. �Ҽ� �Ǻ�
	if (num == 0 || num == 1) return false; //0�� 1�� �Ҽ��� �ƴ�

	if (num == 2) return true; //2�� �Ҽ�

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false; //�Ҽ��� �ƴ�
	}

	return true; //�Ҽ�
}

//1. k ���� ��ȯ �Լ�
int convert_to_base_k(int n, int k) {
	int quotient; //��
	int remainder; //������
	int count = 0;

	stack<int> nums; //���� ����

	//1. ���� 0�� �� ������ �ݺ�
	while (n > 0) {
		quotient = n / k; //��
		remainder = n % k; //������

		//1.1. remainder�� 0�� ��� ���ÿ� �ִ� ����� ���� ����
		if (remainder == 0 && !nums.empty()) {
			//print_stack(nums); //���� ���
			//1.1.1. �Ҽ� �Ǻ�
			//�Ҽ��� ��� count ����
			if (is_prime(nums)) {
				count++;

			}
			//1.1.2. ���� ����
			while (!nums.empty()) {
				nums.pop(); //���� ����
			}
		}
		//1.2. remainder�� 0�� �ƴ� ��� ���ÿ� ������ ����
		else if (remainder != 0) {
			nums.push(remainder); //���ÿ� ������ ����
		}

		//1.3. ���� n���� ������Ʈ
		n = quotient; //n�� ������ ������Ʈ
	}

	//1.4. ���ÿ� �����ִ� ����� ���� ����
	if (!nums.empty()) {
		//1.4.1. �Ҽ� �Ǻ�
		//�Ҽ��� ��� count ����
		if (is_prime(nums)) {
			count++;
		}
	}

	return count; //�Ҽ� ���� ��ȯ
}

int solution(int n, int k) {
	int answer = -1;

	answer = convert_to_base_k(n, k);

	return answer;
}

int main(void) {
	long long n;
	int k;
	cin >> n;
	cin >> k;
	cout << solution(n, k) << endl;
	return 0;
}

/*
437674
3
*/

/*
110011
10
*/