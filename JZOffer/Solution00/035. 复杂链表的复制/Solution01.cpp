#include <vector>


using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};



/*************************** Solution-01 **************************
 * 解题思路:
 *     该思路比较巧妙，总体上一共遍历三次链表:
 * 1. 第一次遍历。依次在原链表的每个org原结点后创建出一个dup复制结点，此时链表的长度变为了原来的一倍。
 * 接下来考虑如何将这些`复制结点`从原链表中拆分出来构成我们最终想要的一个新的复制链表。
 * 2. 第二次遍历。为了处理好`复制结点`的随机指针，这里采用双指针，一个指向原链表结点，一个指向复制
 * 结点，注意这里就有了这样的关系: dup->random = org->random->next (这也是该思路的巧妙之处)。
 * 3. 第三次遍历。主要是完成原链表和复制链表的拆分。
 * 
 * 注意！！最开始的想法是把第二次遍历和第三次遍历合在一起作，但后来发现不行。因为如果合在一起作，在遍历
 * 过程中原链表和复制链表的前半部分已经拆分开了，后面再去找随机指针所指的结点时，连接关系已经不存在了
 *     
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) return pHead;
        
        RandomListNode *p = pHead;
        while (p) {
            RandomListNode *dup = new RandomListNode(p->label);
            dup->next = p->next;
            p->next = dup;
            p = p->next->next;
        }
        p = pHead;
        while (p) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        RandomListNode* newHead = pHead->next;
        RandomListNode* q = newHead;
        p = pHead;
        while (q->next) {
            p->next = q->next;
            p = p->next;
            q->next = p->next;
            q = q->next;
        }
        p->next = nullptr;

        return newHead;
    }

};