#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}



/****************************** Solution-01*****************************
 * 解题思路：
 *     将二叉树打印成多行，即考查二叉树的层序遍历
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return res;

        queue<TreeNode*> my_queue;
        my_queue.push(pRoot);
        TreeNode* cur = pRoot;
        while (!my_queue.empty()) {
            level.clear();
            int num_elem_cur_level = my_queue.size();
            while (num_elem_cur_level--) {
                cur = my_queue.front();
                my_queue.pop();

                level.push_back(cur->val);
                if (cur->left) my_queue.push(cur->left);
                if (cur->right) my_queue.push(cur->right);
            }
            res.push_back(level);
        }

        return res;
    }

private:
    vector<int> level;
    vector<vector<int> > res;
};

