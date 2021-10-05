#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> q;
    for(int k=0;k<n;k++)
        q.push_back(false);

    int opernum;
    int dropcnt=0;
    int remain=0;
    for(int i=0;i<n;i++){
        int one_remain = 0;
        cin >> opernum;
        for(int j=0;j<opernum;j++){
            int num;
            cin >> num;
            if(num>0){
                if(one_remain>num)
                    q[i] = true;
                one_remain = num;
            }
            else{
                one_remain += num;
            }
        }
        remain += one_remain;
    }

    int E = 0;
    for(int i=0;i<n;i++){
        if(q[i])
            dropcnt++;
        if(q[((i+n)-1)%n]&&q[i]&&q[(i+1)%n])
            E++;
    }

    cout << remain << " " << dropcnt << " " << E;

    return 0;
}
