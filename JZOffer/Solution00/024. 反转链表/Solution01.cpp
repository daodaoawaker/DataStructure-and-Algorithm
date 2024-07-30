#include <vector>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



/************************* Solution-01 ************************
 * 解题思路:
 * 使用递归的思路先到达链表的末尾结点(在这个过程中需要创建局部变量用来保存前驱结点和当前结点)，
 * 然后从后往前依次改变当前结点和前驱结点之间的连接关系，实现结点指向的反转
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return pHead;

        preHead->next = pHead;
        DFS(preHead, pHead);
        pHead->next = nullptr;

        return newHead;
    }

    void DFS(ListNode* preNode, ListNode* curNode) {
        if (curNode == nullptr) {
            newHead = preNode;
            return;
        }
        ListNode* pre = new ListNode(0);
        ListNode* cur = new ListNode(0);
        pre = preNode;
        cur = curNode;

        DFS(pre->next, cur->next);
        cur->next = pre;
        pre->next = nullptr;
    }

private:
    ListNode* preHead = new ListNode(0);
    ListNode* newHead = new ListNode(0);
};
