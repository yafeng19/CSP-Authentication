#include<bits/stdc++.h>

// 参考 https://www.cnblogs.com/cswangchen/p/7532439.html

using namespace std;//保存权限信息
struct Privilege {
    string name;
    int level;
}privilege[110];
//保存角色信息
struct Role {
    string name;
    Privilege privi[11];
    int privilege_num;
}role[110];
//保存用户信息
struct User {
    string name;
    Role role[11];
    int rolenum;
}usr[110];
int p, u, r, q, pos;
string s;
//用于查找privilege的下标
int findPrivi(string str) {
    for (int i = 0; i < 100; i++) {
        if (privilege[i].name == str)
            return i;
    }
    return -1;
}
//用于查找role的下标
int findRole(string str) {
    for (int i = 0; i < 100; i++) {
        if (role[i].name == str)
            return i;
    }
    return -1;
}
//用于查找usr的下标
int findUser(string str) {
    for (int i = 0; i<100; i++) {
        if (usr[i].name == str) return i;
    }
    return -1;
}
//权限读入
void readPrivi() {
    for (int i = 0; i < p; i++) {
        cin >> s;
        if (s.find(':', 0) == s.npos) {
            privilege[i].level = -1;//level等于-1代表不分等级权限
            privilege[i].name = s;
        }
        else {
            pos = s.find(':', 0);
            privilege[i].name = s.substr(0, pos);
            privilege[i].level = s[s.length() - 1] - '0';
        }
    }
}
//角色读入
void readRole() {
    for (int i = 0; i < r; i++) {
        cin >> role[i].name;
        cin >> role[i].privilege_num;
        for (int j = 0; j < role[i].privilege_num; j++) {
            cin >> s;
            if (s.find(':', 0) == s.npos) {
                role[i].privi[j].level = -1;
                role[i].privi[j].name = s;
            }
            else {
                pos = s.find(':', 0);
                role[i].privi[j].name = s.substr(0, pos);
                role[i].privi[j].level = s[s.length() - 1] - '0';
            }
        }
    }
}
//角色读入
void readUser() {
    for (int i = 0; i < u; i++) {
        cin >> usr[i].name;
        cin >> usr[i].rolenum;
        for (int j = 0; j < usr[i].rolenum; j++) {
            cin >> s;
            usr[i].role[j] = role[findRole(s)];
        }
    }
}
void solve() {
    string tmp;
    while (q--) {
        int t_level = -1;//保存询问中的权限等级
        cin >> s >> tmp;
        int t_usr = findUser(s);
        if (tmp.find(':', 0) != tmp.npos) {
            pos = tmp.find(':', 0);
            t_level = tmp[tmp.length() - 1] - '0';
            tmp = tmp.substr(0, pos);
        }
        int t_privi = findPrivi(tmp);
        //如果被查询的权限名或用户名不存在，直接输出false
        if (t_usr == -1 || t_privi == -1) {
            cout << "false" << endl;
            continue;
        }
        //询问中不包含权限等级的情况
        if (t_level == -1) {
            //询问的是分等级权限
            if (privilege[t_privi].level != -1) {
                int ans = -1;
                for (int j = 0; j<usr[t_usr].rolenum; j++) {
                    for (int k = 0; k<usr[t_usr].role[j].privilege_num; k++) {
                        if (usr[t_usr].role[j].privi[k].name == tmp) {
                            ans = max(ans, usr[t_usr].role[j].privi[k].level);
                        }
                    }
                }
                if (ans == -1) {
                    cout << "false" << endl;
                }
                else
                    cout << ans << endl;
            }
            //询问的是不分等级权限
            else {
                int ans = -1;
                for (int j = 0; j<usr[t_usr].rolenum; j++) {
                    for (int k = 0; k<usr[t_usr].role[j].privilege_num; k++) {
                        if (usr[t_usr].role[j].privi[k].name == tmp) {
                            ans = 1;//代表用户拥有该权限
                        }
                    }
                }
                if (ans == -1) {
                    cout << "false" << endl;
                }
                else
                    cout << "true" << endl;
            }
        }
        //询问中包含权限等级的情况
        else {
            int ans = -1;
            for (int j = 0; j<usr[t_usr].rolenum; j++) {
                for (int k = 0; k<usr[t_usr].role[j].privilege_num; k++) {
                    if (usr[t_usr].role[j].privi[k].name == tmp) {
                        //遍历用户拥有的权限，找到用户拥有的被查询权限等级的最大值
                        ans = max(ans, usr[t_usr].role[j].privi[k].level);
                    }
                }
            }
            //用户拥有的权限比查询的高
            if (ans >= t_level) {
                cout << "true" << endl;
            }
            else
                cout << "false" << endl;
        }
    }
}
int main() {
    string s;
    cin >> p;
    readPrivi();
    cin >> r;
    readRole();
    cin >> u;
    readUser();
    cin >> q;
    solve();
}
