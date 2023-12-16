//
// Created by Vincenzo Sanzone on 16/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void solve(string &line, vector<map<string, pll>> &box);

void convertPosition(map<string, pll> &map, ll deleted);

int main() {
	freopen("Insert Your path", "r", stdin);
	string line;
	cin >> line;
	stringstream ss(line);
	ll result = 0;
	vector<map<string, pll>> box(256);
	while (getline(ss, line, ',')) {
		solve(line, box);
	}
	for (int i = 1; i <= box.size(); i++) {
		for (auto element = box[i - 1].begin(); element != box[i - 1].end(); element++) {
			result += element->second.first * element->second.second * i;
			cerr << element->first << " " << element->second.first * element->second.second * i << endl;
			cerr << element->second.first << " " << element->second.second << " " << i << endl;
		}
	}
	cout << result << endl;
}

void solve(string &line, vector<map<string, pll>> &box) {
	ll result = 0;
	ll number = -1;
	for (ll i = 0; i < line.size(); i++) {
		if (line[i] == '-') {
			if (box[result].find(line.substr(0, i)) != box[result].end()) {
				ll positionDeleted = box[result].find(line.substr(0, i))->second.second;
				box[result].erase(line.substr(0, i));
				convertPosition(box[result], positionDeleted);
			}
			break;
		} else if (line[i] == '=') {
			number = stoll(line.substr(i + 1, line.size() - 1));
			ll position = box[result].size() + 1;
			if (box[result].find(line.substr(0, i)) != box[result].end()) {
				position = box[result].find(line.substr(0, i))->second.second;
			}
			box[result][line.substr(0, i)] = make_pair(number, position);
			break;
		}
		result += line[i];
		result *= 17;
		result %= 256;
	}
}

void convertPosition(map<string, pll> &map, ll deleted) {
	for (auto element = map.begin(); element != map.end(); element++) {
		if (element->second.second > deleted) {
			element->second.second--;
		}
	}

}
