#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



/************************** Solution-01 *************************
 * 解题思路：
 *     使用一前一后begin和end两个指针记录duplication重复段的结点范围，同时还需要一个pre记录
 * 重复段前一个位置的结点。需要注意考虑一些细节，如对结点取值时需要判断结点是否为空，或者输入
 * 链表中全部为重复结点的情形等
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead) return nullptr;

        ListNode* begin = pHead;
        ListNode* end = pHead;
        ListNode* pre = new ListNode(0);
        pre->next = pHead;
        ListNode* res = pre;

        while (pre->next) {
            end = end->next;
            if (end == nullptr) break;
            if (begin->val == end->val) {
                while (end && begin->val == end->val) {
                    end = end->next;
                }
                pre->next = end;
                begin = end;
                continue;
            }
            begin = end;
            pre = pre->next;
        }

        return res->next ? res->next : nullptr;
    }

};