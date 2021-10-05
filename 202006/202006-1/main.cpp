#include <iostream>
#include <vector>

using namespace std;

class Point{
public:
    int x;
    int y;
    char type;
};

int main()
{
    vector<Point> pv;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n;i++){
        Point p;
        cin >> p.x >> p.y >>p.type;
        pv.push_back(p);
    }

    for(int j=0; j<m; j++){
        int flag = 0;

        int a,b,c;
        int type;
        cin >> a >> b >>c;
        for(auto it:pv){
            if(a+b*(it).x+c*(it).y>0)
                type='A';
            else type='B';
            if(type == (it).type) flag++;
        }
        if(flag==0||flag==n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
