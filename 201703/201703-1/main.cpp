#include <iostream>

using namespace std;

int main()
{
    int n , k;
    cin  >> n >> k;

    int a;
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> a;
        sum += a;
        if(sum >= k){
            cnt++;
            sum = 0;
        }
        if(i==n-1&&sum<k&&sum>0)
            cnt++;
    }

    cout << cnt;

    return 0;
}
