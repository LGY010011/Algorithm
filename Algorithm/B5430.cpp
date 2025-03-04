#include<iostream>
#include <string>

using namespace std;

class AC {
private:
	int* list_arr;
	int* front;
	int* back;
	int list_size;
	bool reverse; //true�� ������ ����

public:
	AC() {
		//������
		list_arr = NULL;
		front = NULL;
		back = NULL;
		list_size = 0;
		reverse = false;

	
	}
	
	void input_nums() {
		//���� �Է� �Լ�
		cin >> list_size;
		list_arr = new int[list_size]; //���� �迭 �����Ҵ�
		front= list_arr;
		back = list_arr + list_size -1;
		
		char ch;
		cin >> ch; // [ �Է� ������ 
		for (int i = 0;i < list_size;i++) {
			
			cin>>list_arr[i];
			//cout<<list_arr[i]<<endl;
			if(i!=list_size-1)
				cin >> ch; // , �Է� ������
		}
		//cout << list_size << endl;
		cin >> ch; //] �Է� ������
		
	};

	void R() {
		//����Ʈ ������ �Լ�
		//������ ����
		reverse=!reverse;
	}

	bool D() {
		//ù ���� ���� = pointer�� ����Ű�� ���� ���� �� ������ �̵�
		if (list_size == 0) {
			cout << "error" << endl;
			return true;
		}
		//cout << "���� ����" << endl;
		//reverse�� true�� back�� �̵�
		if(reverse){
			back--;
		}
		else{
			front++;
		}
		list_size--;

		return false;
	}

	void print() {
		//����Ʈ ��� �Լ�
		//reverse�� true�� ����� ���
		//cout << list_size << " : ";
		cout << "[";
		if (list_size == 0) {
			cout << "]" << endl;
			return;
		}

		//reverse�� true�� back-front ���
		int* temp = reverse ? back : front;
		for (int i = 0; i < list_size; i++) {
			cout << *temp;
			if (i != list_size - 1) {
				cout << ",";
			}
			temp += reverse ? -1 : 1;
		}
		cout << "]" << endl;
	}

	~AC() {
		//�Ҹ���
		delete[] list_arr;
	}
};

int main() {
	//test case ���� �Է�
	int test_case;
	cin >> test_case;
	for (int i = 0;i < test_case;i++) {
		AC ac; //AC ��ü ����

		//��ɾ� �Է�
		string command;
		cin>>command;
		
		//���� ���� �Է�
		ac.input_nums();


		//��ɾ� ����
		bool flag=false;
		for (int k = 0;k < command.size();k++) {
			if (command[k]=='R') 
				ac.R();
			else if(command[k]=='D') {
				if (ac.D()) {
					flag = true;
					break;
				}
			}
		}
		if(flag)
			continue;
		ac.print();
	}
	return 0;
}

/*
1
RDD
4
[1,2,3,4]
*/

/*
1
R
4
[1,2,3,4]
*/