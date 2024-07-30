#include <iostream>
#include <vector>


using namespace std;

typedef struct node {
    int val;
    struct node* next;
}ListNode;



/********************* Solution-02 ********************
 * 解题思路:
 *     用递归的思路即深度优先搜索，先到达链表的末尾添加对应的元素值，再依次递归出来返回到上一层
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head == nullptr) return res;

        printListFromTailToHead(head->next);
        res.push_back(head->val);

        return res;
    }

private:
    vector<int> res;

};