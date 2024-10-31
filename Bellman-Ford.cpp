#include <bits/stdc++.h>
using namespace std;

// 간선을 나타내는 구조체
struct Edge
{
	int u, v, weight;
};

int V;				// 정점 개수
int E;				// 간선 개수
int start;			// 시작 정점

vector<Edge> holes;	// 모든 간선
int dist[10];		// 최단 경로

void BellmanFord(int start)
{
	dist[start] = 0;

	// 모든 간선을 V - 1번 반복
	for (int i = 0; i < V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = holes[j].u;
			int v = holes[j].v;
			int weight = holes[j].weight;

			// 현재 정점의 거리가 무한대가 아니고 현재 정점에서 다음 정점으로
			// 가는 거리의 합이 다음 정점의 최단 경로보다 작다면 업데이트
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	// 음수 사이클 확인
	for (int j = 0; j < E; j++)
	{
		int u = holes[j].u;
		int v = holes[j].v;
		int weight = holes[j].weight;

		// 최단 거리 갱신이 발생한다는 것은 음수 사이클이 존재함을 의미
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			cout << u << "->" << v << "에서 사이클 발생\n";
			return;
		}
	}

	cout << start << "번 정점부터 최단 경로 출력\n";

	// 출력
	for (int i = 1; i <= V; i++)
	{
		if(dist[i] == INT_MAX)
			cout << i << "까지 도달불가" << '\n';
		else
			cout << i << "까지 " << dist[i] << '\n';
	}
}

int main()
{
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		holes.push_back({ u, v, weight });
	}

	cin >> start;

	fill(dist, dist + 10, INT_MAX);

	BellmanFord(start);
}

/*
Input
4
5
1 2 10
1 3 20
1 4 15
2 4 10
3 4 -15
1

Output
1번 정점부터 최단 경로 출력
1까지 0
2까지 10
3까지 20
4까지 5
*/