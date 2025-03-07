#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int n, s;
	cin >> n >> s;

	int* arr = new int[n];
	
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	
	
	vector<int> S;
	int sum = 0;
	int minSize = n+1;

	for(int i=0;i<n;i++) {
		
		S.push_back(arr[i]);
		sum += arr[i];
		//cout<<i<<"까지 넣음 : ";
		if (sum >= s) {
			while (sum >= s) {
				if (sum - S[0] >= s) {
					sum -= S[0];
					S.erase(S.begin());
				}
				else {
					break;
				}
			}
			minSize = min(minSize, (int)S.size());
		}
		//cout<<sum<<" "<<S.size()<<" "<<minSize<<endl;
		//cout<<minSize<<endl;
		//cout << S.size() << endl;
	}

	if (minSize == n+1) cout << 0 << endl;
	else cout << minSize << endl;


}

/*
10 15
5 1 3 5 10 7 4 9 2 8
*/

/*
6 12
1 6 6 1 1 10
*/

/*
3 3
1 1 1
*/