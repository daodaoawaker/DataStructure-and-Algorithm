#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



/**************************** Solution-01 ***************************
 * 解题思路：
 *     思路肯定是首先考虑使用递归，递归的出口条件就是必须到达叶子节点，并且
 * 当前叶子节点的值和剩余target的值相等。然后就是递归遍历每个子节点，需要注
 * 意的就是一些实现细节。
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // 递归出口
        int val = root->val;
        if (!root->left && !root->right && val == sum) return true;

        if (hasPathSum(root->left, sum - val)) return true;
        if (hasPathSum(root->right, sum - val)) return true;
        return false;
    }
};