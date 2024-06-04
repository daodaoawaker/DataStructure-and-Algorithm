#include <iostream>
#include <vector>
#include <stack>


using namespace std;

typedef struct Node {
    int val;
    struct Node* next;
}ListNode;



/************************* Solution-03 ************************
 * 解题思路:
 *     从头到尾遍历，从尾到头打印，自然想到了使用队列来实现这样的顺序
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head == nullptr) return res;

        ListNode* p = head;
		stack<ListNode*> node_stack;
        while (p != nullptr) {
            node_stack.push(p);
            p = p->next;
        }
        while (!node_stack.empty()) {
            p = node_stack.top();
            res.push_back(p->val);
			node_stack.pop();
        }

        return res;
    }    

};
