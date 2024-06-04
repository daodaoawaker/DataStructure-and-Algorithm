#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};




/**************************** Solution-01 ***************************
 * 解题思路：
 *     本题能想到是利用队列对二叉树进行层序遍历，不过之字形保存结果就需要在原有层序遍历的基础
 * 上，知道队列中每一层的元素个数，然后对奇数层进行一个反转即可。
 *     因为使用队列进行层序遍历的过程，就是对队列中当前层的元素进行front()取队头元素和pop()弹
 * 出队头元素的操作，然后将弹出节点的左右孩子节点(也就是下一层的节点元素）添加进队列中。所以，
 * 可以在每一次循环开始时作个size()操作，获取当前队列中的元素个数，也就方便对当前层的所有元素进
 * 行单独记录保存，从而可以根据层数的奇偶选择是否进行反转。
 */
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) return result;

        queue<TreeNode*> my_queue;
        my_queue.push(root);
        TreeNode* p;
        int num_levels = 0;

        while (!my_queue.empty()) {
            int elems_cur_level = my_queue.size();
            vector<int> cur_level;

            while (elems_cur_level--) {
                p = my_queue.front();
                cur_level.push_back(p->val);
                my_queue.pop();

                if (p->left) my_queue.push(p->left);
                if (p->right) my_queue.push(p->right);
            }

            if (num_levels % 2 == 1) {
                reverse(cur_level.begin(), cur_level.end());
            }
            num_levels++;
            result.push_back(cur_level);
        }

        return result;
    }
    
};