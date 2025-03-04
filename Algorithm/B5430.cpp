#include<iostream>
#include <string>

using namespace std;

class AC {
private:
	int* list_arr;
	int* front;
	int* back;
	int list_size;
	bool reverse; //true면 뒤집힌 상태

public:
	AC() {
		//생성자
		list_arr = NULL;
		front = NULL;
		back = NULL;
		list_size = 0;
		reverse = false;

	
	}
	
	void input_nums() {
		//원소 입력 함수
		cin >> list_size;
		list_arr = new int[list_size]; //원소 배열 동적할당
		front= list_arr;
		back = list_arr + list_size -1;
		
		char ch;
		cin >> ch; // [ 입력 버리기 
		for (int i = 0;i < list_size;i++) {
			
			cin>>list_arr[i];
			//cout<<list_arr[i]<<endl;
			if(i!=list_size-1)
				cin >> ch; // , 입력 버리기
		}
		//cout << list_size << endl;
		cin >> ch; //] 입력 버리기
		
	};

	void R() {
		//리스트 뒤집기 함수
		//포인터 변경
		reverse=!reverse;
	}

	bool D() {
		//첫 원소 삭제 = pointer가 가리키는 원소 제거 후 포인터 이동
		if (list_size == 0) {
			cout << "error" << endl;
			return true;
		}
		//cout << "정상 삭제" << endl;
		//reverse가 true면 back을 이동
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
		//리스트 출력 함수
		//reverse가 true면 뒤집어서 출력
		//cout << list_size << " : ";
		cout << "[";
		if (list_size == 0) {
			cout << "]" << endl;
			return;
		}

		//reverse가 true면 back-front 출력
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
		//소멸자
		delete[] list_arr;
	}
};

int main() {
	//test case 개수 입력
	int test_case;
	cin >> test_case;
	for (int i = 0;i < test_case;i++) {
		AC ac; //AC 객체 생성

		//명령어 입력
		string command;
		cin>>command;
		
		//원소 개수 입력
		ac.input_nums();


		//명령어 수행
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