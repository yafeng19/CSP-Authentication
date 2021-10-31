#include <iostream>

using namespace std;

int myfind(int lst[], int v, int n){
    for(int i=0;i<n;i++)
        if(lst[i]==v)
            return i;
    return -1;
}

int main()
{
    int n;
    int m;

    cin >> n;
    int lst[n];
    for(int i=0;i<n;i++){
        lst[i] = i+1;
    }

    cin >> m;
    int p, q;
    int pos;
    int j;
    for(int i=0;i<m;i++){
        cin >> p >> q;
        if(q>=0){
            pos = myfind(lst,p,n);
            for(j=0;j<q;j++)
                lst[pos+j] = lst[pos+j+1];
            lst[pos+j] = p;
        }
        else{
            q = -q;
            pos = myfind(lst,p,n);
            for(j=0;j>-q;j--)
                lst[pos+j] = lst[pos+j-1];
            lst[pos+j] = p;
        }

    }

    for(int i=0;i<n;i++)
        cout << lst[i] << " ";


    return 0;
}
