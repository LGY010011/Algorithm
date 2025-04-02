//���α׷��ӽ� n+1 ī�����
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	0: ���� �Ұ�
	1: ���� �Ϸ�
	2: ���� ����
*/

vector<int> g_cards; //ī�� ��ġ
vector<int> picked_cards; //�� �տ� �ִ� ī��
vector<int> possible_cards; //����� ������ ī��� (�̹� ���� ������ ī���)
int g_coin; //���� ���� ����
int g_index; //���� ī�� ��ġ ����Ű�� �ε���
int n; //��ü ī�� ��

void print_possible_cards() {
	for (int i = 1; i < possible_cards.size(); i++) {
		cout << possible_cards[i] << " ";
	}
	cout << endl;
}

void print_picked_cards() {
	for (int i = 0; i < picked_cards.size(); i++) {
		cout << picked_cards[i] << " ";
	}
	cout << endl;
}

void print_cards() {
	for (int i = 0; i < g_cards.size(); i++) {
		cout << g_cards[i] << " ";
	}
	cout << endl;
}

//ī�带 �̴� �Լ�
int get_result() {
	int round = 0;
	g_index = 0;
	possible_cards.resize(n+2,0);
	
	//1. �ʱ� ī�带 �̱�
	vector<int> temp_cards;  // �ʱ� ī�� ����� ����
	for (int i = 0; i < n / 3; i++) {
		temp_cards.push_back(g_cards[i]);
		possible_cards[g_cards[i]] = 1;
	}
	//1-1. ���� ī�� ����
	g_cards.erase(g_cards.begin(), g_cards.begin() + n / 3);
	picked_cards = temp_cards;

	bool possible = false; //���� ���� ���� ���� ����

	//2. ���� ����
	while (g_coin >= 0 && g_index < g_cards.size() - 1) {
		round++;
		//2-1. ī�� ��ġ���� ī�带 �̱�
		int first_card = g_cards[g_index];
		int second_card = g_cards[g_index + 1];

		possible_cards[g_cards[g_index]] = 2;
		possible_cards[g_cards[g_index + 1]] = 2;

		possible = false;

		//2-2. �� �տ� �ִ� ī�� ��
		vector<int> erase_cards; //������ ī��� ����� ����

		for (int i = 0; i < picked_cards.size(); i++) {
			int index = n + 1 - picked_cards[i];

			//2-2-1. �� �տ� �ִ� ī��� ���� ������ ī���� ���� n+1�� �Ǵ� ���: ���ʸ�	
			if (possible_cards[index] == 2 && g_coin > 0) {
				//������ ī�� ����
				possible_cards[index] = 1;
				g_coin -= 1;

				//ī�� ���� �Ϸ� ó��
				cout << "������ ī��: " << picked_cards[i] << " " << index << endl;
				possible = true;
				possible_cards[picked_cards[i]] = -1;
				possible_cards[index] = -1;
				erase_cards.push_back(i);
				break;
			}

			//2-2-2. �� �տ� �ִ� ī���� n+1�� ����� ���
			else if (possible_cards[index] == 1) {
				possible = true;

				//ī�� ���� �Ϸ� ó��
				cout << "������ ī��: " << picked_cards[i] << " " << index << endl;
				possible_cards[picked_cards[i]] = -1;
				possible_cards[n + 1 - picked_cards[i]] = -1;
				erase_cards.push_back(i);
				erase_cards.push_back(find(picked_cards.begin(), picked_cards.end(), index) - picked_cards.begin());
				break;
			}
		}

		//2-2-3. ���� ī��� �����
		for (int j = erase_cards.size() - 1; j >= 0; j--) {
			picked_cards.erase(picked_cards.begin() + erase_cards[j]);
		}

		//2-3. ���� ������ ī�忡�� ã��
		//2-3-1. ���� ī�� + ���� ���� ī��
		if (!possible) {

			if (possible_cards[n + 1 - first_card] == 2 && g_coin > 1) {
				cout << "������ ī��: " << first_card << " " << n + 1 - first_card << endl;
				g_coin -= 2;
				possible_cards[n + 1 - first_card] = -1;
				possible_cards[first_card] = -1;
				possible = true;
			}
			else if (possible_cards[n + 1 - second_card] == 2 && g_coin > 1) {
				cout << "������ ī��: " << second_card << " " << n + 1 - second_card << endl;
				g_coin -= 2;
				possible_cards[n + 1 - second_card] = -1;
				possible_cards[second_card] = -1;
				possible = true;
			}
		}

		
		/*cout << "round: " << round << endl;
		cout << "coin: " << g_coin << endl;	
		print_cards();
		print_possible_cards();
		print_picked_cards();
		cout << "-------------------" << endl;*/

		
		//4. ���� ���� ���� �Ұ����� ���
		
		if (!possible) {
			break;
		}
		if (g_index + 2 >= g_cards.size()) break;

		//4. ���� ���� ���� ������ ���
		g_index += 2;

	}

	//5. ���� ����
	//5-1.���� ����� ���� �����ߴ� ���
	if (possible) round++;

	//5-2. ���� ����� ���� ���������� ������ ���带 ��� �����ߴ� ���
	if (g_index  >= g_cards.size() - 1) round--;

	cout<<"g_index: "<<g_index<<endl;
	
	return  round;

}


int solution(int coin, vector<int> cards) {
    int answer = 0;
	g_cards = cards;
	g_coin = coin;
	n = cards.size();

	answer=get_result();


    return answer;
}

int main(void) {
	int coin;
	cin >> coin;
	
	int n;
	cin >> n;
	vector<int> cards;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cards.push_back(temp);
	}
	cout << solution(coin, cards) << endl;
	return 0;
}

/*
4
12
3 6 7 2 1 10 5 9 8 12 11 4
*/

/*
3
12
1 2 3 4 5 8 6 7 9 10 11 12
*/

/*
2
12
5 8 1 2 9 4 12 11 3 10 6 7
*/

/*
10
18
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
*/

/*
0
12
12 1 11 2 10 3 9 4 8 5 7 6

ans=3
*/

/*
6
6
1 6 2 5 3 4
*/