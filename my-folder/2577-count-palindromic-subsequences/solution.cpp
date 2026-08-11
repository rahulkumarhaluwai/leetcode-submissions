class Solution {
public:
    int countPalindromes(string s) {
        const long long MOD = 1000000007;

        long long left[10][10] = {};
        long long right[10][10] = {};
        long long leftCnt[10] = {};
        long long rightCnt[10] = {};

        for (char c : s) {
            rightCnt[c - '0']++;
        }

        long long cnt[10] = {};

        for (int i = s.size() - 1; i >= 0; i--) {
            int d = s[i] - '0';

            for (int x = 0; x < 10; x++) {
                right[d][x] += cnt[x];
            }

            cnt[d]++;
        }

        long long ans = 0;

        for (char c : s) {
            int d = c - '0';

            rightCnt[d]--;

            for (int x = 0; x < 10; x++) {
                right[d][x] -= rightCnt[x];
            }

            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + left[a][b] * right[b][a]) % MOD;
                }
            }

            for (int x = 0; x < 10; x++) {
                left[x][d] += leftCnt[x];
            }

            leftCnt[d]++;
        }

        return ans;
    }
};
