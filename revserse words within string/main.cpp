#include <iostream>

using namespace std;

void reverseWorlds(char *str, int i, int j)
{
    while(i>j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i--;
        j++;
    }
    cout << str << endl;
}

void Reverse(char *str)
{
    int i=0,j=0;
    bool flag=false;
    while(true)
    {
        if(str[i]==' '  || str[i]=='\0')
        {
            if(flag==true)
            {
                reverseWorlds(str,i-1,j);
                if(str[i]=='\0')
                {
                    break;
                }
                flag=false;
            }
        }
        else
        {
            if(flag==false)
            {
                j=i;
                flag=true;
            }
        }
        i++;
    }
}

int main()
{
    char str[100];
    cin.getline(str,100);
    Reverse(str);
    cout << str;
    return 0;
}
