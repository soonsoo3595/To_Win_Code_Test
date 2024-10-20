#include <bits/stdc++.h>

using namespace std;

int N;
vector<char> nodes[30];

void FirstSearch(char node)
{
    if (node == '.')
        return;

    cout << node;
    FirstSearch(nodes[node - 'A'][0]);
    FirstSearch(nodes[node - 'A'][1]);
}

void MiddleSearch(char node)
{
    if (node == '.')
        return;

    MiddleSearch(nodes[node - 'A'][0]);
    cout << node;
    MiddleSearch(nodes[node - 'A'][1]);
}

void LastSearch(char node)
{
    if (node == '.')
        return;

    LastSearch(nodes[node - 'A'][0]);
    LastSearch(nodes[node - 'A'][1]);
    cout << node;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char data, left, right;
        cin >> data >> left >> right;

        nodes[data - 'A'].push_back(left);
        nodes[data - 'A'].push_back(right);
    }

    FirstSearch('A'); cout << '\n';
    MiddleSearch('A'); cout << '\n';
    LastSearch('A'); cout << '\n';

    return 0;
}

