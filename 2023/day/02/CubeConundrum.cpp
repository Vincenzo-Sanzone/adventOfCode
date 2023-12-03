//
// Created by Vincenzo Sanzone on 03/12/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
	string thisLine;
	cin >> thisLine;
	int sum = 0;
	while (!thisLine.empty()) {
		cin >> thisLine >> thisLine;
		int actualBlue, actualGreen, actualRed;
		int atLeastBlue, atLeastGreen, atLeastRed;
		actualBlue = actualGreen = actualRed = atLeastBlue = atLeastGreen = atLeastRed = 0;
		while (thisLine != "Game" && thisLine != "STOP") {
			int value = stoi(thisLine.substr(0, thisLine.size()));
			cin >> thisLine;
			if (thisLine.substr(0, thisLine.size() - 1) == "blue" || thisLine == "blue") {
				actualBlue += value;
			} else if (thisLine.substr(0, thisLine.size() - 1) == "green" || thisLine == "green") {
				actualGreen += value;
			} else if (thisLine.substr(0, thisLine.size() - 1) == "red" || thisLine == "red") {
				actualRed += value;
			}
			if (thisLine.substr(thisLine.size() - 1, thisLine.size()) != ",") {
				atLeastBlue = max(actualBlue, atLeastBlue);
				atLeastGreen = max(actualGreen, atLeastGreen);
				atLeastRed = max(actualRed, atLeastRed);
				actualBlue = actualGreen = actualRed = 0;
			}
			cin >> thisLine;
		}
		sum += atLeastBlue * atLeastGreen * atLeastRed;
		if (thisLine == "STOP") {
			break;
		}
	}
	cout << sum << endl;
}