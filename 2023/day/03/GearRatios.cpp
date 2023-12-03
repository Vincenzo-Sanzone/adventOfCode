//
// Created by Vincenzo Sanzone on 03/12/2023.
//

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll getAllNumbers(vector<string>& engine, int engineRow, int engineCol);

ll countFrom(vector<string> &engine, int engineRow, int engineCol);

ll getNumber(vector<string> &engine, int engineRow, int engineCol);

void updateValue(ll &first, ll &second, ll functionResult);

int main() {
	string thisLine;
	vector<string> engine;
	while (cin >> thisLine && thisLine != "STOP") {
		engine.push_back(thisLine);
	}
	ll result = 0;
	for(int engineSize = 0; engineSize < engine.size(); engineSize++) {
		thisLine = engine[engineSize];
		for (int i = 0; i < thisLine.size(); i++) {
			if (thisLine[i] == '*') {
				result += getAllNumbers(engine, engineSize, i);
			}
		}
	}
	cout << result << endl;
}

ll getAllNumbers(vector<string>& engine, int engineRow, int engineCol) {
	ll firstValue, secondValue, tmp;
	firstValue = secondValue = 0;
	tmp = countFrom(engine, engineRow + 1, engineCol + 1);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow + 1, engineCol - 1);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow - 1, engineCol + 1);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow - 1, engineCol - 1);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow + 1, engineCol);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow - 1, engineCol);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow, engineCol + 1);
	updateValue(firstValue, secondValue, tmp);
	tmp = countFrom(engine, engineRow, engineCol - 1);
	updateValue(firstValue, secondValue, tmp);
	return firstValue * secondValue;
}

void updateValue(ll &first, ll &second, ll functionResult) {
	if(functionResult != 0) {
		if (first == 0) {
			first = functionResult;
		} else {
			second = functionResult;
		}
	}
}

ll countFrom(vector<string> &engine, int engineRow, int engineCol) {
	if(engineRow < 0 || engineRow >= engine.size() || engineCol < 0 || engineCol >= engine[0].size()){
		return 0;
	}
	if(isdigit(engine[engineRow][engineCol])){
		return getNumber(engine, engineRow, engineCol);
	}
	return 0;
}

ll getNumber(vector<string> &engine, int engineRow, int engineCol) {
	int sum = 0;
	string thisLine = engine[engineRow];
	int toReverse = 0;
	int size = 0;
	for(int i = engineCol; i >= 0 && isdigit(thisLine[i]); i--){
		engine[engineRow][i] = '.';
		toReverse = toReverse * 10 + thisLine[i] - '0';
		size++;
	}
	for(int i = 0; i < size; i++){
		sum = sum * 10 + toReverse % 10;
		toReverse /= 10;
	}
	for(int i = engineCol + 1; i < thisLine.size() && isdigit(thisLine[i]); i++){
		engine[engineRow][i] = '.';
		sum = sum * 10 + thisLine[i] - '0';
	}
	return sum;
}