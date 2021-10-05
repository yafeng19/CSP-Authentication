#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int totalcnt = 1;
    int validcnt = 0;
    int a= 0;
    int b= 0;
    int c= 0;
    int d= 0;
    while(validcnt<n)
    {
        if(totalcnt%7==0||to_string(totalcnt).find('7')!=-1)
        {
            int who = totalcnt%4;
            switch(who)
            {
            case 1:
                a++;
                break;
            case 2:
                b++;
                break;
            case 3:
                c++;
                break;
            case 0:
                d++;
                break;
            }
        }
        else validcnt++;
        totalcnt++;
    }

    cout <<a<<endl<<b<<endl<<c<<endl<<d;

    return 0;
}
