#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    int num=1;
    int w;
    queue<int> q;

    cin >> n >> k;

    for(int i=1;i<=n;i++)
        q.push(i);
    while(!q.empty()){
        w = q.front();
        q.pop();
        if(num%k==0||num%10==k);
        else
            q.push(w);
        num++;
    }

    cout << w;

    return 0;
}
