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

    Node* root = new Node();

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
                node->put(bit, new Node());

            node = node->get(bit);
        }
    }

    int getMaxXOR(int num) {
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

public:
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums)
            insert(num);

        int ans = 0;

        for (int num : nums)
            ans = max(ans, getMaxXOR(num));

        return ans;
    }
};
