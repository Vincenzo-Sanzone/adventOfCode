//
// Created by Vincenzo Sanzone on 05/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int convert(string &thisLine, vector<ll> &sourceVector, vector<ll> &destinationVector, ll actualMin);

bool isNumber(string &stringToCheck);

int main(){
	string thisLine;
	vector<ll> sourceVector;
	cin >> thisLine;
	while(cin >> thisLine && isNumber(thisLine)){
		sourceVector.push_back(atoll(thisLine.c_str()));
	}
	vector<ll> destinationVector(sourceVector.size());
	cout << convert(thisLine, sourceVector, destinationVector, LONG_LONG_MAX) << endl;

}

int convert(string &thisLine, vector<ll> &sourceVector, vector<ll> &destinationVector, ll actualMin) {
	if(thisLine == "STOP"){
		return actualMin;
	}
	actualMin = LONG_LONG_MAX;
	cin >> thisLine;
	while (cin>> thisLine && isNumber(thisLine)) {
		ll destination, source, steps;
		destination = atoll(thisLine.c_str());
		cin  >> source >> steps;
		for (ll i = 0; i < sourceVector.size(); i++) {
			if (sourceVector[i] >= source && sourceVector[i] <= source + steps - 1) {
				ll usedSteps = sourceVector[i] - source;
				ll newDestination = destination + usedSteps;
				destinationVector[i] = newDestination;
				sourceVector[i] = -1;
				actualMin = min(actualMin, newDestination);
			}
		}
		for (int i = 0; i < sourceVector.size(); i++) {
			if (sourceVector[i] != -1) {
				destinationVector[i] = sourceVector[i];
				actualMin = min(actualMin, sourceVector[i]);
			}
		}
	}
	return convert(thisLine, destinationVector, sourceVector, actualMin);
}

bool isNumber(string &stringToCheck) {
	return !stringToCheck.empty() && find_if(stringToCheck.begin(),
											 stringToCheck.end(), [](char c) { return !isdigit(c); }) == stringToCheck.end();
}