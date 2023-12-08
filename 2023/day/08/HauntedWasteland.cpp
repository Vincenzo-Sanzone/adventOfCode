//
// Created by Vincenzo Sanzone on 08/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, string> pss;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

ll lcm(vector<ll> number) {
	ll result = number[0];
	for (ll i = 1; i < number.size(); i++) {
		result = lcm(result, number[i]);
	}
	return result;
}

int main() {
	string map;
	cin >> map;
	unordered_map<string, pss> instructions;
	string keyName;
	vector<string> actualPosition;
	while (cin >> keyName && keyName != "STOP") {
		if (keyName[keyName.size() - 1] == 'A') {
			actualPosition.push_back(keyName);
		}
		string equals, left, right;
		cin >> equals >> left >> right;
		instructions[keyName] = pss(left.substr(1, left.size() - 2), right.substr(0, right.size() - 1));
	}
	vector<ll> pass(actualPosition.size());
	ll actualInstruction = 0;
	for (ll i = 0; i < actualPosition.size(); i++) {
		bool readAll = false;
		bool foundZ = false;
		while (actualPosition[i][actualPosition[i].size() - 1] != 'Z' || !readAll ||
		       !foundZ) {
			string newPosition;
			if (map[actualInstruction] == 'L') {
				newPosition = instructions[actualPosition[i]].first;

			} else {
				newPosition = instructions[actualPosition[i]].second;
			}
			actualPosition[i] = newPosition;
			pass[i]++;
			actualInstruction++;
			if (actualInstruction == map.size()) {
				actualInstruction = 0;
				readAll = true;
			}
			if (newPosition[newPosition.size() - 1] == 'Z') foundZ = true;
		}
	}
	cout << lcm(pass) << endl;
}