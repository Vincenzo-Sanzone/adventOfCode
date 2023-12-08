//
// Created by Vincenzo Sanzone on 08/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, string> pss;

int main(){
	string map;
	cin >> map;
	unordered_map<string, pss> instructions;
	string keyName;
	while (cin >> keyName && keyName != "STOP") {
		string equals, left, right;
		cin >> equals >> left >> right;
		instructions[keyName] = pss(left.substr(1, left.size()-2), right.substr(0, right.size()-1));
	}
	ll pass = 0;
	ll actualInstruction = 0;
	string actualPosition = "AAA";
	while(actualPosition != "ZZZ"){
		pss movies= instructions[actualPosition];
		if(map[actualInstruction] == 'L'){
			actualPosition = movies.first;
		}
		else{
			actualPosition = movies.second;
		}
		pass++;
		actualInstruction++;
		if(actualInstruction == map.size()) actualInstruction = 0;
	}
	cout << pass << endl;
}