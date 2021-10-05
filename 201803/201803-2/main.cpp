#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, l, t;
    cin >> n >> l >> t;
    vector<int> pv;
    vector<int> dv;
    int pos;
    for(int i=0;i<n;i++){
        cin >> pos;
        pv.push_back(pos);
        dv.push_back(1);
    }

    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            pv[j] += dv[j];
            if(pv[j]==l||pv[j]==0)
                dv[j] = -dv[j];
        }

        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++)
                if(pv[j]==pv[k]){
                    dv[j] = -dv[j];
                    dv[k] = -dv[k];
                }
        }
    }

    for(int i=0;i<n;i++)
        cout << pv[i] << " ";

    return 0;
}
