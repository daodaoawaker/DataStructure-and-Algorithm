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
 *     用递归的思想遍历二叉树的每个节点，然后交换它的左、右子树
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


class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;

        // 交换当前根节点的左右子树
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        // 递归遍历下一层
        Mirror(pRoot->left);
        Mirror(pRoot->right);

        return pRoot;
    }
};