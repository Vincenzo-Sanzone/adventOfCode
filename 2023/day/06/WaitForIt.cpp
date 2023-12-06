//
// Created by Vincenzo Sanzone on 06/12/2023.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	string thisLine;
	cin >> thisLine;
	ll time = 0;
	while (cin >> thisLine && thisLine != "Distance:") {
		ll tmp = atoll(thisLine.c_str());
		ll size = 0;
		for (; tmp != 0; size++, tmp /= 10);
		time = time * pow(10, size) + atoll(thisLine.c_str());
	}
	ll distances = 0;
	while (cin >> thisLine && thisLine != "STOP") {
		ll tmp = atoll(thisLine.c_str());
		ll size = 0;
		for (; tmp != 0; size++, tmp /= 10);
		distances = distances * pow(10, size) + atoll(thisLine.c_str());
	}

	ll result = 0;

	for (ll i = 0; i < time; i++) {
		if (i * (time - i) > distances) {
			result++;
		} else if (result > 0) {
			break;
		}
	}
	cout << result << endl;
}