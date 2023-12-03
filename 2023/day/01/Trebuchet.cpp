//
// Created by Vincenzo Sanzone on 03/12/2023.
//
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int getDigit(string stringToCheck, ll startPosition);

int main() {
	string thisLine;
	cin >> thisLine;
	ll sum = 0;
	while (!thisLine.empty()) {
		int firstDigit, lastDigit;
		firstDigit = -1;
		for (ll i = 0; i < thisLine.size(); i++) {
			int digitValue = getDigit(thisLine, i);
			if (digitValue > 0) {
				if (firstDigit == -1) {
					firstDigit = digitValue;
				}
				lastDigit = digitValue;
			}
		}
		if(firstDigit != -1){
			sum += firstDigit * 10 + lastDigit;
		}
		cin >> thisLine;
		if(thisLine == "STOP"){
			break;
		}
	}
	cout << sum << endl;
}

int getDigit(string stringToCheck, ll startPosition) {
	if(isdigit(stringToCheck[startPosition])){
		return stringToCheck[startPosition] - '0';
	}
	vector<string> possibleValues{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for(int i = 0; i < possibleValues.size(); i++){
		if(stringToCheck.substr(startPosition, possibleValues[i].size()) == possibleValues[i]){
			return i+1;
		}
	}
	return -1;
}
