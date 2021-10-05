#include <iostream>

using namespace std;


//参考博客 https://blog.csdn.net/weixin_44778155/article/details/101158855


int main()
{
    long long r, y, g;
    cin >> r >> y >> g;
    //一个循环：红-绿-黄
    int round = r+y+g;
    int n, k, t;

    cin >> n;

    long long sum = 0;

    for(int i=0; i<n; i++)
    {
        cin >> k >> t;
        if(k==0) sum+=t;
        else
        {
            long long tmp;
            if(k==1) tmp = y+r-t;
            else if(k==2) tmp = y-t;
            else if(k==3) tmp = y+r+g-t;

            tmp = (tmp+sum)%round;
            if(tmp < y+r) sum += y+r-tmp;
        }
    }

    cout << sum << endl;

    return 0;
}
