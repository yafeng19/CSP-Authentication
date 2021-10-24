
// 参考 https://www.pianshen.com/article/7021421814/

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct key{
    int id;
    bool state; // 钥匙状态，0借1还
    int time;   // 借或者还钥匙的时间
}Key;

bool cmp(Key k1, Key k2){
    // 时间不同则按照先后顺序排序
    if(k1.time!=k2.time)
        return k1.time < k2.time;
    // 时间相同但状态不同，先还再借
    else if(k1.state!=k2.state)
        return k1.state > k2.state;
    // 时间相同，状态相同，按照钥匙序号排序
    else
        return k1.id < k2.id;

}

int main()
{

    int n, k;
    cin >> n >> k;
    int order[n];
    for(int i=0;i<n;i++)
        order[i]=i+1;

    Key keyque[k*2];
    int w, s, c;
    for(int i=0;i<k;i++){
        cin >> w >> s >> c;
        keyque[i*2].id = w;
        keyque[i*2].state = 0;
        keyque[i*2].time = s;
        keyque[i*2+1].id = w;
        keyque[i*2+1].state = 1;
        keyque[i*2+1].time = s + c;
    }
    sort(keyque, keyque+2*k, cmp);

    for(int i=0;i<2*k;i++){
        // 借钥匙
        if(!keyque[i].state){
            for(int j=0;j<n;j++){
                if(order[j]==keyque[i].id){
                    order[j]=0;
                    break;
                }
            }
        }
        // 还钥匙
        else{
            for(int j=0;j<n;j++){
                if(order[j]==0){
                    order[j]=keyque[i].id;
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        cout << order[i] << " ";


    return 0;
}
