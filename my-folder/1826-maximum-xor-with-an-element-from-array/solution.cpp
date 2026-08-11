class Solution {
    struct Node {
        Node* links[2] = {};

        bool containsKey(int bit) {
            return links[bit] != nullptr;
        }

        Node* get(int bit) {
            return links[bit];
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }
    };

    class Trie {
        Node* root = new Node();

    public:
        void insert(int num) {
            Node* node = root;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (!node->containsKey(bit))
                    node->put(bit, new Node());

                node = node->get(bit);
            }
        }

        int findMax(int num) {
            Node* node = root;
            int result = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (node->containsKey(1 - bit)) {
                    result |= (1 << i);
                    node = node->get(1 - bit);
                } else {
                    node = node->get(bit);
                }
            }

            return result;
        }
    };

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> offline;

        for (int i = 0; i < queries.size(); i++)
            offline.push_back({queries[i][1], {queries[i][0], i}});

        sort(offline.begin(), offline.end());

        vector<int> ans(queries.size(), -1);
        Trie trie;
        int i = 0;

        for (auto& query : offline) {
            int m = query.first;
            int x = query.second.first;
            int index = query.second.second;

            while (i < nums.size() && nums[i] <= m)
                trie.insert(nums[i++]);

            if (i > 0)
                ans[index] = trie.findMax(x);
        }

        return ans;
    }
};
