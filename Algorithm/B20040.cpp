//B20040 ����Ŭ���� [��4]
#include<iostream>
#include<vector>

using namespace std;

class Union {
private:
	//������ ���� �迭
	vector<int> parent;
	//��� ����
	int n;
	//����Ŭ ���� �ñ�
	int count;

public:
	//������
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
		//��Ʈ ��� ã��
		if (parent[key] < 0) {
			//cout<<key<<endl;
			return key;
		}
		else {
			//cout<<"��� ����"<<endl;
			return parent[key] = find(parent[key]);
		}
	}

	bool push(int a, int b) {
		//���� �߰�
		//a�� b�� ���� ���տ� ���ϴ��� Ȯ��
		//���� �����̸� ����Ŭ �߻�
		//�ٸ� �����̸� �� ū �������� ��ġ��
		
		int rootA = find(a);
		int rootB = find(b);

		//cout<<rootA<<" "<<rootB<<endl;
		
		if(rootA == rootB) {
			//���� ����
			return true;
		}
		
		//�ٸ� ������ ��� ����
		if (parent[rootA] < parent[rootB]) {
			//rootA�� �� ū ����
			parent[rootA] += parent[rootB];
			parent[rootB] = rootA;
		}
		else {
			//rootB�� �� ū ����
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
	//n : ��� ����
	//m : ���� ����

	Union u(n);

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		if (u.push(a, b)&&u.getCount()==0) {
			//cout<<i+1;
			//cout << "����Ŭ �߻�" << endl;
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