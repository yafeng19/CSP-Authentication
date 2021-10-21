#include<bits/stdc++.h>

// �ο� https://www.cnblogs.com/cswangchen/p/7532439.html

using namespace std;//����Ȩ����Ϣ
struct Privilege {
    string name;
    int level;
}privilege[110];
//�����ɫ��Ϣ
struct Role {
    string name;
    Privilege privi[11];
    int privilege_num;
}role[110];
//�����û���Ϣ
struct User {
    string name;
    Role role[11];
    int rolenum;
}usr[110];
int p, u, r, q, pos;
string s;
//���ڲ���privilege���±�
int findPrivi(string str) {
    for (int i = 0; i < 100; i++) {
        if (privilege[i].name == str)
            return i;
    }
    return -1;
}
//���ڲ���role���±�
int findRole(string str) {
    for (int i = 0; i < 100; i++) {
        if (role[i].name == str)
            return i;
    }
    return -1;
}
//���ڲ���usr���±�
int findUser(string str) {
    for (int i = 0; i<100; i++) {
        if (usr[i].name == str) return i;
    }
    return -1;
}
//Ȩ�޶���
void readPrivi() {
    for (int i = 0; i < p; i++) {
        cin >> s;
        if (s.find(':', 0) == s.npos) {
            privilege[i].level = -1;//level����-1�����ֵȼ�Ȩ��
            privilege[i].name = s;
        }
        else {
            pos = s.find(':', 0);
            privilege[i].name = s.substr(0, pos);
            privilege[i].level = s[s.length() - 1] - '0';
        }
    }
}
//��ɫ����
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
//��ɫ����
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
        int t_level = -1;//����ѯ���е�Ȩ�޵ȼ�
        cin >> s >> tmp;
        int t_usr = findUser(s);
        if (tmp.find(':', 0) != tmp.npos) {
            pos = tmp.find(':', 0);
            t_level = tmp[tmp.length() - 1] - '0';
            tmp = tmp.substr(0, pos);
        }
        int t_privi = findPrivi(tmp);
        //�������ѯ��Ȩ�������û��������ڣ�ֱ�����false
        if (t_usr == -1 || t_privi == -1) {
            cout << "false" << endl;
            continue;
        }
        //ѯ���в�����Ȩ�޵ȼ������
        if (t_level == -1) {
            //ѯ�ʵ��Ƿֵȼ�Ȩ��
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
            //ѯ�ʵ��ǲ��ֵȼ�Ȩ��
            else {
                int ans = -1;
                for (int j = 0; j<usr[t_usr].rolenum; j++) {
                    for (int k = 0; k<usr[t_usr].role[j].privilege_num; k++) {
                        if (usr[t_usr].role[j].privi[k].name == tmp) {
                            ans = 1;//�����û�ӵ�и�Ȩ��
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
        //ѯ���а���Ȩ�޵ȼ������
        else {
            int ans = -1;
            for (int j = 0; j<usr[t_usr].rolenum; j++) {
                for (int k = 0; k<usr[t_usr].role[j].privilege_num; k++) {
                    if (usr[t_usr].role[j].privi[k].name == tmp) {
                        //�����û�ӵ�е�Ȩ�ޣ��ҵ��û�ӵ�еı���ѯȨ�޵ȼ������ֵ
                        ans = max(ans, usr[t_usr].role[j].privi[k].level);
                    }
                }
            }
            //�û�ӵ�е�Ȩ�ޱȲ�ѯ�ĸ�
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
