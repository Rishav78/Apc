#include <iostream>

using namespace std;

void reverseString(char *str,int i=0)
{
    static int len;
    if(str[i*2]=='\0')
    {
        len = i*2;
        return;
    }
    else{
        if(str[i*2 + 1] == '\0')
        {
            len = i*2+1;
            return;
        }
    }
    reverseString(str,i+1);
    char temp = str[i];
    str[i] = str[len-(1+i)];
    str[len-(1+i)] = temp;
}

int main()
{
    char str[20];
    cin >> str;
    reverseString(str);
    cout << str;
    return 0;
}
