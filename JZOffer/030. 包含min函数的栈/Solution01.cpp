#include <vector>
#include <stack>


using namespace std;



/************************* Solution-01 ************************
 * 解题思路：
 *     使用两个栈来实现栈的接口，一个栈1用于进行栈的基本操作，另一个辅助栈2专门用来存放当前情况下栈1中的最小值。
*/
class Solution {
public:
    void push(int val) {
        st_val.push(val);
        if (st_min.empty()) {
            st_min.push(val);
        } else {
            int cur_min = st_min.top();
            if (val < cur_min) st_min.push(val);
        }
    }

    int pop() {
        int ret = st_val.top();
        if (st_val.size() > st_min.size()) {
            st_val.pop();
        } else {
            st_val.pop();
            st_min.pop();
        }
        return ret;
    }

    int top() {
        return st_val.top();
    }

    int min() {
        return st_min.top();
    }

private:
    stack<int> st_val;
    stack<int> st_min;

};