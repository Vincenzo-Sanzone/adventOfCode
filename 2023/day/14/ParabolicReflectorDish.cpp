//
// Created by Vincenzo Sanzone on 16/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void reoganizeMap(vector<string> &map);

void north(vector<string> &map);

void west(vector<string> &map);

void south(vector<string> &map);

void east(vector<string> &map);

ll findResult(const vector<string> &map);

int main() {
	vector<string> mapRocks;
	string line;
	while (cin >> line && line != "STOP") {
		mapRocks.push_back(line);
	}
	map<vector<string>, ll> memo;
	ll i, start;
	for (i = 0; i < 1000000000; i++) {
		reoganizeMap(mapRocks);
		if (memo.find(mapRocks) != memo.end()) {
			start = memo.find(mapRocks)->second;
			break;
		}
		memo[mapRocks] = i;
	}
	vector<ll> results(i);
	for (auto element = memo.begin(); element != memo.end(); element++) {
		results[element->second] = findResult(element->first);
	}
	cout << results[(1000000000 - i) % (results.size() - start) + start - 1] << endl;
}

ll findResult(const vector<string> &map) {
	ll result = 0;
	for (int i = 0; i < map.size(); i++) {
		ll roundedRocks = 0;
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'O') {
				roundedRocks++;
			}
		}
		result += roundedRocks * (map.size() - i);
	}
	return result;
}

void reoganizeMap(vector<string> &map) {
	north(map);
	west(map);
	south(map);
	east(map);
}

void east(vector<string> &map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size() - 1; j++) {
			if (map[i][j] == 'O') {
				if (map[i][j + 1] == '#') {
					continue;
				}
				ll numberOfRoundedRocks = 1;
				ll newPosition = j + 1;
				while (map[i][newPosition] == 'O') {
					numberOfRoundedRocks++;
					newPosition++;
					if (newPosition >= map[i].size()) {
						break;
					}
				}
				if (newPosition >= map[i].size()) {
					continue;
				}
				if (map[i][newPosition] != '#') {
					map[i][newPosition] = 'O';
					map[i][j] = '.';
				}
			}
		}
	}
}

void south(vector<string> &map) {
	for (int i = 0; i < map.size() - 1; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'O') {
				if (map[i + 1][j] == '#') {
					continue;
				}
				ll numberOfRoundedRocks = 1;
				ll newPosition = i + 1;
				while (map[newPosition][j] == 'O') {
					numberOfRoundedRocks++;
					newPosition++;
					if (newPosition >= map.size()) {
						break;
					}
				}
				if (newPosition >= map.size()) {
					continue;
				}
				if (map[newPosition][j] != '#') {
					map[newPosition][j] = 'O';
					map[i][j] = '.';
				}
			}
		}
	}
}

void west(vector<string> &map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = map[i].size() - 1; j > 0; j--) {
			if (map[i][j] == 'O') {
				if (map[i][j - 1] == '#') {
					continue;
				}
				ll numberOfRoundedRocks = 1;
				ll newPosition = j - 1;
				while (map[i][newPosition] == 'O') {
					numberOfRoundedRocks++;
					newPosition--;
					if (newPosition < 0) {
						break;
					}
				}
				if (newPosition < 0) {
					continue;
				}
				if (map[i][newPosition] != '#') {
					map[i][newPosition] = 'O';
					map[i][j] = '.';
				}
			}
		}
	}
}

void north(vector<string> &map) {
	for (int i = map.size() - 1; i > 0; i--) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'O') {
				if (map[i - 1][j] == '#') {
					continue;
				}
				ll numberOfRoundedRocks = 1;
				ll newPosition = i - 1;
				while (map[newPosition][j] == 'O') {
					numberOfRoundedRocks++;
					newPosition--;
					if (newPosition < 0) {
						break;
					}
				}
				if (newPosition < 0) {
					continue;
				}
				if (map[newPosition][j] != '#') {
					map[newPosition][j] = 'O';
					map[i][j] = '.';
				}
			}
		}
	}
}
