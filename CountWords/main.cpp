#include <iostream>

using namespace std;

int CountWords(char *str)
{
    int i=0,words=0;
    bool flag=false;;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            if(flag==true)
            {
                words++;
                flag=false;
            }
        }
        else
        {
            if(flag==false)
            {
                flag=true;
            }
        }
        i++;
    }
    if(flag==true)
    {
        words++;
    }
    return words;
}

int main()
{
    char str[100];
    cin.getline(str,100);
    cout << CountWords(str);
    return 0;
}
