//
// Created by Vincenzo Sanzone on 11/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll shortestPath(ll actualPosition, vector<pll> galaxies);

int main() {
	string line;
	ll size = 0;
	vector<pll> galaxies;
	cin >> line;
	vector<bool> hasGalaxy(line.size(), false);
	while (line != "STOP") {
		bool found = false;
		for (ll i = 0; i < line.size(); i++) {
			if (line[i] == '#') {
				hasGalaxy[i] = true;
				found = true;
				pll position = make_pair(size, i);
				galaxies.push_back(position);
			}
		}
		if (!found) {
			size += 999999;
		}
		size++;
		cin >> line;
	}

	for (ll i = 0; i < galaxies.size(); i++) {
		for (ll j = galaxies[i].second - 1; j < hasGalaxy.size(); j--) {
			if (!hasGalaxy[j]) {
				galaxies[i].second += 999999;
			}
		}
	}

	ll result = 0;
	for (ll i = 0; i < galaxies.size(); i++) {
		result += shortestPath(i, galaxies);
	}
	cout << result << endl;
}

ll shortestPath(ll actualPosition, vector<pll> galaxies) {
	ll result = 0;
	for (ll i = actualPosition + 1; i < galaxies.size(); i++) {
		ll distance = abs(galaxies[actualPosition].first - galaxies[i].first) +
		              abs(galaxies[actualPosition].second - galaxies[i].second);
		result += distance;
	}
	return result;
}
