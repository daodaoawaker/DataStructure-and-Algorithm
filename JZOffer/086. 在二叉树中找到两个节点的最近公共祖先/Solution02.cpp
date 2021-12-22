#include <queue>
#include <map>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};



/************************** Solution-02 *************************
 * 解题思路：
 *     总体思路从下往上遍历，找出指定的两个节点元素到根节点的路径，两条路径的交点即为二者的
 * 最近公共祖先节点。
 *     找出指定节点到根节点的路径的方法依然是遍历二叉树，只是在遍历的过程中用一个map记录下节点
 * 和它的父节点组成的键值对。无须遍历完整颗二叉树，只需保证遍历到这两个指定的元素即可。先将其中
 * 一个指定元素p到根节点的路径上的元素依次保存下来，然后遍历另一个元素到根节点的路径，找出二者
 * 的交点。
 *     需要注意的点是，寻找第一个元素到根节点的路径时，注意最后一定要把根节点添加进去，否则当
 * 根节点是二者的最近公共祖先时会报错
*/
class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) return -1;

        std::map<int, int> parent_map;
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode* cur;

        // 只需查找到遍历到了这两个节点即可，无须遍历整个二叉树
        while (parent_map.count(p) == 0 || parent_map.count(q) == 0) {
            cur = node_queue.front();
            node_queue.pop();

            if (cur->left) {
                node_queue.push(cur->left);
                parent_map.emplace(cur->left->val, cur->val);
            }
            if (cur->right) {
                node_queue.push(cur->right);
                parent_map.emplace(cur->right->val, cur->val);
            }
        }

        // 将元素p到二叉树的根节点的路径上的值依次添加到path1中
        std::vector<int> path1;
        while (parent_map.count(p) == 1) {
            path1.push_back(p);
            p = parent_map.at(p);
        }
        path1.push_back(root->val);  // Notice here!! 一定要把根节点添加进去

        // 遍历从元素值q到根节点的路径path2，当遍历到path1中存在相同的元素值时，即为二者最近的祖先节点
        std::vector<int>::iterator itr = find(path1.begin(), path1.end(), q);
        while (itr == path1.end()) {
            q = parent_map.at(q);
            itr = find(path1.begin(), path1.end(), q);
        }

        return q;
    }

};