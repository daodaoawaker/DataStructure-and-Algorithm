#include <vector>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



/************************* Solution-01 ************************
 * 解题思路:
 *     使用双指针begin、end分别指向两个相隔为k的节点，其中head指向链表的头节点。
 * 然后让这两个指针同时向前移动，当尾指针到达链表尾部时，首指针即为目标节点。
*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || k == 0) return nullptr;

        ListNode* begin = new ListNode(0);
        ListNode* end = new ListNode(0);
        begin->next = pHead;
        end->next = pHead;
        while (k > 0) {
            end = end->next;
            k--;
            if (!end) return nullptr;
        }
        while (end != nullptr) {
            end = end->next;
            begin = begin->next;
        }

        return begin;
    }

};