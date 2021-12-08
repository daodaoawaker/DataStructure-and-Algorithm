#include <iostream>
#include <vector>
#include <queue>


using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};



/*************************** Solution-01 ************************
 * 解题思路：
 *     明显本题考查的是二叉树的层序遍历，使用栈来实现每一层节点的先进先出
 * 
 */
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* pRoot) {
        if (!pRoot) return res;

        queue<TreeNode*> Q;
        Q.push(pRoot);
        TreeNode* cur;
        while (!Q.empty()) {
            cur = Q.front();
            res.push_back(cur->val);
            Q.pop();

            if (cur->left) Q.push(cur->left);
            if (cur->right) Q.push(cur->right);
        }

        return res;
    }

private:
    vector<int> res;

};