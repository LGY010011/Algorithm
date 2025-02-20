#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void print_bridge(vector<int> bridge) {
	for (int i = 0;i < bridge.size();i++) {
		cout << bridge[i] << " ";
	}
	cout << endl;
}

int main() {
	int n, w, L;
	int sum = 0;
	int count = 0;
	cin >> n;
	cin>>w >> L;

	vector<int> truck;
	vector<int> bridge(w, 0);

	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		truck.push_back(k);
	}


	while ((!truck.empty())||(sum!=0)) { // �ٸ��� �� �ǳ� Ʈ���� �ְų� �ٸ� ���� Ʈ���� ���� ���
		count++; //ȸ�� ����
		//cout <<"���� �ٸ� �� Ʈ���� �� : "<<sum << endl;
		//���� �ٸ� �� Ʈ���� �̵� ��Ų �� ���� Ʈ���� �ø��� ���� �Ǵ��ؾ� ��
		//�ٸ��� ù ��ġ Ʈ�� ����
		sum -= bridge.front(); 
		bridge.erase(bridge.begin());

		if (!truck.empty()) {
			//Ʈ���� �����ִ� ���
			if (sum + truck.front() > L) {
				//�ٸ��� Ʈ���� �ö� �� ���� ���
				//cout << truck.front() << " �ٸ��� �ö� �� ����" << endl;
				bridge.push_back(0);
			}
			else {
				//cout << truck.front() << " �ٸ��� �ö� �� ����" << endl;
				bridge.push_back(truck.front()); //�ٸ��� Ʈ�� �ֱ�
				truck.erase(truck.begin()); //Ʈ���� ��� ����
			}
		}
		else {
			//Ʈ���� ���� ���
			bridge.push_back(0);
		}
		sum+= bridge.back(); //�ٸ� �� Ʈ���� ��
		//print_bridge(bridge);
		//cout<<"Ȯ�� ���� ��: "<<sum << endl;
	}

	cout << count << endl;

	return 0;
}

/*
4 2 10
7 4 5 6
*/

/*
1 100 100
10
*/