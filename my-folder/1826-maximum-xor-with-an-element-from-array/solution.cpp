struct Node {
    Node* links[2];

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

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
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } 
            else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {
        vector<int> ans(queries.size(), -1);
        vector<pair<int, pair<int, int>>> offlineQueries;

        sort(nums.begin(), nums.end());

        int index = 0;

        for (auto& query : queries) {
            int x = query[0];
            int limit = query[1];

            offlineQueries.push_back({
                limit,
                {x, index}
            });

            index++;
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;

        int i = 0;
        int n = nums.size();

        for (auto& query : offlineQueries) {
            int limit = query.first;
            int x = query.second.first;
            int originalIndex = query.second.second;
            while (i < n && nums[i] <= limit) {
                trie.insert(nums[i]);
                i++;
            }
            if (i > 0) {
                ans[originalIndex] = trie.findMax(x);
            }
        }

        return ans;
    }
};
