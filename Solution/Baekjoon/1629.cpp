#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long go(long long a, long long b, int depth = 0)
{
    // Print a debug message to show the depth of recursion
    cout << "Depth " << depth << ": Calling go(a=" << a << ", b=" << b << ")" << endl;

    if (b == 1)
    {
        cout << "Depth " << depth << ": Base case reached. Returning " << a % c << endl;
        return a % c;
    }

    long long ret = go(a, b / 2, depth + 1); // Recursive call

    // Combine the solutions of subproblems
    ret = (ret * ret) % c;
    cout << "Depth " << depth << ": After squaring: ret=" << ret << endl;

    // If b is odd, multiply by a once more
    if (b % 2)
    {
        ret = (ret * a) % c;
        cout << "Depth " << depth << ": After multiplying by a: ret=" << ret << endl;
    }

    cout << "Depth " << depth << ": Returning " << ret << endl;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    // Call the divide and conquer function to compute a^b % c
    cout << go(a, b);
}