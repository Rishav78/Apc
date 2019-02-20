#include <iostream>

using namespace std;

int compareWord(char *str, char *str2)
{
    int i=0;
    while(str[i]!='\0' && str2[i]!='\0')
    {
        if(str[i]!=str2[i])
        {
            break;
        }
        i++;
    }
    if(str[i]==str2[i])
    {
        return 0;
    }
    else{
        if(str[i]!='\0')
        {
            return -1;
        }
        return 1;
    }
}

int compareString(char str[], char str1[])
{
    int i=0,j=0;
    char dup[20];
    bool flag = true;
    while(true)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            if(flag==true)
            {
                dup[j]='\0';
                if(!compareWord(dup,str1))
                    return 1;
                if(str[i]=='\0')
                {
                    return 0;
                }
            }
            flag=false;
        }
        else
        {
            if(flag==false)
            {
                j=0;
                flag=true;
            }
            dup[j++] = str[i];
        }
        i++;
    }
   /* if(flag==true)
    {
        dup[j]='\0';
        if(!compareWord(dup,str1))
        return 1;
    }*/
    return 0;
}

int main()
{
    char str[20];
    char str1[10];
    cin.getline(str,20);
    cin >> str1;
    cout << compareString(str,str1);
    return 0;
}
