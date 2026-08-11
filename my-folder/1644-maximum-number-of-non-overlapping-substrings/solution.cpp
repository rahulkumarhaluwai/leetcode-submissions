class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] != i) continue;

            int l = i, r = last[s[i] - 'a'];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                if (first[s[j] - 'a'] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[s[j] - 'a']);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        for (auto [l, r] : intervals) {
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};
