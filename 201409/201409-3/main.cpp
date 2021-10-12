#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool upper;
    int num;
    string word;

    cin >> word >> upper >> num;

    string wd = word;
    for(int i=0;i<word.size();i++)
        if(isupper(word[i]))
            word[i]=tolower(word[i]);

    string tmp;

    for(int i=0; i<num; i++)
    {
        cin >> tmp;
        if(upper){
            int pos = tmp.find(wd);
            if(pos>=0)
                cout << tmp << endl;
        }
        else{
            string s = tmp;
            for(int j=0;j<s.size();j++)
                if(isupper(s[j]))
                    s[j] = tolower(s[j]);
            int pos = s.find(word);
            if(pos>=0)
                cout << tmp << endl;
        }
    }

    return 0;
}
