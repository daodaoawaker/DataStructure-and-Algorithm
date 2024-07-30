#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {}
};


/****************************** Solution-01 ******************************
 * 解题思路：
 * 使用递归的方式实现一个二叉树的后序遍历即可。
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;

        int numLeft  = TreeDepth(pRoot->left);
        int numRight = TreeDepth(pRoot->right);
        int ret = std::max(numLeft, numRight) + 1;
        return ret;
    }
};
