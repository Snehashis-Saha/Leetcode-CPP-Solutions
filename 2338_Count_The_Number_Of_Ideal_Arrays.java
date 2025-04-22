class Solution {
    static final int MOD = 1_000_000_007;
    static final int MAX_N = 10000;
    static long[] fact = new long[MAX_N + 100];
    static long[] invFact = new long[MAX_N + 100];

    public int idealArrays(int n, int maxValue) {
        int maxExp = 14;
        int maxA = n + maxExp;

        computeFactorials(maxA);

        long ans = 0;

        for (int num = 1; num <= maxValue; num++) {
            Map<Integer, Integer> primeFactors = factorize(num);
            long ways = 1;

            for (Map.Entry<Integer, Integer> entry : primeFactors.entrySet()) {
                int exp = entry.getValue();
                int a = exp + n - 1;
                int b = n - 1;

                ways = (ways * comb(a, b)) % MOD;
            }

            ans = (ans + ways) % MOD;
        }

        return (int) ans;
    }
    
    private void computeFactorials(int max) {
        fact[0] = invFact[0] = 1;

        for (int i = 1; i <= max; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[max] = pow(fact[max], MOD - 2);
        for (int i = max - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    private long pow(long base, int exp) {
        long result = 1;
        base %= MOD;
        while (exp > 0) {
            if ((exp & 1) == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    private long comb(int n, int r) {
        if (r > n || r < 0) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    private Map<Integer, Integer> factorize(int num) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                map.put(i, map.getOrDefault(i, 0) + 1);
                num /= i;
            }
        }
        if (num > 1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        return map;
    }
}