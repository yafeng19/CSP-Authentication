#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s, e;
    vector<int> a;
    vector<int> b;
    for(int i=0; i<n; i++)
    {
        cin >> s >> e;
        for(int j=s; j<e; j++)
            a.push_back(j);
    }
    for(int i=0; i<n; i++)
    {
        cin >> s >> e;
        for(int j=s; j<e; j++)
            b.push_back(j);
    }

    int cnt = 0;
    int i=0;
    int j=0;
    while(i<a.size()&&j<b.size())
    {
        if(a[i]==b[j]){
            cnt++;
            i++;
            j++;

        }
        else if(a[i]<b[j])
                i++;

        else if(a[i]>b[j])
                j++;

    }
    cout << cnt;

    return 0;
}
