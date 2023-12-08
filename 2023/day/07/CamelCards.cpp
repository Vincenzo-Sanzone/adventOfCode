//
// Created by Vincenzo Sanzone on 07/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

short getRank(string hand);

ll getPoints(priority_queue<tuple<short, ll, string>> &allHands);

ll getPointsOfARank(vector<pair<string, ll>> &bestHands, ll &numberOfHands);

void radixSort(vector<pair<string, ll>> &toOrder);

int main() {
	string hand;
	ll bid;
	priority_queue<tuple<short, ll, string>> allHandsRanked;

	while (cin >> hand && hand != "STOP") {
		cin >> bid;
		short rank = getRank(hand);
		allHandsRanked.push(make_tuple(rank, bid, hand));
	}
	cout << getPoints(allHandsRanked) << endl;

}

ll getPoints(priority_queue<tuple<short, ll, string>> &allHands) {
	ll numberOfHands = allHands.size();
	ll points = 0;
	short actualRank = get<0>(allHands.top());
	while (!allHands.empty()) {
		vector<pair<string, ll>> bestHands;
		while (!allHands.empty() && actualRank == get<0>(allHands.top())) {
			bestHands.push_back(make_pair(get<2>(allHands.top()), get<1>(allHands.top())));
			allHands.pop();
		}
		points += getPointsOfARank(bestHands, numberOfHands);
		actualRank = get<0>(allHands.top());
	}
	return points;
}

ll getPointsOfARank(vector<pair<string, ll>> &bestHands, ll &numberOfHands) {
	radixSort(bestHands);
	ll points = 0;
	for (int i = 0; i < bestHands.size(); i++) {
		points += bestHands[i].second * numberOfHands;
		numberOfHands--;
	}
	return points;
}

void radixSort(vector<pair<string, ll>> &toOrder) {
	vector<char> cards{'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4',
	                   '3', '2', 'J'};
	int maxLen = toOrder[0].first.size();
	for (int i = maxLen - 1; i >= 0; i--) {
		vector<pair<string, ll>> ordered;
		vector<int> occurrences(13, 0);
		for (int j = 0; j < toOrder.size(); j++) {
			int posValue = find(cards.begin(), cards.end(), toOrder[j].first[i]) - cards.begin();
			occurrences[posValue]++;
		}
		for (int j = 0; j < occurrences.size(); j++) {
			for (int k = 0; k < toOrder.size(); k++) {
				if (toOrder[k].first[i] == cards[j]) {
					ordered.push_back(toOrder[k]);
				}
			}
		}
		toOrder = ordered;
	}
}

short getRank(string hand) {
	vector<char> cards{'J', '2', '3', '4', '5', '6', '7', '8', '9', 'T',
	                   'Q', 'K', 'A'};
	vector<short> occurrences(13, 0);
	bool pair, tris, poker, doublePair;
	for (int i = 0; i < hand.size(); i++) {
		int posValue = find(cards.begin(), cards.end(), hand[i]) - cards.begin();
		occurrences[posValue]++;
		if(posValue == 0) continue;
		if (occurrences[posValue] == 5) return 6;
		if (occurrences[posValue] == 4) poker = true;
		if (occurrences[posValue] == 3) tris = true;
		if (occurrences[posValue] == 2 && pair) doublePair = true;
		if (occurrences[posValue] == 2) pair = true;
	}
	if((tris && occurrences[0] == 2) || (poker && occurrences[0] == 1) || (pair && occurrences[0] == 3) || occurrences[0] == 5 || occurrences[0] == 4) return 6;
	if((tris && occurrences[0] == 1) || (pair && occurrences[0] == 2) || occurrences[0] == 3) return 5;
	if((doublePair && occurrences[0] == 1)) return 4;
	if((pair && occurrences[0] == 1) || occurrences[0] == 2) return 3;
	if(occurrences[0] == 1) return 1;
	if (poker) return 5;
	if (doublePair && tris) return 4;
	if (tris) return 3;
	if (doublePair) return 2;
	if (pair) return 1;
	return 0;
}
