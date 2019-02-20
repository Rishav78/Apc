#include <iostream>

using namespace std;

void Index(char *str)
{
    int i=0,j=0;
    bool flag=false;
    while(true)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            if(flag==true)
            {
                cout << j << " " << i << endl;
                flag=false;
            }
            if(str[i]=='\0')
            {
                break;
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
    Index(str);
    return 0;
}
