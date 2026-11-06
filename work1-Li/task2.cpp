#include <iostream>
#include <cstring>
using namespace std;

int countVowels(const char* p)
{
    int cnt = 0;
    while (*p != '\0')
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
        {
            cnt++;
        }
        p++;
    }
    return cnt;
}

int main()
{
    char str[100];
    cin.getline(str, 100);
    int num = countVowels(str);
    cout << num << endl;
    return 0;
}

