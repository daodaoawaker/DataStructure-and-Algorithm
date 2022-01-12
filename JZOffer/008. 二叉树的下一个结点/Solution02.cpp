#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* next;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};




/***************************** Solution-02 *****************************
 * 解题思路：
 *     用笨一点的办法解决，既然它想找中序遍历的下一个节点，那就先找到二叉树的根节点，然后
 * 得到整个二叉树的中序遍历序列，进而得到下一个节点
*/
class Solution {
public:
    TreeNode* GetNext(TreeNode* pNode) {
        if (!pNode) return nullptr;

        TreeNode* root = pNode;
        while (root->next) {
            root = root->next;
        }
        inOrderTraverse(root);

        vector<TreeNode*>::iterator it = find(vecInOrder.begin(), vecInOrder.end(), pNode);
        if (it != vecInOrder.end() && it != vecInOrder.end() - 1) {
            return *it++;
        }
        
        return nullptr;
    }

    void inOrderTraverse(TreeNode* pHead) {
        if (!pHead) return;

        inOrderTraverse(pHead->left);
        vecInOrder.push_back(pHead);
        inOrderTraverse(pHead->right);
        return;
    }

private:
    vector<TreeNode*> vecInOrder;
};