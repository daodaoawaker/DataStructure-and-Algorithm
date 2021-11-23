#include <iostream>
#include <vector>


using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};



/*************************** Solution-01 ***************************
 * 解题思路：
 *    根据递归的思路判断树A当中有无跟树B的结构完全相同的子树
 */
class Solution {
public:
    bool HasSubtree(TreeNode* pNode1, TreeNode* pNode2) {
        if (!pNode1 || !pNode2) return false;
        
        // 判断以pNode1为头节点的子树或者以pNode1的左右子树中是否存在和pNode2相同结构的子树
        return isSub(pNode1, pNode2) || HasSubtree(pNode1->left, pNode2) || HasSubtree(pNode1->right, pNode2);
    }

    // 以pHead1和pHead2为头节点的两颗子树是否具有相同的结构（以pHead1为主）
    bool isSub(TreeNode* pHead1, TreeNode* pHead2) {
        if (!pHead2) return true;
        if (!pHead1) return false;

        return (pHead1->val == pHead2->val) && isSub(pHead1->left, pHead2->left) && isSub(pHead1->right, pHead2->right);
    }

};