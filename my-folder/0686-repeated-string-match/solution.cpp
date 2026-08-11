class Solution {
public:
    bool rabinKarp(string &text, string &pat) {
        int n = text.size(), m = pat.size();
        if (m > n) return false;

        long long base = 31;
        long long mod = 1e9 + 7;

        long long patHash = 0, textHash = 0;
        long long power = 1;

        for (int i = 0; i < m; i++) {
            patHash = (patHash * base + (pat[i] - 'a' + 1)) % mod;
            textHash = (textHash * base + (text[i] - 'a' + 1)) % mod;

            if (i < m - 1)
                power = (power * base) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            if (textHash == patHash) {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) return true;
            }

            if (i < n - m) {
                textHash = (textHash - (text[i] - 'a' + 1) * power) % mod;
                if (textHash < 0) textHash += mod;

                textHash = (textHash * base +
                            (text[i + m] - 'a' + 1)) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int repeats = (b.size() + a.size() - 1) / a.size();

        string s;
        for (int i = 0; i < repeats; i++)
            s += a;

        if (rabinKarp(s, b))
            return repeats;

        s += a;

        if (rabinKarp(s, b))
            return repeats + 1;

        return -1;
    }
};
