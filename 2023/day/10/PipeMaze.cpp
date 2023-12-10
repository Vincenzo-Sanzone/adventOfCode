//
// Created by vsanz on 10/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void
updateGraph(const vector<string> &map, vector<vector<ll>> &graph, pair<ll, ll> &startingPosition, int row, int column);

void
changeStartingPosition(vector<string> &map, vector<vector<ll>> &graph, pair<ll, ll> &startingPosition, char &newPipe);

void doUpdate(const vector<string> &map, vector<vector<ll>> &graph, int row, int column);

void deleteEdge(vector<vector<ll>> &graph, ll position);

ll bfs(vector<vector<ll>> &graph, ll start);

bool isLegalPipe(vector<vector<ll>> &graph, ll &start, ll &arrive);

int main() {
	string line;
	vector<string> map;
	while (cin >> line && line != "STOP") {
		map.push_back(line);
	}

	vector<vector<ll>> graph(map.size() * map[0].size());
	pair<ll, ll> startingPosition;
	for (int i = 0; i < map.size(); i++) {
		line = map[i];
		for (int j = 0; j < line.size(); j++) {
			updateGraph(map, graph, startingPosition, i, j);
		}
	}

	ll result = 0;
	vector<char> possibleSubstitutions{'|', '-', 'L', '7', 'J', 'F'};
	for (int i = 0; i < possibleSubstitutions.size(); i++) {
		changeStartingPosition(map, graph, startingPosition, possibleSubstitutions[i]);
		result = bfs(graph, startingPosition.first * map[0].size() + startingPosition.second);
		deleteEdge(graph, startingPosition.first * map[0].size() + startingPosition.second);
		if (result != 0) {
			break;
		}
	}
	cout << result << endl;
}

ll bfs(vector<vector<ll>> &graph, ll start) {
	vector<ll> distance(graph.size(), LONG_LONG_MAX);
	distance[start] = 0;
	queue<ll> queue;
	queue.push(start);
	ll maxDistance = 0;
	while (!queue.empty()) {
		ll actual = queue.front();
		queue.pop();
		for (int i = 0; i < graph[actual].size(); i++) {
			if(!isLegalPipe(graph, actual, graph[actual][i])){
				return 0;
			}
			if (distance[graph[actual][i]] == LONG_LONG_MAX) {
				distance[graph[actual][i]] = distance[actual] + 1;
				queue.push(graph[actual][i]);
			} else if (distance[graph[actual][i]] < distance[actual] ) {
				continue;
			} else {
				return distance[actual] + 1;
			}
		}
	}
	return maxDistance;
}

bool isLegalPipe(vector<vector<ll>> &graph, ll &start, ll &arrive) {
	for(int i = 0; i < graph[arrive].size(); i++) {
		if(graph[arrive][i] == start) {
			return true;
		}
	}
	return false;
}

void deleteEdge(vector<vector<ll>> &graph, ll position) {
	int size = graph[position].size();
	for (int i = 0; i < size; i++) {
		graph[position].pop_back();
	}
}

void
changeStartingPosition(vector<string> &map, vector<vector<ll>> &graph, pair<ll, ll> &startingPosition, char &newPipe) {
	map[startingPosition.first][startingPosition.second] = newPipe;
	doUpdate(map, graph, startingPosition.first, startingPosition.second);
}

void
updateGraph(const vector<string> &map, vector<vector<ll>> &graph, pair<ll, ll> &startingPosition, int row, int column) {
	string line = map[row];
	if (line[column] == 'S') {
		startingPosition = make_pair(row, column);
		return;
	}
	doUpdate(map, graph, row, column);
}

void doUpdate(const vector<string> &map, vector<vector<ll>> &graph, int row, int column) {
	string line = map[row];
	ll position = row * line.size() + column;
	if (line[column] == 'F') {
		if (row == map.size() - 1 || column == line.size() - 1) {
			line[column] = '.';
		} else {
			graph[position].push_back(position + line.size());
			graph[position].push_back(position + 1);
		}
	} else if (line[column] == 'L') {
		if (row == 0 || column == line.size() - 1) {
			line[column] = '.';
		} else {
			graph[position].push_back(position - line.size());
			graph[position].push_back(position + 1);
		}
	} else if (line[column] == '7') {
		if (row == map.size() - 1 || column == 0) {
			line[column] = '.';
		} else {
			graph[position].push_back(position + line.size());
			graph[position].push_back(position - 1);
		}
	} else if (line[column] == 'J') {
		if (row == 0 || column == 0) {
			line[column] = '.';
		} else {
			graph[position].push_back(position - line.size());
			graph[position].push_back(position - 1);
		}
	} else if (line[column] == '|') {
		if (row == 0 || row == map.size() - 1) {
			line[column] = '.';
		} else {
			graph[position].push_back(position - line.size());
			graph[position].push_back(position + line.size());
		}
	} else if (line[column] == '-') {
		if (column == 0 || column == line.size() - 1) {
			line[column] = '.';
		} else {
			graph[position].push_back(position - 1);
			graph[position].push_back(position + 1);
		}
	}
}
