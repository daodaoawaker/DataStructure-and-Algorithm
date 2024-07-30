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



/***************************** Solution-01 ****************************
 * 解题思路：
 *     采用非递归的方式遍历二叉树的每个节点，然后交换它的左、右子树
 * 
 */
class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;

        TreeNode* cur = pRoot;
        stack<TreeNode*> ST;

        // 非递归<中序>遍历二叉树的各个节点
        while (cur != nullptr || !ST.empty()) {
            while (cur != nullptr) {
                ST.push(cur);
                cur = cur->left;
            }
            if (!ST.empty()) {
                cur = ST.top();
                ST.pop();
                // 交换当前遍历节点的左右子树
                TreeNode* tmp = cur->left;
                cur->right = cur->left;
                cur->right = tmp;
                // Notice here!! 访问完当前节点后，本应将其置为其右子节点,
                // 但因为前面已经交换了左右子树，所以这里应该置为左子节点
                cur = cur->left;
            }
        }
        
        return pRoot;
    }

};