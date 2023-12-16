//
// Created by Vincenzo Sanzone on 16/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void reoganizeMap(vector<string> &map);

int main() {
	vector<string> map;
	string line;
	while (cin >> line && line != "STOP") {
		map.push_back(line);
	}
	reoganizeMap(map);
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
	cout << result << endl;
}

void reoganizeMap(vector<string> &map) {
	for (int i = map.size() - 1; i > 0; i--) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'O') {
				if(map[i-1][j] == '#'){
					continue;
				}
				ll numberOfRoundedRocks = 1;
				ll newPosition = i-1;
				while(map[newPosition][j] == 'O'){
					numberOfRoundedRocks++;
					newPosition--;
					if(newPosition < 0){
						break;
					}
				}
				if(newPosition < 0){
					continue;
				}
				if(map[newPosition][j] != '#'){
					map[newPosition][j] = 'O';
					map[i][j] = '.';
				}
			}
		}
	}
}
