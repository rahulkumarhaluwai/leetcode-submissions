class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = needle.size();
        vector<int> lps(n, 0);

        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int i = 0, j = 0;

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == n)
                return i - j;

            if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};
