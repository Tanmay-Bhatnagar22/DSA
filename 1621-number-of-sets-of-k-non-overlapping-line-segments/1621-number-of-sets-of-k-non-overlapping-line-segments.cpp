class Solution {
public:
    static const int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    int numberOfSets(int n, int k) {
        int maxN = n + k; // upper bound for factorial array size
        vector<long long> fact(maxN + 1), invFact(maxN + 1);
        
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[maxN] = power(fact[maxN], MOD - 2, MOD);
        for (int i = maxN - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        
        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };
        
        // Answer = C(n + k - 1, 2k)
        return (int) C(n + k - 1, 2 * k);
    }
};