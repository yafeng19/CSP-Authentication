#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5;

int main()
{
    int n = 0;
    cin >> n;
    pair<int, int> prlst[N];
    int sum[N];
    for(int i = 1; i <= n; i++){
        int theta = 0;
        int res = 0;
        cin >> theta >> res;
        prlst[i] = make_pair(theta, res);
    }
    sort(prlst+1, prlst+n+1);
    set<int> st;
    int maxtheta = 0;
    int maxpre = 0;

    for(int i = 1; i<=n; i++){
        sum[i] = sum[i-1] + prlst[i].second;
    }
    for(int i = 1; i<=n; i++){
        int a = prlst[i].first;
        if(st.count(a)) continue;
        st.insert(a);
        int pre1 = sum[n] - sum[i-1];
        int pre0 = i-1 - sum[i-1];
        if(pre1 + pre0 >= maxpre){
            maxpre = pre1 + pre0;
            maxtheta = a;
        }
    }

    cout << maxtheta;

    return 0;
}
