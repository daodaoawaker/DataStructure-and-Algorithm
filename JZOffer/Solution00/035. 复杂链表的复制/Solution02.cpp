#include <iostream>
#include <map>


using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};



/************************* Solution-02 ************************
 * 解题思路:
 *     如果先不考虑随即指针，则复制出一个新的链表应该相对比较容易，完成这样的复制过程后随即指针
 * 该如何处理呢？
 *     可以想到，在前面完成新的复制链表的构建过程中，同时创建出一个映射，即原链表上的org结点和
 * 新的复制链表上的dup结点组成的<key,value>对。这样的用处就是，通过这么一个映射关系就可以根据
 * 原结点的random指针所指的结点，找到复制链表中dup结点的random指针的所指了。
*/
class Solution {
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) return pHead;

        map<RandomListNode*, RandomListNode*> node_map;
        RandomListNode* cur = pHead;
        RandomListNode* pre = new RandomListNode(0);
        RandomListNode* newHead = pre;
        while (cur) {
            RandomListNode* dup = new RandomListNode(cur->label);
            node_map.emplace(cur, dup);
            pre->next = dup;
            cur = cur->next;
            pre = pre->next;
        }
        for (map<RandomListNode*, RandomListNode*>::iterator it = node_map.begin(); it != node_map.end(); ++it) {
            RandomListNode* org = it->first;
            RandomListNode* dup = it->second;
            if (org->random) {
                dup->random = node_map[org->random];
            }
        }

        return newHead->next;
    }
};