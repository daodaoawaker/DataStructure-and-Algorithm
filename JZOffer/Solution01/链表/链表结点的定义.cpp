/* C语言定义结点 */
typedef struct node {
    int val;
    struct node *next;
}ListNode;


/* C++定义结点 */
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
