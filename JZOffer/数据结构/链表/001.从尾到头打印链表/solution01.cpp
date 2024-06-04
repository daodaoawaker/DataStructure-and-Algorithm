#include <iostream>
#include <vector>


struct ListNode {
    ListNode(int x) : val(x), next(nullptr) {}

    int val;
    ListNode *next;
};


/**
 * 解题思路:
 *     第一种思路从头到尾遍历链表，用一个数组记录下每个节点的元素值，然后反转数组
 * 
*/
class Solution {
public:
    std::vector<int> printListFromTailToHead(ListNode *head) {
        std::vector<int> ret;
        if (head == nullptr) return ret;

        while(head) {
            ret.push_back(head->val);
            head = head->next;
        }

        int i = 0, tmp = 0;
        int j = ret.size() - 1;
        while (i < j) {
            tmp = ret[i];
            ret[i] = ret[j];
            ret[j] = tmp;
            i++;
            j--;
        }

        return ret;
    }
};


