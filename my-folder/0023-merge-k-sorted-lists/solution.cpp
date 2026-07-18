/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        for (auto node : lists) {
            if (node) pq.push({node->val, node});
        }

        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ListNode* node = curr.second;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }

            temp->next = node;
            temp = temp->next;
        }

        return dummy.next;
    }
};
