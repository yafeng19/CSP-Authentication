#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;
    int sum = 0;
    scanf("%d", &cnt);
    int w = 0;
    int score = 0;
    for(int i=0;i<cnt;i++){
        scanf("%d %d", &w, &score);
        sum += w*score;
    }
    if(sum >=0)
        printf("%d",sum);
    else
        printf("0");
    return 0;
}
