#include <vector>
#include <algorithm>

using namespace std;



/************************* Solution-01 ************************
 * 解题思路：
 *     每个窗口就是对vector的一个切片操作，通过max_element()不断地取得当前切片的最大值即可
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        if (size == 0 || size > num.size()) 
            return res;

        for (int i = 0, j = size - 1; j < num.size(); i++, j++) {
            vector<int> cur_win(num.begin() + i, num.begin() + j + 1);
            int cur_max = curMax(cur_win);
            res.push_back(cur_max);
        }

        return res;
    }

    int curMax(vector<int>& vec) {
        return *max_element(vec.begin(), vec.end());
    }

private:
    vector<int> res;

};