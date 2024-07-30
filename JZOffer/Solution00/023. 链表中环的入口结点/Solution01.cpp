#include <vector>
#include <map>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


/************************* Solution-01 ************************
 * 解题思路:
 *     首先的想法是通过map存储每个node和它出现的次数组成的一个个`键值对`，遍历链表的过程中构造出这些键值对
 * 并依次添加到map中，添加之前对待添加的key进行查找，若这个key已经出现过则其即为环的入口
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead) return nullptr;

        ListNode* cur = pHead;
        std::map<ListNode*, int> node_map;

        while (cur) {
            if (node_map.count(cur)) {
                return cur;
            }
            node_map.emplace(cur, 1);
            cur = cur->next;
        }

        return nullptr;
    }

};