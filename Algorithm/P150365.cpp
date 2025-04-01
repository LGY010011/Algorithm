//���α׷��ӽ� �̷� Ż�� ��ɾ�
#include<iostream>
#include<vector>

using namespace std;

int n, m; //n x m
int k; //Ƚ��
pair<int, int> xy; //x,y
pair<int, int> rc; //r,c
vector<char> path; //���� ���
bool impossible = false; //���� ���� ����


void print_stack() {

	for (char& c : path) {
		cout << c;
	}
	cout << endl;

}
//DIRECTION Ž�� �Լ�
void search(int x, int y, int cnt) {
	int dis_x = abs(x - rc.first);
	int dis_y = abs(y - rc.second);
	int d = dis_x + dis_y;
	
	cout << x << ", " << y << endl;
	cout << "cnt:" << cnt << "," << "d:" << d << endl;
	
	//0. ���� ���ǵ�
	//0.0. �̹� ��� ã�� ���
	if (impossible) return;

	//0.1. ����Ƚ���� �Ÿ����� ���� ��� stop
	if (cnt < d) {
		cout << "����Ƚ���� �Ÿ����� ���� ��� stop" << endl;
		return;
	}
	//0.2. cnt-d�� Ȧ�� �� ��� stop
	if ((cnt - d) % 2 != 0) {
		cout << "cnt-d�� Ȧ�� �� ��� stop" << endl;
		return;
	}

	//0.4. ������ ����
	if (cnt == 0 && x == rc.first && y == rc.second) {
		impossible = true;
		cout << rc.first << rc.second << endl;
		cout << x << y << endl;
		cout << cnt << endl;
		cout << "������ ����" << endl;
		print_stack();
		return;
	}
	
	
	//1. �������� ����
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
	//0. �Է�
	//0.1. n m �Է�
	cin >> n >> m;

	//0.2. x y �Է�
	cin >> xy.first;
	cin >> xy.second;
	xy.first--;
	xy.second--;

	//0.3. r c �Է�
	cin >> rc.first;
	cin >> rc.second;
	rc.first--;
	rc.second--;

	//0.4. k �Է�, cnt �ʱ�ȭ
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