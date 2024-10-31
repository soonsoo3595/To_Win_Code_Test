#include <bits/stdc++.h>
using namespace std;

// ������ ��Ÿ���� ����ü
struct Edge
{
	int u, v, weight;
};

int V;				// ���� ����
int E;				// ���� ����
int start;			// ���� ����

vector<Edge> holes;	// ��� ����
int dist[10];		// �ִ� ���

void BellmanFord(int start)
{
	dist[start] = 0;

	// ��� ������ V - 1�� �ݺ�
	for (int i = 0; i < V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = holes[j].u;
			int v = holes[j].v;
			int weight = holes[j].weight;

			// ���� ������ �Ÿ��� ���Ѵ밡 �ƴϰ� ���� �������� ���� ��������
			// ���� �Ÿ��� ���� ���� ������ �ִ� ��κ��� �۴ٸ� ������Ʈ
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	// ���� ����Ŭ Ȯ��
	for (int j = 0; j < E; j++)
	{
		int u = holes[j].u;
		int v = holes[j].v;
		int weight = holes[j].weight;

		// �ִ� �Ÿ� ������ �߻��Ѵٴ� ���� ���� ����Ŭ�� �������� �ǹ�
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			cout << u << "->" << v << "���� ����Ŭ �߻�\n";
			return;
		}
	}

	cout << start << "�� �������� �ִ� ��� ���\n";

	// ���
	for (int i = 1; i <= V; i++)
	{
		if(dist[i] == INT_MAX)
			cout << i << "���� ���޺Ұ�" << '\n';
		else
			cout << i << "���� " << dist[i] << '\n';
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
1�� �������� �ִ� ��� ���
1���� 0
2���� 10
3���� 20
4���� 5
*/