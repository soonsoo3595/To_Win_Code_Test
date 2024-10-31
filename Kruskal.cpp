#include <bits/stdc++.h>
using namespace std;

// 간선을 나타내는 구조체
struct Edge
{
	int u, v, weight;
};

int V;				// 정점 개수
int parent[10];		// 어떤 정점의 부모 정점
int height[10];		// 높이(최적화용)

vector<Edge> holes;	// 모든 간선
vector<Edge> MST;	// MST의 집합

// 가중치를 기준으로 오름차순
bool Compare(Edge& e1, Edge& e2)
{
	return e1.weight < e2.weight;
}

// 경로 압축을 적용해 부모 정점을 빠르게 찾는다
int Find(int u)
{
	if (u == parent[u]) return u;

	return parent[u] = Find(parent[u]);
}

// 두 정점을 합친다
// 높이가 낮은 쪽이 높이가 높은쪽으로 들어간다
void Union(int u, int v)
{
	int pu = Find(u);
	int pv = Find(v);

	if (pu != pv)
	{
		if (height[pu] > height[pv])
		{
			parent[pv] = pu;
		}
		else if (height[pu] < height[pv])
		{
			parent[pu] = pv;
		}
		else
		{
			parent[pv] = pu;
			height[pv]++;
		}
	}
}

int main()
{
	V = 4;

	holes.push_back({ 1, 2, 1 });
	holes.push_back({ 1, 3, 2 });
	holes.push_back({ 1, 4, 5 });
	holes.push_back({ 2, 4, 3 });
	holes.push_back({ 3, 4, 4 });

	sort(holes.begin(), holes.end(), Compare);

	// 부모 노드 자기 자신으로 초기화
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}

	// 간선을 순회하며 사이클이 생성되는지 체크 후 
	// 두 정점을 연결하고 MST에 간선을 추가한다
	for (auto& edge : holes)
	{
		int u = edge.u;
		int v = edge.v;
		int weight = edge.weight;

		if (Find(u) != Find(v))
		{
			Union(u, v);
			MST.push_back(edge);
		}
	}

	for (auto& edge : MST)
	{
		cout << edge.u << "->" << edge.v << " : " << edge.weight << '\n';
	}
}

/*
1->2 : 1
1->3 : 2
2->4 : 3
*/