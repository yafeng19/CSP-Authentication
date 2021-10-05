#include <iostream>

using namespace std;


int main()
{
    int n,k,t,xl,yd,xr,yu;
    int x, y;
    int passcnt = 0;
    int staycnt = 0;
    cin >>n>>k>>t>>xl>>yd>>xr>>yu;

    for(int i = 0; i<n; i++)
    {
        bool ispass = false;
        bool isstay = false;
        int cnt = 0;
        for (int j =0; j<t; j++)
        {
            cin >> x >> y;
            if(x>=xl&&x<=xr&&y>=yd&&y<=yu) {
                ispass = true;
                cnt++;
                if(cnt >= k)
                    isstay = true;
            }
            else cnt = 0;
        }
        if(ispass) passcnt++;
        if(isstay) staycnt++;
    }

    cout << passcnt <<endl << staycnt;


    return 0;
}
