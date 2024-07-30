#include <iostream>
#include <vector>


using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};



/***************************** Solution-01 ****************************
 * 解题思路：
 *     由对称二叉树的定义，树中任意两个对称节点L和R必定满足以下：
 * 1. L->val == R->val
 * 2. L和R的孩子节点必须构成两对对称节点，即
 *    L->left->val  == R->right->val;
 *    L->right->val == R->left->val;
 * 
 * 根据以上规律，考虑自顶而下递归判断二叉树上的每对节点是否对称，从而得出整棵树是否对称
 */
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        return isPairSymmetric(pRoot->left, pRoot->right);
    }

    bool isPairSymmetric(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (root1 == nullptr || root2 == nullptr) return false;

        return root1->val == root2->val &&
               isPairSymmetric(root1->left, root2->right) &&
               isPairSymmetric(root1->right, root2->left);
    }
};
