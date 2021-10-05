#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a,b;
    cin >> n >> a >> b;
    int index, value;

    vector<pair<int,int>> u;
    for(int i=0; i<a; i++)
    {
        cin >> index >> value;
        u.emplace_back(make_pair(index, value));
    }

    long long sum = 0;

    int i =0;
    for(int j=0; j<b; j++)
    {
        cin >> index >> value;
        for(i; i<a;)
        {
            if(index<u.at(i).first)
                break;

            else if(index>u.at(i).first)
                i++;
            else{
                sum += value * (u.at(i).second);
                i++;
            }
        }
    }

    cout << sum;
    return 0;
}
