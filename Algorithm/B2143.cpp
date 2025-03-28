//B2143.cpp
//두 배열의 합
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int n, m;
vector<int> A;
vector<int> B;
vector<pair<pair<int,int>, int>> A_sum; //A 부 배열 합
vector<pair<pair<int,int>, int>> B_sum; //B 부 배열 합
map<pair<int, int>, pair<int, int>> result_sub; //A, B 부 배열 조합

void print_vector(vector<int> arr) {
	
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_sum(vector<pair<pair<int, int>, int>> sum) {
	for (int i = 0;i < sum.size();i++) {
		cout << sum[i].first.first << " " << sum[i].first.second << ": " << sum[i].second << endl;
	}
}

void print_map(map<pair<int, int>, int> sum) {
	cout << "------------------------" << endl;
	for (auto it = sum.begin();it != sum.end();it++) {
		cout << it->first.first+1 << " " << it->first.second+1 << ": " << it->second << endl;
	}
}

//2.0. 부 배열 합 구하는 함수
void sum_array(vector<int> arr, bool type) {
	//type: true->A, false->B
	map<pair<int, int>, int> sum;

	//print_vector(arr);
	
	//2.0.1. 부 배열 합 구하기
	for (int start = 0;start < arr.size();start++) {
		//부 배열의 시작점을 i로 두고, 끝점을 j로 둔다.
		int temp_sum = 0;
		for (int end = start;end < arr.size();end++) {
			temp_sum += arr[end];

			//start to end 합이 T 미만이면 sum에 추가 하고서 end 증가
			if (temp_sum < T) {
				sum[{start, end}] = temp_sum;
				//cout<<start+1<<"+"<<end+1<<": "<<temp_sum<<endl;
			}
			else if (temp_sum >= T) {
				 //cout<<start+1<<"+"<<end+1<<": "<<temp_sum<<"초과" << endl;
				break;
			}
		}
	}

	//print_map(sum);

	//2.0.2. value 기준 정렬
	vector<pair<pair<int, int>, int>> temp;
	for (auto it = sum.begin();it != sum.end();it++) {
		temp.push_back({ it->first, it->second });
	}

	if(type){
		//A_sum : value 기준 오름차순
		sort(temp.begin(), temp.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
			return a.second < b.second;
		});
		A_sum = temp;
	}
	else{
		//B_sum : value 기준 내림차순
		sort(temp.begin(), temp.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
			return a.second > b.second;
		});
		B_sum = temp;
	}
}

//3.0. A_sum, B_sum 조합 구하기
void get_result() {
	//3.0.1. A_sum, B_sum 조합 구하기
	int j_start = 0;
	for (int i = 0;i < A_sum.size();i++) {
		auto a = A_sum[i];
		for (int j = j_start; j < B_sum.size();j++) {
			auto b = B_sum[j];
			if (a.second + b.second == T) {
				result_sub[a.first] = b.first;
			}
			else if (a.second + b.second > T) {
				j_start++;
			}
		}
	}
	cout<<result_sub.size()<<endl;
}


int main() {
	//1. 입력부
	//T: 전체 합
	cin >> T;
	//A.size
	cin >> n;

	//A
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		A.push_back(a);
	}

	//B.size
	cin >> m;
	//B
	for(int i=0;i<m;i++){
		int b;
		cin >> b;
		B.push_back(b);
	}

	//2. 부 배열 합 구하기
	//2.1. A 부 배열 합 구하기
	sum_array(A, true);
	//print_sum(A_sum);

	//2.2. B 부 배열 합 구하기
	sum_array(B, false);
	//print_sum(B_sum);
	
	//3. A, B 부배열 조합 구하기
	get_result();

	return 0;
}

/*
5
4
1 3 1 2
3
1 3 2
*/