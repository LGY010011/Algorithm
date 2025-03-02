//��ū��
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
		nge.resize(n, -1); //�ʱ�ȭ
	}

	void print() {
		for (int i = 0;i < n;i++) {
			cout << nge[i] << " ";
		}
		cout << endl;
	}

	void push() {
		stack<int> s; //��ū�� �Ҵ� �� �� �ε��� ���� ����

		for (int i = 0;i < n;i++) {
			int value;
			cin >> value;
			
			//���� ���� ���� ���� ��ū���� ã�� ���� �ε������� ��
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
	cin >> n; //������ ũ��

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