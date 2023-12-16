//
// Created by Vincenzo Sanzone on 16/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(string &line);

int main(){
	freopen("Insert Your path", "r", stdin);
	string line;
	cin >> line;
	cerr << line << endl;
	stringstream ss(line);
	ll result = 0;
	while (getline(ss, line, ',')) {
		result += solve(line);
	}
	cout << result << endl;
}

ll solve(string &line) {
	ll result = 0;
	for(ll i = 0; i < line.size(); i++){
		result += line[i];
		result *= 17;
		result %= 256;
	}
	cerr << line << " " << result << endl;
	return result;
}
