#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Role{
public:
int pos;
int attack;
int health;
public:
Role(int p, int a, int h){
    pos = p;
    attack = a;
    health = h;
}

};

int main()
{
    int n;
    cin >> n;
    bool turn = 0;  //代表是哪个玩家的轮次
    vector<Role> v[2];

    int flag = 0;   //获胜标志

    Role hero = Role(0,0,30);
    v[0].push_back(hero);
    v[1].push_back(hero);

    string action;
    int pos, attack,health;
    int ally, enemy;
    for(int i=0;i<n;i++){
        cin >> action;
        if (!strcmp(action.c_str(),"summon")){
            cin >> pos >> attack >> health;
            Role role = Role(pos,attack,health);
            v[turn].insert(v[turn].begin()+pos,role);
        }
        else if (!strcmp(action.c_str(),"attack")){
            cin >> ally >> enemy;
            v[turn][ally].health -= v[!turn][enemy].attack;
            v[!turn][enemy].health -= v[turn][ally].attack;

            // 英雄阵亡，游戏结束。必须在判断随从阵亡之前，因为英雄阵亡不影响随从顺序
            if(v[turn][0].health<=0){
                flag = turn?1:-1;
                break;
            }
            if(v[!turn][0].health<=0){
                flag = turn?-1:1;
                break;
            }
            if(v[turn][ally].health<=0) v[turn].erase(v[turn].begin()+ally);
            if(v[!turn][enemy].health<=0) v[!turn].erase(v[!turn].begin()+enemy);

        }
        else if (!strcmp(action.c_str(),"end")){
            turn = !turn;
        }
    }

    cout << flag << endl;

    cout << v[0][0].health << endl;
    cout << v[0].size()-1<< " ";
    for(int i=1;i<v[0].size();i++)
        cout << v[0][i].health << " ";
    cout << endl;

    cout << v[1][0].health << endl;
    cout << v[1].size()-1<< " ";
    for(int i=1;i<v[1].size();i++)
        cout << v[1][i].health << " ";
    cout << endl;

    return 0;
}
