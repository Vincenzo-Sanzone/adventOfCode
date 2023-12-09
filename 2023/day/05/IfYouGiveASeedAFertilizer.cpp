//
// Created by Vincenzo Sanzone on 05/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll convert(string &thisLine, vector<pll> &sourceVector, vector<pll> &destinationVector, ll actualMin);

bool isNumber(string &stringToCheck);

int main() {
	string thisLine;
	vector<pll> sourceVector;
	cin >> thisLine;
	while (cin >> thisLine && isNumber(thisLine)) {
		ll pass;
		cin >> pass;
		ll base = stoll(thisLine);
		sourceVector.push_back(pll(base, base + pass - 1));
	}
	vector<pll> destinationVector(sourceVector.size());
	cout << convert(thisLine, sourceVector, destinationVector, LONG_LONG_MAX) << endl;
}

ll convert(string &thisLine, vector<pll> &sourceVector, vector<pll> &destinationVector, ll actualMin) {
	if (thisLine == "STOP") {
		return actualMin;
	}
	actualMin = LONG_LONG_MAX;
	cin >> thisLine;
	vector<bool> done(sourceVector.size(), false);
	while (cin >> thisLine && isNumber(thisLine)) {
		ll destination, source, lenght;
		destination = stoll(thisLine.c_str());
		cin >> source >> lenght;
		ll endSource = source + lenght - 1;
		for (ll i = 0; i < sourceVector.size(); ++i) {
			ll startNumber = sourceVector[i].first;
			ll endNumber = sourceVector[i].second;

			if (startNumber > endSource || endNumber < source || done[i]) {
				continue;
			}

			if (startNumber >= source && startNumber <= endSource) {
				bool allIn = endNumber <= endSource;
				ll steps = startNumber - source;
				if (allIn) {
					destinationVector[i] = pll(destination + steps, destination + steps + (endNumber - startNumber));
				} else {
					destinationVector[i] = pll(destination + steps, destination + steps + (endSource - startNumber));
					sourceVector.push_back(make_pair(endSource + 1, endNumber));
					destinationVector.push_back(make_pair(-1, -1));
					done.push_back(false);
				}
				done[i] = true;
			} else if (source > startNumber && source < endNumber) {
				bool finishAllIn = endNumber <= endSource;

				if (finishAllIn) {
					destinationVector[i] = pll(destination, destination + (endNumber - source));
				} else {
					destinationVector[i] = pll(destination, destination + (endSource - source));
					sourceVector.push_back(make_pair(endSource + 1, endNumber));
					destinationVector.push_back(make_pair(-1, -1));
					done.push_back(false);
				}
				sourceVector.push_back(make_pair(startNumber, source - 1));
				destinationVector.push_back(make_pair(-1, -1));
				done.push_back(false);
				done[i] = true;
			}

			actualMin = min(actualMin, destinationVector[i].first);
		}

	}
	for (ll i = 0; i < sourceVector.size(); i++) {
		if (done[i]) continue;
		destinationVector[i] = sourceVector[i];
		actualMin = min(actualMin, destinationVector[i].first);
	}

	return convert(thisLine, destinationVector, sourceVector, actualMin);
}

bool isNumber(string &stringToCheck) {
	return !stringToCheck.empty() && find_if(stringToCheck.begin(),
	                                         stringToCheck.end(), [](char c) { return !isdigit(c); }) ==
	                                 stringToCheck.end();
}