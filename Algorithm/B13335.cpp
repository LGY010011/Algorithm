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


	while ((!truck.empty())||(sum!=0)) { // 다리를 안 건넌 트럭이 있거나 다리 위에 트럭이 있을 경우
		count++; //회차 증가
		//cout <<"현재 다리 위 트럭의 합 : "<<sum << endl;
		//먼저 다리 위 트럭을 이동 시킨 후 조건 트럭을 올릴지 말지 판단해야 함
		//다리의 첫 위치 트럭 제거
		sum -= bridge.front(); 
		bridge.erase(bridge.begin());

		if (!truck.empty()) {
			//트럭이 남아있는 경우
			if (sum + truck.front() > L) {
				//다리에 트럭이 올라갈 수 없는 경우
				//cout << truck.front() << " 다리에 올라갈 수 없음" << endl;
				bridge.push_back(0);
			}
			else {
				//cout << truck.front() << " 다리에 올라갈 수 있음" << endl;
				bridge.push_back(truck.front()); //다리에 트럭 넣기
				truck.erase(truck.begin()); //트럭의 요소 제거
			}
		}
		else {
			//트럭이 없는 경우
			bridge.push_back(0);
		}
		sum+= bridge.back(); //다리 위 트럭의 합
		//print_bridge(bridge);
		//cout<<"확인 이후 합: "<<sum << endl;
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