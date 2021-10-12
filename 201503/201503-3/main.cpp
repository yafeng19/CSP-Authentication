#include <iostream>
#include <vector>
using namespace std;

int leapyear(int y) //返回这一年之前的闰年数
{
    int cnt = 0;
    for(int i=1850; i<y; i++)
        if(i%400==0||i%4==0&&i%100!=0)
            cnt++;
    return cnt;
}

int daynum(int y) //返回1850年到这一年之间的天数
{
    int leap = leapyear(y);
    int nonleap = y-1850-leap;
    int daynum = nonleap*365+leap*366;
    return daynum;
}

vector<int> nleap= {0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<int> leap= {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    int weekday, date;
    for(int i=y1; i<=y2; i++)
    {
        if(i%400==0||i%4==0&&i%100!=0)
        {
            int day = daynum(i);
            for(int j=1; j<a; j++)
                day += leap[j];    //到i年a月1日的天数
            weekday = 1 + day%7;    //i年a月1日前一天星期几
            if (c>weekday)
                date = (b-1)*7+c-weekday;
            else
                date = (b-1)*7+c+7-weekday;
            if(date>leap[a])
                cout << "none" << endl;
            else
            {
                cout << i <<"/";
                if(a<10)
                    cout << "0";
                cout << a <<"/";
                if(date<10)
                    cout << "0";
                cout << date<<endl;
            }
        }
        else
        {
            int day = daynum(i);
            for(int j=1; j<a; j++)
                day += nleap[j];    //到i年a月1日的天数
            weekday = 1 + day%7;    //i年a月1日前一天星期几
            if (c>weekday)
                date = (b-1)*7+c-weekday;
            else
                date = (b-1)*7+c+7-weekday;
            if(date>nleap[a])
                cout << "none" << endl;
            else
            {
                cout << i <<"/";
                if(a<10)
                    cout << "0";
                cout << a <<"/";
                if(date<10)
                    cout << "0";
                cout << date<<endl;
            }
        }

    }

    return 0;
}
