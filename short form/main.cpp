#include <iostream>

using namespace std;

void Swap(char *str, int i, int len)
{
    if(str[i]=='\0')
    {
        str[i-len] = str[i];
        return;
    }
    str[i-len] = str[i];
    Swap(str,i+1,len);
}

void shortName(char *str)
{
    int i=0,len=-2;
    bool flag=true;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            if(flag==true)
            {
                flag=false;
            }
        }
        else
        {
            if(flag==false)
            {
                Swap(str,i,len);
                i = i - len;
                str[i-1] = '.';
                len=-2;
                flag=true;
            }
        }
        len++;
        i++;
    }
}

int main()
{
    char arr[50];
    cin.getline(arr,50);
    shortName(arr);
    cout << arr;
    return 0;
}
