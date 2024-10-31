#include <bits/stdc++.h>
using namespace std;

// ������ ��Ÿ���� ����ü
struct Edge
{
	int u, v, weight;
};

int V;				// ���� ����
int parent[10];		// � ������ �θ� ����
int height[10];		// ����(����ȭ��)

vector<Edge> holes;	// ��� ����
vector<Edge> MST;	// MST�� ����

// ����ġ�� �������� ��������
bool Compare(Edge& e1, Edge& e2)
{
	return e1.weight < e2.weight;
}

// ��� ������ ������ �θ� ������ ������ ã�´�
int Find(int u)
{
	if (u == parent[u]) return u;

	return parent[u] = Find(parent[u]);
}

// �� ������ ��ģ��
// ���̰� ���� ���� ���̰� ���������� ����
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

	// �θ� ��� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}

	// ������ ��ȸ�ϸ� ����Ŭ�� �����Ǵ��� üũ �� 
	// �� ������ �����ϰ� MST�� ������ �߰��Ѵ�
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