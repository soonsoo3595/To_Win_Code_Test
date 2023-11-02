#include <bits/stdc++.h>

using namespace std;

int N;
deque<int> dq;
deque<char> dq2;

int Cal(int n1, int n2, char op)
{
    switch (op)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
	    return n1 * n2; 
    }
}



int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;

        if(c - '0' >= 0 && c - '0' <= 9)
			dq.push_back(c - '0');
		else
			dq2.push_back(c);
    }

    while (dq.size() >= 2)
    {
        int n1 = dq.front(); dq.pop_front();
        int n2 = dq.front(); dq.pop_front();
        char op1 = dq2.front(); dq2.pop_front();

        if (dq.empty())
        {
            dq.push_front(Cal(n1, n2, op1));
			break;
		}

        int n3 = dq.front(); dq.pop_front();
        char op2 = dq2.front(); dq2.pop_front();

        cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << op1 << ' ' << op2 << '\n';

        int ret1 = Cal(Cal(n1, n2, op1), n3, op2);
        int ret2 = Cal(n1, Cal(n2, n3, op2), op1);

        int tmp = max(ret1, ret2);

        cout << ret1 << ' ' << ret2 << ' ' << tmp << '\n';

        dq.push_front(tmp);
    }

    cout << dq.front() << '\n';

    return 0;
}

