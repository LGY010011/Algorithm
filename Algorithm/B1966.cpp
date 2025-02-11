#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int data;
	int index;
}Node;

//�켱���� ť
class PriorityQueue {
private:
	vector<Node> heap;
	int max_index;
	int print_count;
public:
	PriorityQueue() {
		max_index = 0;
		print_count = 0;
	}

	void common_input(int n) {
		for(int i=0;i<n;i++) {
			Node node;
			cin >> node.data;
			node.index = i;
			heap.push_back(node);
		}
		max_index = n;
	}

	int get_print(int flag) {
		//flag: �˰��� �ϴ� ���� ��ġ
		//max_index�� 1�̸� �ٷ� ���
		if (max_index == 1)
			return 1;
		//flag ��ġ ã��
		while (1) {
			bool check = false;
			Node first_node=heap[0];
			//�� ū ������ �ִ��� Ȯ��
			for (int i = 1;i < max_index;i++) {
				//���� ���� �� �ϳ��� �� Ŭ ��� �ڷ� ����
				if (first_node.data < heap[i].data) {
					//�ڷ� ������
					//cout<< first_node.index <<" " << first_node.data << " �ڷ� ������" << endl;
					heap.push_back(first_node);
					heap.erase(heap.begin());
					check = true;
					break;
				}
			}
			//�� ū ������ ���� ��� pop
			if (!check) {
				heap.erase(heap.begin());
				max_index--;
				//cout << first_node.index << " " << first_node.data << " ���" << endl;
				print_count++;
				if (first_node.index == flag) {
					//cout<<print_count<<"��° ���" << endl;
					//cout<<first_node.index<<"��° ����" << endl;
					return print_count;
				}
			}
			
		}
		
	}

	
};

int main() {
	//�Է�: �׽�Ʈ ���̽� ����
	int T;
	cin >> T;
	//�׽�Ʈ ���̽� ������ŭ �ݺ�
	for (int i = 0;i < T;i++) {
		int N, M;
		PriorityQueue pq;
		//�Է�: ������ ����, �ñ��� ���� ��ġ
		cin>> N >> M;
		pq.common_input(N);

		//���: ������ ��� ����
		cout << pq.get_print(M) << endl;
	}
}

/*
5
1 0
5
*/

/*
1
4 2
1 2 3 4
*/

/*
1
6 0
1 1 9 1 1 1
*/