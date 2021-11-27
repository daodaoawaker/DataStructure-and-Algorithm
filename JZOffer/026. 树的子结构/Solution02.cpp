#include <iostream>
#include <vector>
#include <stack>


using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    bool HasSubtree(TreeNode* pNode1, TreeNode* pNode2) {
        if (!pNode1 || !pNode2) return false;

        // 非递归前序遍历树1
        stack<TreeNode*> ST;
        TreeNode* cur = pNode1;
        while (cur != nullptr || !ST.empty()) {
            // 走至最左子节点
            while (cur != nullptr) {
                ST.push(cur);
                cur = cur->left;    
            }
            if (!ST.empty()) {
                cur = ST.top();
                ST.pop();
                if (isSub(cur, pNode2)) {
                    return true;
                }
                cur = cur->right;
            }
        }

        return false;
    }

    // 以pHead1为主，判断pHead1和pHead2是否具有相同的结构
    bool isSub(TreeNode* pHead1, TreeNode* pHead2) {
        // ！！要注意这两个判断条件的先后顺序
        if (!pHead2) return true;
        if (!pHead1) return false;

        return (pHead1->val == pHead2->val) && isSub(pHead1->left, pHead2->left) && isSub(pHead1->right, pHead2->right);
    }

};