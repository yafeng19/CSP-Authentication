#include <iostream>

using namespace std;

int main()
{
    int pre=0;
    int now=0;
    int sum=0;

    int num;
    cin >> num;
    if(num==1) {
        sum += 1;
        pre = 1;
    }
    else if(num==2) {
        sum += 2;
        pre = 2;
    }
    while(num>0){
        cin >> num;
        if(num==1){
            sum += 1;
            pre = 1;
        }
        else if(num==2){
            if(pre==1){
                sum += 2;
                pre = 2;
            }
            else{
                sum += (pre+2);
                pre += 2;
            }
        }
    }

    cout << sum;

    return 0;
}
