//
// Created by Vincenzo Sanzone on 09/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void convertLine(string line, vector<ll> &history);

ll getValueFromHistory(vector<ll> history);

int main() {
	string line;
	ll result = 0;
	while (getline(cin, line) && line != "STOP") {
		vector<ll> history;
		convertLine(line, history);
		result += getValueFromHistory(history);
	}
	cout << result << endl;
}

ll getValueFromHistory(vector<ll> history) {
	vector<ll> newHistory(history.size() - 1);
	bool allZero = true;
	for (ll i = 1; i < history.size(); i++) {
		newHistory[i - 1] = history[i] - history[i - 1];
		if (newHistory[i - 1] != 0) allZero = false;
	}
	if (allZero) return history[history.size() - 1];
	return history[0] - getValueFromHistory(newHistory);
}

void convertLine(string line, vector<ll> &history) {
	stringstream ss(line);
	string token;
	while (getline(ss, token, ' ')) {
		history.push_back(stoll(token));
	}
}
