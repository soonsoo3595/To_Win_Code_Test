#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
};

int N, M;
vector<Edge> adj[100001];
int startNode, endNode;
vector<bool> visited;

bool CanGo(int weight, int node) {
    if (node == endNode) return true;
    visited[node] = true;

    for (Edge& edge : adj[node]) {
        if (!visited[edge.to] && edge.weight >= weight) {
            if (CanGo(weight, edge.to)) return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int maxW = 0;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
        maxW = max(maxW, c);
    }

    cin >> startNode >> endNode;

    int left = 1, right = maxW, answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        visited.assign(N + 1, false);

        if (CanGo(mid, startNode)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';
}