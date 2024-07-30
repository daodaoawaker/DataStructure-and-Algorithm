
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


/**
 * 解题思路:
 * 
 * 使用递归的思路先到达链表的末尾结点(在这个过程中需要创建局部变量用来保存前驱结点和当前结点)，
 * 然后从后往前依次改变当前结点和前驱结点之间的连接关系，实现结点指向的反转。
 * 
*/
class Solution {
public:
    Solution() : preHead(new ListNode(0)), newHead(new ListNode(0)) {}

    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) return head;

        preHead->next = head;
        DFS(preHead, head);
        head->next = nullptr;
        preHead->next = nullptr;

        return newHead;
    }

    void DFS(ListNode *preNode, ListNode *curNode) {
        /**
         * 每一层DFS函数调用之后都完成了当前结点和前驱结点连接关系的修正，
         * 即从preNode->curNode 变成 curNode->preNode
        */
        if (curNode == nullptr) {
            // 递归结束条件，新的头结点找到了
            newHead = preNode;
            return;
        }

        ListNode *pre = preNode;
        ListNode *cur = curNode;
        DFS(pre->next, cur->next);
        cur->next = pre;
        pre->next = nullptr;
    }

private:
    ListNode *preHead; // 头前结点
    ListNode *newHead; // 最终的新的头结点
};