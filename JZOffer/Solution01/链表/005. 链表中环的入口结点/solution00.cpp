#include <map>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead) return pHead;
        ListNode *cur = pHead;
        std::vector<ListNode*> nodes;

        while (cur) {
            std::vector<ListNode*>::iterator it;
            it = find(nodes.begin(), nodes.end(), cur);
            if (it != nodes.end()) {
                return cur;
            }
            nodes.push_back(cur);
            cur = cur->next;
        }

        return nullptr;
    }
};
