#include <iostream>
#include <string>
using namespace std;

void compress(string s)
{
    int num = s.length();

    for (int i = 0; i < num;)
    {
        int repetition = 1;
        while (s[i] == s[i + 1] && i + repetition < num)
        {
            repetition++;
            i++;
        }
        cout << s[i] << repetition;
        i++;
    }
}

int main()
{
    string str;
    cin >> str;

    compress(str);
}