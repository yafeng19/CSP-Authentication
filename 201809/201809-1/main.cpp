#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int price;
    for(int i=0;i<n;i++){
        cin >> price;
        v.push_back(price);
    }
    cout << (v[0]+v[1])/2 << " ";
    for(int j=1;j<n-1;j++)
        cout << (v[j-1]+
                 v[j]+v[j+1])/3 << " ";
    cout << (v[n-2]+v[n-1])/2<<endl;
    return 0;
}
