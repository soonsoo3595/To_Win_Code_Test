#include <bits/stdc++.h>
using namespace std;

int N;
int mp, mf, ms, mv;
int answer = INT_MAX;
vector<vector<int>> answer_vector;

struct Ingredient
{
    int p;
    int f;
    int s;
    int v;
    int c;
};
vector<Ingredient> v;
vector<int> combi;

void Input()
{
    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < N; i++)
    {
        int pi, fi, si, vi, ci;
        cin >> pi >> fi >> si >> vi >> ci;
        v.push_back({ pi, fi, si, vi, ci });
    }
}

bool Check()
{
    int sp = 0, sf = 0, ss = 0, sv = 0;

    for (int idx : combi)
    {
        sp += v[idx].p;
        sf += v[idx].f;
        ss += v[idx].s;
        sv += v[idx].v;
    }

    if (sp < mp || sf < mf || ss < ms || sv < mv) return false;

    return true;
}

int Cost()
{
    int cost = 0;

    for (int idx : combi)
    {
        cost += v[idx].c;
    }

    return cost;
}

void Func(int start, int depth)
{
    if (Cost() > answer) return;

    if (depth == combi.size())
    {
        if (Check())
        {
            int cost = Cost();
            if (answer > cost)
            {
                answer = cost;

                answer_vector.clear();
                answer_vector.push_back(combi);
            }
            else if (answer == cost)
            {
                answer_vector.push_back(combi);
            }
        }
        return;
    }

    for (int i = start; i < N; i++)
    {
        combi.push_back(i);
        Func(i + 1, depth);
        combi.pop_back();
    }
}

void Solve()
{
    for (int i = 1; i <= N; i++)
    {
        Func(0, i);
    }

    if (answer_vector.empty())
    {
        cout << -1;
    }
    else
    {
        cout << answer << '\n';

        sort(answer_vector.begin(), answer_vector.end());

        for (int idx : answer_vector[0])
        {
            cout << idx + 1 << ' ';
        }
    }
}

int main()
{
    Input();

    Solve();

    return 0;
}