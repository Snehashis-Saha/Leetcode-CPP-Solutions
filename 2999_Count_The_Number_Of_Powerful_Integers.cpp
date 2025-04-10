class Solution {
public:
    string t, s;
    int limit;
    long long dp[20];

    long long dfs(int pos, bool tight) {
        if ((int)t.size() < (int)s.size()) return 0;

        if (!tight && dp[pos] != -1) return dp[pos];

        if (pos <= t.size() && (int)t.size() - pos == (int)s.size()) {
            string suffix = t.substr(pos);
            if (tight) return (suffix >= s ? 1 : 0);
            return 1;
        }

        long long ans = 0;
        int upper = tight ? t[pos] - '0' : 9;
        upper = min(upper, limit);

        for (int d = 0; d <= upper; ++d) {
            bool newTight = tight && (d == t[pos] - '0');
            ans += dfs(pos + 1, newTight);
        }

        if (!tight) dp[pos] = ans;
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int _limit, string _s) {
        limit = _limit;
        s = _s;

        // Count below start
        t = to_string(start - 1);
        memset(dp, -1, sizeof(dp));
        long long countBelowStart = dfs(0, true);

        // Count up to finish
        t = to_string(finish);
        memset(dp, -1, sizeof(dp));
        long long countUpToFinish = dfs(0, true);

        return countUpToFinish - countBelowStart;
    }
};
