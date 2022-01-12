#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct node {
    int val;
    struct node* next;
}ListNode;



/********************* Solution-01 ********************
 * 解题思路:
 *     第一种思路从头到尾遍历链表，用一个数组记录下每个节点的元素值，然后反转数组
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head == nullptr) return res;

        while (head) {
            res.push_back(head->val);
            head = head->next;
        }

        // reverse(res.begin(), res.end());
        int i = 0, j = res.size() - 1, tmp = 0;
        while (i < j) {
            tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;
            i++;
            j--;
        }

        return res;
    }
    
};