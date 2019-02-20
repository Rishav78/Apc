#include <iostream>

using namespace std;

char *SubString(char str[], int start, int last)
{
    int n = last - start,i;
    char *subStr = new char[n];
    for(i=0;i<n;i++)
    {
        subStr[i] = str[start+i];
    }
    subStr[i] = '\0';
    return subStr;
}

int main()
{
    char str[50];
    cin.getline(str,50);
    int n1,n2;
    cin >> n1 >> n2;
    char *sub = SubString(str,n1,n2);
    cout << sub;
    delete sub;
    return 0;
}
