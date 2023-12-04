//
// Created by Vincenzo Sanzone on 04/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	string thisLine;
	int sum = 0;
	cin >> thisLine;
	vector<int> istances;
	while (thisLine != "STOP") {
		map<int, int> cards;
		cin >> thisLine;
		int actualCard = stoi(thisLine.substr(0, thisLine.size() - 1));
		if (actualCard > istances.size()) {
			istances.push_back(1);
		}
		while (cin >> thisLine && thisLine != "|") {
			int card = stoi(thisLine);
			cards.insert(pair<int, int>(card, 1));
		}
		int points = 0;
		while (cin >> thisLine && thisLine != "Card" && thisLine != "STOP") {
			int card = stoi(thisLine);
			if (cards.find(card) != cards.end()) {
				points++;
				if (actualCard + points > istances.size()) {
					istances.push_back(istances[actualCard - 1] + 1);
				} else {
					istances[actualCard + points - 1] += istances[actualCard - 1];
				}
			}
		}
		sum += istances[actualCard - 1];
	}
	cout << sum << endl;
	return 0;
}