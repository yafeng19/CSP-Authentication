#include <iostream>
#include <set>

using namespace std;

class mycompare
{

public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second == p2.second ?  p1.first < p2.first : p1.second < p2.second ;
    }
};


int main()
{
    int n, X, Y,x,y;
    cin >> n >> X >> Y;

    set<pair<int, int>,mycompare> poslst;
    pair<int,int> pos;
    int dis;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        dis = (X-x)*(X-x) + (Y-y)*(Y-y);
        pos = make_pair(i+1, dis);
        poslst.insert(pos);
    }
    int cnt = 0;
    for(set<pair<int, int>>::iterator it = poslst.begin(); it != poslst.end(); it++,cnt++)
    {
        cout << (*it).first << endl;
        if(cnt == 2) break;
    }


    return 0;
}
