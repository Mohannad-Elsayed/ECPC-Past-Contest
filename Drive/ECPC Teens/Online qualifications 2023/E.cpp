#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                int p1 = 0;
                string s = "";
                s.push_back(i + '0');
                s.push_back(j + '0');
                s.push_back(k + '0');
                for (int i = 0; i < x.size(); i++)
                {
                    if (p1 < 3 && s[p1] == x[i])
                        p1++;
                }
                if (p1 == 3)
                    ans++;
            }
        }
    }
    cout << ans << "\n";
}
