#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	int data;
	Node* prev;
} Node;

// Stack 구현
class Stack {
public:
	Node* top;
	int size;
	
	Stack() {
		top = NULL;
		size=0;
	}

	void push(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->prev = top;
		top = newNode;
		size++;
	}

	int pop() {
		if (top == NULL) {
			return -1;
		}
		Node* temp = top;
		top = top->prev;
		temp->prev = NULL;
		size--;
		return temp->data;
	}
	
	int getSize() {
		return size;
	}

	int isEmpty() {
		if (top == NULL)
			return 1;
		else
			return 0;
	}

	int getTop() {
		if (top == NULL) {
			return -1;
		}
		return top->data;
	}
};
int main() {
	Stack stack; //스택 생성
	int commandCount;
	cin >> commandCount;
	for (int i = 0;i < commandCount;i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int data;
			cin >> data;
			stack.push(data);
		}
		else if (command == "pop") {
			cout<<stack.pop()<<endl;
		}
		else if (command == "size") {
			cout << stack.getSize() << endl;
		}
		else if(command == "empty") {
			cout << stack.isEmpty() << endl;
		}
		else if (command == "top") {
			cout << stack.getTop() << endl;
		}
		else {
			cout << "잘못된 명령어입니다." << endl;
		}
	}
	
}