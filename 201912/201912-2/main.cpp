#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x,y;
    vector<pair<int ,int>> v;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        pair<int, int> p = make_pair(x,y);
        v.push_back(p);
    }

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;

    pair<int, int> p,p1,p2,p3,p4,p5,p6,p7,p8;
    for(int i=0;i<n;i++){
        p = v[i];
        p1 = make_pair(p.first-1,p.second);
        p2 = make_pair(p.first,p.second+1);
        p3 = make_pair(p.first+1,p.second);
        p4 = make_pair(p.first,p.second-1);
        vector<pair<int,int>>::iterator b = v.begin();
        vector<pair<int,int>>::iterator e = v.end();
        if(find(b,e,p1)!=e&&find(b,e,p2)!=e&&find(b,e,p3)!=e&&find(b,e,p4)!=e){
            int cnt = 0;
            p5 = make_pair(p.first-1,p.second-1);
            p6 = make_pair(p.first-1,p.second+1);
            p7 = make_pair(p.first+1,p.second-1);
            p8 = make_pair(p.first+1,p.second+1);
            if(find(b,e,p5)!=e) cnt++;
            if(find(b,e,p6)!=e) cnt++;
            if(find(b,e,p7)!=e) cnt++;
            if(find(b,e,p8)!=e) cnt++;

            switch(cnt){
                case 0: cnt0++; break;
                case 1: cnt1++; break;
                case 2: cnt2++; break;
                case 3: cnt3++; break;
                case 4: cnt4++; break;
            }
        }

    }

    cout <<cnt0<<endl<<cnt1<<endl<<cnt2<<endl<<cnt3<<endl<<cnt4<<endl;

    return 0;
}
