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
 *     总体思路从下往上遍历，找出指定的两个节点到根节点的路径，两条路径的交点即为二者的最近公
 * 共祖先节点。找出指定节点到根节点的路径，方法依然是遍历二叉树，只是在遍历的过程中需要用一个
 * map记录下每个节点和其父节点的元素值构成的键值对，目的是为了方便后面从下往上地记录``路径``。
 *     这里无须遍历完整颗二叉树，因为我们的目标是分别找出指定节点到根节点的``路径``，只需保证
 * 遍历到了这两个指定的节点元素即可。先将其中一个指定节点p到根节点的路径上的元素依次记录保存下
 * 来，然后遍历另一个节点到根节点的路径，找出二者的重合位置即为所需。
 *     Notice!! 需要注意的就是，寻找第一个节点到根节点的路径时，注意最后一定要把根节点添加进去，
 * 否则当根节点是二者的最近公共祖先时会出错。
*/
class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) return -1;

        std::map<int, int> parent_map;
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode* cur;

        // 只需要遍历到了这两个节点即可，无须遍历整个二叉树
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

        // 记录下节点p到根节点的完整路径`path1`
        std::vector<int> path1;
        while (parent_map.count(p) == 1) {
            path1.push_back(p);
            p = parent_map.at(p);
        }
        // // Notice here!! 一定要保证把根节点添加进`path1`当中
        path1.push_back(root->val);

        // 遍历另一个节点q到根节点的路径`path2`，
        // 然后不断地判断`path2`中的当前元素是否出现在了`path1`中
        std::vector<int>::iterator itr = find(path1.begin(), path1.end(), q);
        while (itr == path1.end()) {
            q = parent_map.at(q);
            itr = find(path1.begin(), path1.end(), q);
        }

        return q;
    }

};