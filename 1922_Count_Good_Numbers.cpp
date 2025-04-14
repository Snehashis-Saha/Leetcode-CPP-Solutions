
class Solution {
public:
    const long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long ans = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long a = (n + 1) / 2;
        long long b = n / 2;
        long long x = modPow(5, a);
        long long y = modPow(4, b);
        long long res = (x * y) % mod;
        return static_cast<int>(res);
    }
};
