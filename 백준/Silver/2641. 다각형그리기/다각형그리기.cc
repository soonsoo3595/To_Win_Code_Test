#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

bool visited[100][100];

set<string>path;
int N;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void DFS(int y, int x, int cnt, string route) {	
	if (cnt == N) {		
		path.insert(route);
		return;
	}
	for (int idx = 0; idx < 4; ++idx) {
		int ny = y + dy[idx];
		int nx = x + dx[idx];
		if (visited[ny][nx] == false) continue;
		visited[ny][nx] = false;
		DFS(ny, nx, cnt + 1, route + to_string(idx + 1));
		visited[ny][nx] = true;
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	char input(' ');
	string origin("");
	for (int idx = 0; idx < N; ++idx) {
		cin >> input;
		origin += input;
	}

	int M(0);
	cin >> M;

	int y = 50;
	int x = 50;

	for (int idx = 0; idx < N; ++idx) {
		int dir = origin[idx] - '0' - 1;
		y += dy[dir];
		x += dx[dir];
		visited[y][x] = true;
	}

	for (y = 0; y < 100; ++y) {
		for (x = 0; x < 100; ++x) {
			if (visited[y][x] == true) {
				DFS(y, x, 0, "");
			}
		}
	}

	vector<string>answer;
	for (int idx = 0; idx < M; ++idx) {
		string str("");
		for (int idx2 = 0; idx2 < N; ++idx2) {
			cin >> input;
			str += input;
		}
		if (path.find(str) != path.end()) {
			answer.push_back(str);
		}
	}

	cout << answer.size() << '\n';
	for (int path_idx = 0; path_idx < answer.size(); ++path_idx) {
		for (int idx = 0; idx < answer[path_idx].size(); ++idx) {
			cout << answer[path_idx][idx] << ' ';
		}
		cout << '\n';
	}
}