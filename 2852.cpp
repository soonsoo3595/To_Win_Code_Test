#include <bits/stdc++.h>

using namespace std;

int N;
int team[3];
int second[3];

const int game = 60 * 48;

string go(int sec)
{
    string ret = "";
    
    ret += ((sec / 60) / 10) + '0';
    ret += ((sec / 60) % 10) + '0';
    ret += ":";
    ret += ((sec % 60) / 10) + '0';
    ret += ((sec % 60) % 10) + '0';

    return ret;
}

int main()
{
    cin >> N;

    bool team1 = false;
    bool team2 = false;

    while (N--)
    {
        int num;
        string time;

        cin >> num >> time;

        team[num]++;


        int sec = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 5));

        if (team[1] < team[2] && !team2)
        {
            second[2] += (game - sec);

            team1 = false;
            team2 = true;
        }
        else if (team[1] == team[2])
        {
            if (team1)
            {
                second[1] -= (game - sec);
            }
            else if (team2)
            {
                second[2] -= (game - sec);
            }

            team1 = false;
            team2 = false;
        }
        else if (team[1] > team[2] && !team1)
        {
            second[1] += (game - sec);
            team1 = true;
            team2 = false;
        }
    }

    cout << go(second[1]) << '\n';
    cout << go(second[2]) << '\n';

    return 0;
}

