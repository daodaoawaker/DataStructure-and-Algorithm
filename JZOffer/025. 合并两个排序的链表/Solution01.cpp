#include <iostream>
#include <vector>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



/*************************** Solution-01 **************************
 * 解题思路:
 *     首先想到的是使用双指针分别指向两个已知链表的头结点，然后依次比较两个指针所指元素，将较小的那个
 * 作为新链表中的结点，然后对其作向前加1操作，如此不断循环直到其中某个已知链表被遍历完循环结束。
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 && !pHead2) return nullptr;
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;

        ListNode* preHead = new ListNode(0);
        ListNode* cur = preHead;
        while (pHead1 != nullptr || pHead2 != nullptr) {
            if (!pHead1) {
                cur->next = pHead2;
                break;
            }
            if (!pHead2) {
                cur->next = pHead1;
                break;
            }
            if (pHead1->val >= pHead2->val) {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            } else {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            cur = cur->next;
        }

        return preHead->next;
    }
};