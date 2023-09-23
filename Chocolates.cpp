#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;
        int a[n];

        int s = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        if (s % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        int target = s / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= a[i]; j--)
            {
                dp[j] = dp[j] || dp[j - a[i]];
            }
        }

        if (dp[target])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
