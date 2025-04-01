//프로그래머스 미로 탈출 명령어
#include<iostream>
#include<vector>

using namespace std;

int n, m; //n x m
int k; //횟수
pair<int, int> xy; //x,y
pair<int, int> rc; //r,c
vector<char> path; //누적 경로
bool impossible = false; //도달 가능 여부


void print_stack() {

	for (char& c : path) {
		cout << c;
	}
	cout << endl;

}
//DIRECTION 탐색 함수
void search(int x, int y, int cnt) {
	int dis_x = abs(x - rc.first);
	int dis_y = abs(y - rc.second);
	int d = dis_x + dis_y;
	
	cout << x << ", " << y << endl;
	cout << "cnt:" << cnt << "," << "d:" << d << endl;
	
	//0. 종료 조건들
	//0.0. 이미 경로 찾은 경우
	if (impossible) return;

	//0.1. 남은횟수가 거리보다 적을 경우 stop
	if (cnt < d) {
		cout << "남은횟수가 거리보다 적을 경우 stop" << endl;
		return;
	}
	//0.2. cnt-d가 홀수 일 경우 stop
	if ((cnt - d) % 2 != 0) {
		cout << "cnt-d가 홀수 일 경우 stop" << endl;
		return;
	}

	//0.4. 목적지 도착
	if (cnt == 0 && x == rc.first && y == rc.second) {
		impossible = true;
		cout << rc.first << rc.second << endl;
		cout << x << y << endl;
		cout << cnt << endl;
		cout << "목적지 도착" << endl;
		print_stack();
		return;
	}
	
	
	//1. 방향으로 진행
	if (x + 1 < n) {
		path.push_back('d');
		search(x + 1, y, cnt - 1);
		if (!impossible) path.pop_back();
		if (impossible) return;
	}
	if (y - 1 >= 0) {
		path.push_back('l');
		search(x, y - 1, cnt - 1);
		if (!impossible) path.pop_back();
		if (impossible) return;
	}
	if (y + 1 < m) {
		path.push_back('r');
		search(x, y + 1, cnt - 1);
		if (!impossible) path.pop_back();
		if (impossible) return;
	}
	if (x - 1 >= 0) {
		path.push_back('u');
		search(x - 1, y, cnt - 1);
		if (!impossible) path.pop_back();
		if (impossible) return;
	}
	
	
}


int main() {
	//0. 입력
	//0.1. n m 입력
	cin >> n >> m;

	//0.2. x y 입력
	cin >> xy.first;
	cin >> xy.second;
	xy.first--;
	xy.second--;

	//0.3. r c 입력
	cin >> rc.first;
	cin >> rc.second;
	rc.first--;
	rc.second--;

	//0.4. k 입력, cnt 초기화
	cin >> k;

	search(xy.first, xy.second, k);

	if (impossible) {
		string result(path.begin(), path.end());
		cout << result;
	}
	

	return 0;
}

/*
3 4
2 3
3 1
5
*/