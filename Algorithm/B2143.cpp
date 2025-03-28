//B2143.cpp
//�� �迭�� ��
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int n, m;
vector<int> A;
vector<int> B;

unordered_map<int, int> A_sum_map;
unordered_map<int, int> B_sum_map;

void print_vector(vector<int> arr) {
	
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


//2.0. �� �迭 �� ���ϴ� �Լ�
void sum_array(vector<int> arr, bool type) {
	//type: true->A, false->B
	unordered_map<int, int> sum_map;
	
	//2.0.1. �� �迭 �� ���ϱ�
	for (int start = 0;start < arr.size();start++) {
		//�� �迭�� �������� i�� �ΰ�, ������ j�� �д�.
		int temp_sum = 0;
		for (int end = start;end < arr.size();end++) {
			temp_sum += arr[end];
			sum_map[temp_sum] += 1; //�ش� �� �󵵼� ����
		}
	}

	//print_map(sum);
	if(type) A_sum_map = sum_map;
	else B_sum_map = sum_map;

}

//3.0. A_sum, B_sum ���� ���ϱ�
void get_result() {
	//3.0.1. A_sum, B_sum ���� ���ϱ�
	//A_sum_map�� B_sum_map ��
	long long count = 0;
	for(auto& it: A_sum_map) {
		int a_sum = it.first;
		int a_count = it.second;

		if(B_sum_map.find(T-a_sum) != B_sum_map.end()) {
			count += (long long)a_count * B_sum_map[T - a_sum];
		}
	}
	
	cout<<count<<endl;
}


int main() {
	//1. �Էº�
	//T: ��ü ��
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

	//2. �� �迭 �� ���ϱ�
	//2.1. A �� �迭 �� ���ϱ�
	sum_array(A, true);

	//2.2. B �� �迭 �� ���ϱ�
	sum_array(B, false);
	
	//3. A, B �ι迭 ���� ���ϱ�
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