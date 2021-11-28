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
 *     用递归的思想遍历二叉树的每个节点，然后交换它的左、右子节点
 * 
 */
class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;

        TreeNode* tmp = Mirror(pRoot->left);
        pRoot->left = Mirror(pRoot->right);
        pRoot->right = tmp;

        return pRoot;
    }
};