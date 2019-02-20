#include <iostream>

using namespace std;

void shift(char *str, int i, int Count)
{
    if(str[i]=='\0')
    {
        str[i-Count] = str[i];
        return;
    }
    str[i-Count] = str[i];
    shift(str,i+1,Count);
}

void Replace(char str[])
{
    int i=0,Count=-4;
    bool flag=true;
    while(str[i++]!='\0')
    {
        if(str[i]==' ')
        {
            if(flag==true)
            {
                Count=-4;
                flag=false;
            }
            Count++;
        }
        else
        {
            if(flag==false)
            {
                shift(str,i,Count);
                i = i - Count;
                str[i-4] = '0';
                str[i-3] = 'X';
                str[i-2] = '2';
                str[i-1] = '0';
                flag=true;
            }
        }
    }
}

int main()
{
    char str[50];
    cin.getline(str,50);
    Replace(str);
    cout << str;
    return 0;
}
