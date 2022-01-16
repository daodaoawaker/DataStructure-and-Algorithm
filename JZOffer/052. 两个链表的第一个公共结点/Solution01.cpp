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
 *     想到使用双指针，但双指针需要两个链表的公共结点之前的长度相等，也就是需要遍历的两个链表长度相等
 * 才好使用双指针对二者不断地同时向前遍历。因此可以在两个链表后各自连接上对方，即当遍历达到链表结尾时
 * (此时结点为空)紧接着开始遍历另外一条链表，从而达到了 a+b == b+a 的效果，这样就可以使用双指针了。
 * 此时，即便二者没有公共结点，也能保证他们都会同时遍历到空指针，返回空指针即可   
*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return nullptr;

        ListNode *a = pHead1;
        ListNode *b = pHead2;
        while (a != b) {
            a = a ? a->next : pHead2;
            b = b ? b->next : pHead1;
        }

        return a;
    }

};