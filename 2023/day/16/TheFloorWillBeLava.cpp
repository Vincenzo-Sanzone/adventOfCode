//
// Created by Vincenzo Sanzone on 16/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll energize(vector<string> &map, vector<vector<vector<bool>>> &memo, ll actualRow, ll actualColumn, short direction);

bool alreadyVisited(vector<bool> &memo);

int main() {
	vector<string> map;
	string line;
	while (cin >> line && line != "STOP") {
		map.push_back(line);
	}
	vector<vector<vector<bool>>> memo(map.size(), vector<vector<bool>>(map[0].size(), vector<bool>(4, false)));
	cout << energize(map, memo, 0, 0, 0) << endl;
}


ll energize(vector<string> &map, vector<vector<vector<bool>>> &memo, ll actualRow, ll actualColumn, short direction) {
	if (actualRow < 0 || actualRow >= map.size() || actualColumn < 0 || actualColumn >= map[0].size()) {
		return 0;
	}
	if (memo[actualRow][actualColumn][direction]) {
		return 0;
	}
	ll result = alreadyVisited(memo[actualRow][actualColumn]) ? 0 : 1;
	memo[actualRow][actualColumn][direction] = true;
	char tile = map[actualRow][actualColumn];
	if (tile == '|' && (direction == 0 || direction == 2)) {
		result += energize(map, memo, actualRow + 1, actualColumn, 1);
		result += energize(map, memo, actualRow - 1, actualColumn, 3);
	} else if (tile == '-' && (direction == 1 || direction == 3)) {
		result += energize(map, memo, actualRow, actualColumn + 1, 0);
		result += energize(map, memo, actualRow, actualColumn - 1, 2);
	} else if (tile == '/') {
		if (direction == 0) {
			result += energize(map, memo, actualRow - 1, actualColumn, 3);
		} else if (direction == 1) {
			result += energize(map, memo, actualRow, actualColumn - 1, 2);
		} else if (direction == 2) {
			result += energize(map, memo, actualRow + 1, actualColumn, 1);
		} else if (direction == 3) {
			result += energize(map, memo, actualRow, actualColumn + 1, 0);
		}
	} else if (tile == '\\') {
		if (direction == 0) {
			result += energize(map, memo, actualRow + 1, actualColumn, 1);
		} else if (direction == 1) {
			result += energize(map, memo, actualRow, actualColumn + 1, 0);
		} else if (direction == 2) {
			result += energize(map, memo, actualRow - 1, actualColumn, 3);
		} else if (direction == 3) {
			result += energize(map, memo, actualRow, actualColumn - 1, 2);
		}
	} else {
		if (direction == 0) {
			result += energize(map, memo, actualRow, actualColumn + 1, 0);
		} else if (direction == 1) {
			result += energize(map, memo, actualRow + 1, actualColumn, 1);
		} else if (direction == 2) {
			result += energize(map, memo, actualRow, actualColumn - 1, 2);
		} else if (direction == 3) {
			result += energize(map, memo, actualRow - 1, actualColumn, 3);
		}
	}
	return result;
}

bool alreadyVisited(vector<bool> &memo) {
	return memo[0] || memo[1] || memo[2] || memo[3];
}