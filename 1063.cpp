#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;

string dol, king;

int dy[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int Translate(string move)
{
	if (move == "R")
	{
		return 0;
	}
	else if (move == "L")
	{
		return 1;
	}
	else if (move == "B")
	{
		return 2;
	}
	else if (move == "T")
	{
		return 3;
	}
	else if (move == "RT")
	{
		return 4;
	}
	else if (move == "LT")
	{
		return 5;
	}
	else if (move == "RB")
	{
		return 6;
	}
	else if (move == "LB")
	{
		return 7;
	}
}

void Move(string move)
{
	string newKing = "";
	int y = king[1] - '0';
	int x = king[0] - 'A';
	int ny, nx;

	int dir = Translate(move);
	ny = y + dy[dir];
	nx = x + dx[dir];

	if (ny <= 0 || nx < 0 || ny > MAX || nx >= MAX) return;

	newKing += (char)(nx + 'A');
	newKing += (char)(ny + '0');
	
	if (newKing == dol)
	{
		string newDol = "";

		int y = dol[1] - '0';
		int x = dol[0] - 'A';

		ny = y + dy[dir];
		nx = x + dx[dir];

		if (ny <= 0 || nx < 0 || ny > MAX || nx >= MAX) return;

		newDol += (char)(nx + 'A');
		newDol += (char)(ny + '0');

		king = newKing;
		dol = newDol;
	}
	else
	{
		king = newKing;
	}
}

int main()
{
	int N;

	cin >> king >> dol >> N;

	while (N--)
	{
		string move;
		cin >> move;

		Move(move);
	}

	cout << king << '\n';
	cout << dol << '\n';

    return 0;
}

