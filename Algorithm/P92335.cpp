//프로그래머스 k진수에서 소수 개수 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/92335
#include<iostream>
#include<cmath>
#include<stack>

using namespace std;

//3. 스택 출력 함수
void print_stack(stack<int> nums) {
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		cout << nums.top() << " ";
		nums.pop();
	}
	cout << endl;
}

//2. 소수 판별 함수
bool is_prime(stack<int> nums) {
	long long num = 0;
	int k = 10;
	int size = nums.size();

	//2.1. 스택에 있는 값들로 숫자 생성
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

	//2.2. 소수 판별
	if (num == 0 || num == 1) return false; //0과 1은 소수가 아님

	if (num == 2) return true; //2는 소수

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false; //소수가 아님
	}

	return true; //소수
}

//1. k 진수 변환 함수
int convert_to_base_k(int n, int k) {
	int quotient; //몫
	int remainder; //나머지
	int count = 0;

	stack<int> nums; //스택 생성

	//1. 몫이 0이 될 때까지 반복
	while (n > 0) {
		quotient = n / k; //몫
		remainder = n % k; //나머지

		//1.1. remainder가 0인 경우 스택에 있는 값들로 숫자 생성
		if (remainder == 0 && !nums.empty()) {
			//print_stack(nums); //스택 출력
			//1.1.1. 소수 판별
			//소수일 경우 count 증가
			if (is_prime(nums)) {
				count++;

			}
			//1.1.2. 스택 비우기
			while (!nums.empty()) {
				nums.pop(); //스택 비우기
			}
		}
		//1.2. remainder가 0이 아닌 경우 스택에 나머지 저장
		else if (remainder != 0) {
			nums.push(remainder); //스택에 나머지 저장
		}

		//1.3. 몫을 n으로 업데이트
		n = quotient; //n을 몫으로 업데이트
	}

	//1.4. 스택에 남아있는 값들로 숫자 생성
	if (!nums.empty()) {
		//1.4.1. 소수 판별
		//소수일 경우 count 증가
		if (is_prime(nums)) {
			count++;
		}
	}

	return count; //소수 개수 반환
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