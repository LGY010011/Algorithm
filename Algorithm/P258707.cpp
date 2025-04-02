//프로그래머스 n+1 카드게임
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	0: 구매 불가
	1: 구매 완료
	2: 구매 가능
*/

vector<int> g_cards; //카드 뭉치
vector<int> picked_cards; //내 손에 있는 카드
vector<int> possible_cards; //만들기 가능한 카드들 (이미 지난 라운드의 카드들)
int g_coin; //내가 가진 코인
int g_index; //현재 카드 뭉치 가리키는 인덱스
int n; //전체 카드 수

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

//카드를 뽑는 함수
int get_result() {
	int round = 0;
	g_index = 0;
	possible_cards.resize(n+2,0);
	
	//1. 초기 카드를 뽑기
	vector<int> temp_cards;  // 초기 카드 저장용 벡터
	for (int i = 0; i < n / 3; i++) {
		temp_cards.push_back(g_cards[i]);
		possible_cards[g_cards[i]] = 1;
	}
	//1-1. 뽑은 카드 제거
	g_cards.erase(g_cards.begin(), g_cards.begin() + n / 3);
	picked_cards = temp_cards;

	bool possible = false; //다음 라운드 진행 가능 여부

	//2. 라운드 진행
	while (g_coin >= 0 && g_index < g_cards.size() - 1) {
		round++;
		//2-1. 카드 뭉치에서 카드를 뽑기
		int first_card = g_cards[g_index];
		int second_card = g_cards[g_index + 1];

		possible_cards[g_cards[g_index]] = 2;
		possible_cards[g_cards[g_index + 1]] = 2;

		possible = false;

		//2-2. 내 손에 있는 카드 비교
		vector<int> erase_cards; //제출한 카드들 저장용 벡터

		for (int i = 0; i < picked_cards.size(); i++) {
			int index = n + 1 - picked_cards[i];

			//2-2-1. 내 손에 있는 카드와 구매 가능한 카드의 합이 n+1이 되는 경우: 최초만	
			if (possible_cards[index] == 2 && g_coin > 0) {
				//가능한 카드 구매
				possible_cards[index] = 1;
				g_coin -= 1;

				//카드 지불 완료 처리
				cout << "지불한 카드: " << picked_cards[i] << " " << index << endl;
				possible = true;
				possible_cards[picked_cards[i]] = -1;
				possible_cards[index] = -1;
				erase_cards.push_back(i);
				break;
			}

			//2-2-2. 내 손에 있는 카드들로 n+1을 만드는 경우
			else if (possible_cards[index] == 1) {
				possible = true;

				//카드 지불 완료 처리
				cout << "지불한 카드: " << picked_cards[i] << " " << index << endl;
				possible_cards[picked_cards[i]] = -1;
				possible_cards[n + 1 - picked_cards[i]] = -1;
				erase_cards.push_back(i);
				erase_cards.push_back(find(picked_cards.begin(), picked_cards.end(), index) - picked_cards.begin());
				break;
			}
		}

		//2-2-3. 지울 카드들 지우기
		for (int j = erase_cards.size() - 1; j >= 0; j--) {
			picked_cards.erase(picked_cards.begin() + erase_cards[j]);
		}

		//2-3. 구매 가능한 카드에서 찾기
		//2-3-1. 뽑은 카드 + 구매 가능 카드
		if (!possible) {

			if (possible_cards[n + 1 - first_card] == 2 && g_coin > 1) {
				cout << "지불한 카드: " << first_card << " " << n + 1 - first_card << endl;
				g_coin -= 2;
				possible_cards[n + 1 - first_card] = -1;
				possible_cards[first_card] = -1;
				possible = true;
			}
			else if (possible_cards[n + 1 - second_card] == 2 && g_coin > 1) {
				cout << "지불한 카드: " << second_card << " " << n + 1 - second_card << endl;
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

		
		//4. 다음 라운드 진행 불가능한 경우
		
		if (!possible) {
			break;
		}
		if (g_index + 2 >= g_cards.size()) break;

		//4. 다음 라운드 진행 가능한 경우
		g_index += 2;

	}

	//5. 최종 조건
	//5-1.다음 라운드로 진행 가능했던 경우
	if (possible) round++;

	//5-2. 다음 라운드로 진행 가능했으나 가능한 라운드를 모두 성취했던 경우
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