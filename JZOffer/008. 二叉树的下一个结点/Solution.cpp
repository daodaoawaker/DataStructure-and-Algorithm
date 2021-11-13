#include <vector>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* next;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};




/********************** Solution-01 ***************************
 * 解题思路：
 * 
 *    根据中序遍历的规律，可以分为两种情况讨论：
 * 1) 当前节点存在右子节点。则下一个节点应该是其右子树的最左节点；
 * 2）当前节点没有右子节点。根据中序遍历的特点可知，此时的下一个节点肯定是当前节点的父辈节点，
 * 并且其左父节点都已经被遍历过了，故此时的下一个节点应该是其父辈节点中的第一个右父节点。
*/
class Solution {
public:
    TreeNode* GetNext(TreeNode* pNode) {
        if (!pNode) return nullptr;

        // 存在右子节点
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        // 不存在右子节点
        while (pNode->next) {
            // 第一个右父节点
            if (pNode == pNode->next->left) {
                return pNode->next;
            }
            pNode = pNode->next;
        }

        return nullptr;
    }
};

