#include <iostream>
#include <vector>
#include <stack>

//²Î¿¼£ºhttps://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num;
    vector<int> heights;
    for(int i=0;i<n;i++){
        cin >> num;
        heights.push_back(num);
    }

    vector<int> left(n), right(n, n);

    stack<int> mono_stack;
    for (int i = 0; i < n; ++i) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            right[mono_stack.top()] = i;
            mono_stack.pop();
        }
        left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
        mono_stack.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }

    cout << ans;

    return 0;
}
