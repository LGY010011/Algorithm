#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int data;
	int index;
}Node;

//우선순위 큐
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
		//flag: 알고자 하는 문서 위치
		//max_index가 1이면 바로 출력
		if (max_index == 1)
			return 1;
		//flag 위치 찾기
		while (1) {
			bool check = false;
			Node first_node=heap[0];
			//더 큰 문서가 있는지 확인
			for (int i = 1;i < max_index;i++) {
				//남은 문서 중 하나라도 더 클 경우 뒤로 보냄
				if (first_node.data < heap[i].data) {
					//뒤로 보내기
					//cout<< first_node.index <<" " << first_node.data << " 뒤로 보내기" << endl;
					heap.push_back(first_node);
					heap.erase(heap.begin());
					check = true;
					break;
				}
			}
			//더 큰 문서가 없는 경우 pop
			if (!check) {
				heap.erase(heap.begin());
				max_index--;
				//cout << first_node.index << " " << first_node.data << " 출력" << endl;
				print_count++;
				if (first_node.index == flag) {
					//cout<<print_count<<"번째 출력" << endl;
					//cout<<first_node.index<<"번째 문서" << endl;
					return print_count;
				}
			}
			
		}
		
	}

	
};

int main() {
	//입력: 테스트 케이스 개수
	int T;
	cin >> T;
	//테스트 케이스 개수만큼 반복
	for (int i = 0;i < T;i++) {
		int N, M;
		PriorityQueue pq;
		//입력: 문서의 개수, 궁금한 문서 위치
		cin>> N >> M;
		pq.common_input(N);

		//출력: 문서의 출력 순서
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