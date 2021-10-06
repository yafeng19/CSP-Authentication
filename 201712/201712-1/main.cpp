#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int num;
    for(int i=0;i<n;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());


    int mindiff = 10001;
    for(int i=0;i<n-1;i++){
        if(mindiff > v[i+1]-v[i])
            mindiff = v[i+1]-v[i];
    }

    cout << mindiff;

    return 0;
}
