//오큰수
#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class NGES {
private:
	vector<int> nge;
	vector<int> input;
	int n;

public:
	NGES(int n) {
		this->n = n;
		nge.resize(n, -1); //초기화
	}

	void print() {
		for (int i = 0;i < n;i++) {
			cout << nge[i] << " ";
		}
		cout << endl;
	}

	void push() {
		stack<int> s; //오큰수 할당 안 된 인덱스 저장 스택

		for (int i = 0;i < n;i++) {
			int value;
			cin >> value;
			
			//현재 들어온 값과 아직 오큰수를 찾지 못한 인덱스들을 비교
			while(!s.empty()) {
				if (value <= input[s.top()]) break;
				nge[s.top()] = value;
				s.pop();
			}
			
			input.push_back(value);
			s.push(i);
		}

		print();
	}


};

int main() {
	int n;
	cin >> n; //수열의 크기

	NGES NGE(n);
	NGE.push();
		

	return 0;
}

/*
4
3 5 2 7
*/

/*
4
9 5 4 8
*/