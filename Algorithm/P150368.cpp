#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> discountList={10,20,30,40}; // ������
vector<int> emoticonsList; // �� �̸�Ƽ���� ����
vector<vector<int>> usersList; // [0] : ������, [1] : �÷��� ���� ���� ����
vector<int> vl; //������ ������ ���� ����

int result_count=0; //���� ū �÷��� ������ ��
double result_amount=0; //���� ū �� �ݾ�

void print_vl() {
	for(int i = 0;i < vl.size();i++) {
		cout << vl[i] << " ";
	}
	cout << endl;
}

static void search() {
    if (vl.size() == emoticonsList.size()) {
        //cout << "---search---"<<endl;
        //print_vl();//������
        //������ �� ���� ���,
        //�ش� ������ ���տ� ���� ��� �� �� �� ������Ʈ

        vector<double> amountList; //�� ������ ������ �ݾ�
        int plus_count = 0;//�÷��� ������ ��
        double total_amount = 0.0; //�� �ݾ�

        //1. �ݾ� ���
        for (int i = 0;i < vl.size();i++) {
			amountList.push_back(emoticonsList[i] * (1 - vl[i] / 100.0));
		}
        
        //2. �Ǹ� �ݾװ� �÷��� ������ �� ��� 
        for(int i = 0; i < usersList.size();i++) {
            double user_amount = 0.0; //������ ���� ����� �ݾ�
            bool flag = false; //�̸�Ƽ�� ���� ���� Ȯ�ο�

            for(int j = 0;j < amountList.size();j++) {
                if(usersList[i][0] <= vl[j]) {
                    //�������� ������� ���������� �۰ų� ���� ��� => �̸�Ƽ�� ����
                    //�Ǹž� ����
					user_amount += amountList[j];
   				}
                if(usersList[i][1]<=user_amount) {
                    //������ ����� �ݾ��� �÷��� ���� ���� �ݾ׺��� ũ�ų� ���� ��� => �÷��� ����
                    //�÷��� ������ �� ����
					plus_count++;
                    flag = true;
                    break;
				}
			}
			if(!flag) {
				//�÷��� �����ڰ� �ƴ� ���
				total_amount += user_amount;
			}
		}

        //�� �� ������Ʈ
        if (plus_count > result_count) {
            result_count = plus_count;
            result_amount = total_amount;
        }
		else if (plus_count == result_count) {
			if (total_amount > result_amount) {
                //�÷��� ������ ���� ������ �� �ݾ��� �� ū ���
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