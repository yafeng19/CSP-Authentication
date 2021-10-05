#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int remain=0;
    int origin,drop;
    int maxdrop = 0;
    int maxindex = 0;
    for(int i=0;i<n;i++){
        cin >> origin;
        remain += origin;
        int totaldrop = 0;
        for(int j=0;j<m;j++){
            cin >> drop;

            remain += drop;
            totaldrop += abs(drop);
            if(totaldrop>maxdrop){
                maxdrop =totaldrop;
                maxindex = i+1;
            }
        }
    }

    cout << remain <<" "<<maxindex<<" "<<maxdrop<<endl;
    return 0;
}
