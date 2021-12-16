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
 *     因为使用队列进行层序遍历的过程，就是对队列中的当前层的元素进行top()取队头元素和pop()弹
 * 出队头元素的操作，然后将左右孩子元素也就是下一层的元素添加进队列中。这样以来，在每一次取队头
 * 元素操作之前获取一下当前队列中的元素个数，便得到了当前层的所有元素，从而根据层数的奇偶选择是
 * 否进行反转。
 */
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) return result;

        queue<TreeNode*> my_queue;
        my_queue.push(root);
        TreeNode* p;
        int num_level = 0;

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

            if (num_level % 2 == 0) {
                reverse(cur_level.begin(), cur_level.end());
            }
            num_level++;
            result.push_back(cur_level);
        }

        return result;
    }
    
};