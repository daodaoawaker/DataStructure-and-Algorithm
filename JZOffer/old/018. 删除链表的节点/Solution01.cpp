#include <vector>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



/************************* Solution-01 ************************
 * 解题思路:
 *     需要注意的点应该是: 1)链表为空; 2)删除的是头节点
*/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) return head;

        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur->next = nullptr;
                break;
            }
            cur = cur->next;
            pre = pre->next;
        }

        return res->next;
    }
};