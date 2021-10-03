class Solution
{
public:
    int longestCommonSubsequence(string a1, string b1)
    {

        int n, m;
        n = a1.length();
        m = b1.length();

        int t[n + 1][m + 1];
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a1[i - 1] == b1[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[n][m];
    }
};