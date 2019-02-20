#include <iostream>

using namespace std;

void shift(char *str,int i, int j)
{
    if(str[i]=='\0')
    {
        str[i-j]=str[i];
        return;
    }
    str[i-j] = str[i];
    shift(str,i+1,j);
}

void trim(char *str)
{
    int i=0,j=0;
    bool flag =false;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            if(flag==true)
            {
                flag=false;
                j=-1;
            }
            j++;
        }
        else
        {
            if(flag==false)
            {
                shift(str,i,j);
                i = i - j;
                flag=true;
            }
        }
        i++;
    }
}

int main()
{
    char str[20];
    cin.getline(str,20);
    trim(str);
    cout << str;
    return 0;
}
