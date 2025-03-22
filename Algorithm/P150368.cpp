#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> discountList={10,20,30,40}; // 할인율
vector<int> emoticonsList; // 각 이모티콘의 가격
vector<vector<int>> usersList; // [0] : 할인율, [1] : 플러스 가입 기준 가격
vector<int> vl; //할인율 조합을 담을 스택

int result_count=0; //가장 큰 플러스 가입자 수
double result_amount=0; //가장 큰 총 금액

void print_vl() {
	for(int i = 0;i < vl.size();i++) {
		cout << vl[i] << " ";
	}
	cout << endl;
}

static void search() {
    if (vl.size() == emoticonsList.size()) {
        //cout << "---search---"<<endl;
        //print_vl();//디버깅용
        //스택이 다 찻을 경우,
        //해당 할인율 조합에 대해 계산 후 비교 및 업데이트

        vector<double> amountList; //각 할인율 적용한 금액
        int plus_count = 0;//플러스 가입자 수
        double total_amount = 0.0; //총 금액

        //1. 금액 계산
        for (int i = 0;i < vl.size();i++) {
			amountList.push_back(emoticonsList[i] * (1 - vl[i] / 100.0));
		}
        
        //2. 판매 금액과 플러스 가입자 수 계산 
        for(int i = 0; i < usersList.size();i++) {
            double user_amount = 0.0; //유저가 현재 사용한 금액
            bool flag = false; //이모티콘 구매 여부 확인용

            for(int j = 0;j < amountList.size();j++) {
                if(usersList[i][0] <= vl[j]) {
                    //할인율이 사용자의 할인율보다 작거나 같은 경우 => 이모티콘 구매
                    //판매액 증가
					user_amount += amountList[j];
   				}
                if(usersList[i][1]<=user_amount) {
                    //유저가 사용한 금액이 플러스 가입 기준 금액보다 크거나 같은 경우 => 플러스 가입
                    //플러스 가입자 수 증가
					plus_count++;
                    flag = true;
                    break;
				}
			}
			if(!flag) {
				//플러스 가입자가 아닌 경우
				total_amount += user_amount;
			}
		}

        //비교 및 업데이트
        if (plus_count > result_count) {
            result_count = plus_count;
            result_amount = total_amount;
        }
		else if (plus_count == result_count) {
			if (total_amount > result_amount) {
                //플러스 가입자 수는 같지만 총 금액이 더 큰 경우
				result_amount = total_amount;
			}
		}

    }
    else {
        for (int i = 0;i < discountList.size();i++) {
    		vl.push_back(discountList[i]);
			search();
			vl.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    emoticonsList=emoticons;
    usersList=users;
    search();
    answer.push_back(result_count);
    answer.push_back(result_amount);
    return answer;
}


int main() {
    vector<vector<int>> users = { {40,10000},{25,10000} };
	vector<int> emoticons = {7000,9000};
	vector<int> answer = solution(users, emoticons);
	cout << answer[0] << " " << answer[1] << endl;
	return 0;
}