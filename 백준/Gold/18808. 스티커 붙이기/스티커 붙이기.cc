#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int arr[41][41];

void Input()
{
	cin >> N >> M >> K;
}

// (y, x)에서부터 스티커를 붙일 수 있는 지 확인
bool Func1(int y, int x, vector<vector<int>>& sticker)
{
	int r = sticker.size();
	int c = sticker[0].size();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (sticker[i][j] == 0) continue; 

			int ny = y + i;
			int nx = x + j;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1)
			{
				return false;
			}
		}
	}

	return true;
}

// 배열에 스티커를 붙였음
void Func2(int y, int x, vector<vector<int>>& sticker)
{
	int r = sticker.size();
	int c = sticker[0].size();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (sticker[i][j] == 1)
			{
				arr[y + i][x + j] = 1;
			}
		}
	}
}

bool Func3(vector<vector<int>>& sticker)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Func1(i, j, sticker))
			{
				Func2(i, j, sticker);
				return true;
			}
		}
	}

	return false;
}

vector<vector<int>> Rotate(vector<vector<int>>& sticker)
{
	int r = sticker.size();
	int c = sticker[0].size();
	vector<vector<int>> temp(c, vector<int>(r));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp[j][r - i - 1] = sticker[i][j];
		}
	}

	return temp;
}

void Solve()
{
	for (int k = 0; k < K; k++)
	{
		int R, C;
		cin >> R >> C;

		vector<vector<int>> sticker;
		for (int i = 0; i < R; i++)
		{
			vector<int> v;
			for (int j = 0; j < C; j++)
			{
				int temp;
				cin >> temp;
				v.push_back(temp);
			}
			sticker.push_back(v);
		}

		// 초기 상태
		if (Func3(sticker))
		{
			continue;
		}
		
		// 90도 회전
		vector<vector<int>> sticker_90 = Rotate(sticker);
		if (Func3(sticker_90))
		{
			continue;
		}

		// 180도 회전
		vector<vector<int>> sticker_180 = Rotate(sticker_90);
		if (Func3(sticker_180))
		{
			continue;
		}

		// 270도 회전
		vector<vector<int>> sticker_270 = Rotate(sticker_180);
		if (Func3(sticker_270))
		{
			continue;
		}
	}
	
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
				count++;
		}
	}

	cout << count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}