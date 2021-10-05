#include <iostream>

using namespace std;

int main()
{
    int r, y, g;
    cin >> r >> y >> g;
    int n, k, t;

    cin >> n;

    int sum = 0;

    for(int i=0;i<n;i++){
        cin >> k >> t;
        switch(k){
        case 0: sum += t; break;
        case 1: sum += t; break;
        case 2: sum += (t+r); break;
        case 3: break;
        }
    }

    cout << sum;

    return 0;
}
