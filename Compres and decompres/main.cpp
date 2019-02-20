#include <iostream>

using namespace std;

void Swap(char *str, int i, int Count)
{

    if(str[i]=='\0')
    {
        str[i+Count] = str[i];
        return;
    }
    if(Count>=0)
    {
        Swap(str,i+1,Count);
    }
    str[i+Count] = str[i];
    if(Count<0)
    {
        Swap(str,i+1,Count);
    }
}

//COMPRESS
void compress(char *str)
{
    int i=0, Count=0;
    char s = str[0];
    while(str[i]!='\0')
    {
        if(str[i]!=s)
        {
            s = str[i];
            Swap(str,i,-1*(Count-2));
            i=i-(Count-2);
            str[i-1] = char(Count + '0');
            Count=1;
        }
        else
        {
            Count++;
        }
        i++;
    }
    Swap(str,i,(Count-2)*-1);
    i=i-(Count-2);
    str[i-1] = char(Count + '0');
}

void decompress(char *str)
{
    bool flag=true;
    int c=1;
    int num=0,i=0,j=0;
    while(str[i++]!='\0')
    {
        if(str[i]>='0' && str[i]<='9')
        {
            if(flag==true)
            {
                j=i;
                num = 0;
                c=1;
            }
            num = num*10 + (str[i] - '0');
            flag = false;
            c++;
        }
        else{
            if(flag==false)
            {
                Swap(str,i,num-c);
                for(int k=j;num>1;k++)
                {
                    str[k]=str[k-1];
                    num--;
                }
                i=i+num-1;
                flag=true;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    char str[n];
    cin >> str;
    compress(str);
    decompress(str);
    cout << str;
    return 0;
}
