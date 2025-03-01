//B20040 사이클게임 [골4]
#include<iostream>
#include<vector>

using namespace std;

class Union {
private:
	//데이터 저장 배열
	vector<int> parent;
	//노드 개수
	int n;
	//사이클 생성 시기
	int count;

public:
	//생성자
	Union(int n) {
		this->n = n;
		parent.resize(n, -1);
		count = 0;
	}

	void print() {
		for (int i = 0;i < n;i++) {
			cout << parent[i] << " ";
		}
		cout << endl;
	}

	int find(int key) {
		//루트 노드 찾기
		if (parent[key] < 0) {
			//cout<<key<<endl;
			return key;
		}
		else {
			//cout<<"경로 압축"<<endl;
			return parent[key] = find(parent[key]);
		}
	}

	bool push(int a, int b) {
		//간선 추가
		//a와 b가 같은 집합에 속하는지 확인
		//같은 집합이면 사이클 발생
		//다른 집합이면 더 큰 집합으로 합치기
		
		int rootA = find(a);
		int rootB = find(b);

		//cout<<rootA<<" "<<rootB<<endl;
		
		if(rootA == rootB) {
			//같은 집합
			return true;
		}
		
		//다른 집합일 경우 연결
		if (parent[rootA] < parent[rootB]) {
			//rootA가 더 큰 집합
			parent[rootA] += parent[rootB];
			parent[rootB] = rootA;
		}
		else {
			//rootB가 더 큰 집합
			parent[rootB] += parent[rootA];
			parent[rootA] = rootB;
		}
		return false;
	}	

	int getCount() {
		return count;
	}

	void setCount(int v) {
		count = v;
	}
};

int main(void) {
	int n, m;

	cin >> n >> m;
	//n : 노드 개수
	//m : 에지 개수

	Union u(n);

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		if (u.push(a, b)&&u.getCount()==0) {
			//cout<<i+1;
			//cout << "사이클 발생" << endl;
			u.setCount( i + 1);
		}
		//u.print();
		//cout << u.getCount();
	}

	cout<<u.getCount();

	return 0;
}

/*
6 5
0 1
1 2
2 3
5 4
0 4
*/

/*
6 5
0 1
1 2
1 3
0 3
4 5
*/