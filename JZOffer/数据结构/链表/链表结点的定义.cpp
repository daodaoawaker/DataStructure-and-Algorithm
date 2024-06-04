/***** C语言定义结点 *****/
typedef struct node {
    int val;
    struct node *next;
}ListNode;


/***** C++定义结点 *****/
struct ListNode {
    ListNode(int x) : val(x), next(nullptr) {}

    int val;
    ListNode *next;
};
