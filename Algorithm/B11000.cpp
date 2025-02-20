#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct Class {
	int s;
	int t;
}Class;

int main() {
	int n;
	vector<Class> class_list;
	priority_queue<int,vector<int>,greater<int>> lecture; //�켱 ���� ť�� ���� = ��������, ���� ������ ����
	cin >> n;

	for (int i = 0;i < n;i++) {
		Class c;
		cin >> c.s >> c.t;
		class_list.push_back(c);
	}

	//���� �ð� ������ ����
	sort(class_list.begin(), class_list.end(), [](Class a, Class b) {
		return a.s < b.s;
	});

    lecture.push(class_list[0].t); //ù ���ǽ� ��ġ

	//S1~Sn���� �ݺ��ϸ� ��ġ
	for (int i = 1;i < n;i++) {
		//cout<<"���� ���ǽ� ��: "<<lecture.size()<<endl;
		//print_lecture(lecture);
		if (class_list[i].s >= lecture.top()) {
			//���� ���ǽ� ��ġ
			lecture.pop();
		}
		lecture.push(class_list[i].t);
	}

	//print_lecture(lecture);

	cout << lecture.size();

}

/*
3
1 3
2 4
3 5
*/

/*
8
1 8
9 16
3 7
8 10
10 14
5 6
6 11
11 12
*/