class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_map<string, vector<int>> goodSets;

        auto reverseStr = [](const string& s) {
            string r = s;
            reverse(r.begin(), r.end());
            return r;
        };

        int L = (n + 1) / 2;
        long long start = (L == 1) ? 1 : pow(10, L - 1);
        long long end = pow(10, L);

        for (long long num = start; num < end; ++num) {
            string half = to_string(num);
            string palStr;

            if (n % 2 == 0) {
                palStr = half + reverseStr(half);
            } else {
                palStr = half + reverseStr(half.substr(0, half.length() - 1));
            }

            long long palNum = stoll(palStr);
            if (palNum % k != 0) continue;

            vector<int> freq(10, 0);
            for (char ch : palStr) {
                freq[ch - '0']++;
            }

            string key;
            for (int f : freq) {
                key += to_string(f) + ",";
            }

            goodSets[key] = freq; 
        }

        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }

        long long totalCount = 0;

        for (auto& entry : goodSets) {
            vector<int> freq = entry.second;
            
            long long totalPerm = fact[n];
            for (int f : freq) {
                totalPerm /= fact[f];
            }

            long long leadZeroCount = 0;
            if (freq[0] > 0) {
                long long ways = fact[n - 1] / fact[freq[0] - 1];
                for (int d = 1; d < 10; ++d) {
                    ways /= fact[freq[d]];
                }
                leadZeroCount = ways;
            }

            totalCount += (totalPerm - leadZeroCount);
        }

        return totalCount;
    }
};
