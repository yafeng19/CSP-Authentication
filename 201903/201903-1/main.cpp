#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    int num;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    int lnum = v[0];
    int rnum = v[n-1];
    int mnum;
    if(n%2==0){
        //ע��������������Ը�����2.0�ŵø�����
        //�������뱣��������(int)(num+0.5)
        //�������뱣��һλС����round(num*10.0)/10.0
        mnum = v[n/2-1]+v[n/2];
        if(mnum%2==0)
            cout << rnum<<" " << mnum/2 <<" " << lnum;
        else
            cout << rnum<<" " << round(mnum/2.0*10)/10.0 <<" " << lnum;
    }
    else
    {
        mnum = v[(n+1)/2-1];
        cout << rnum<<" " << mnum <<" " << lnum;
    }


    return 0;
}
