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
	priority_queue<int,vector<int>,greater<int>> lecture; //우선 순위 큐로 구현 = 오름차순, 가장 작은게 위에
	cin >> n;

	for (int i = 0;i < n;i++) {
		Class c;
		cin >> c.s >> c.t;
		class_list.push_back(c);
	}

	//시작 시간 순으로 정렬
	sort(class_list.begin(), class_list.end(), [](Class a, Class b) {
		return a.s < b.s;
	});

    lecture.push(class_list[0].t); //첫 강의실 배치

	//S1~Sn까지 반복하며 배치
	for (int i = 1;i < n;i++) {
		//cout<<"현재 강의실 수: "<<lecture.size()<<endl;
		//print_lecture(lecture);
		if (class_list[i].s >= lecture.top()) {
			//기존 강의실 배치
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