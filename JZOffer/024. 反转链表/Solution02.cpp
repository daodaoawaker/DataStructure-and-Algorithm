#include <vector>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



/********************** Solution-02 *********************
 * 解题思路:
 *     从头遍历链表，每个位置都分别记录下前驱/当前/后继结点三个变量，然后改变三者之间的连接关系
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return pHead;

        ListNode* pre = new ListNode(0);
        ListNode* cur = new ListNode(0);
        ListNode* next = new ListNode(0);
        pre->next = pHead;
        cur = pHead;

        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        pHead->next = nullptr;

        return pre;
    }
};