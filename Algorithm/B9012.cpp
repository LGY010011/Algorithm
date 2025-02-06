#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	getchar();

	for (int i = 0;i < n;i++) {
		vector<char> v;
		string str;
		getline(cin, str);
		
		for (char c : str) {
			if (c == '(') {
				v.push_back(c);
			}
			else if (c == ')') {
				if (!v.empty()) {
					v.pop_back();
				}
				else {
					v.push_back(c);
					break;
				}
			}
			else if (c == '\n') {
				break;
			}
		}

		if (v.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		v.clear();
	}


	
	return 0;
}