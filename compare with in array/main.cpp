#include <iostream>

using namespace std;
/*
int fun(int *arr, int n=0)
{
    static int c=0;
    c++;
    static int len = 0;
    if(arr[n]==-1)
    {
        return c;
    }
    len++;
    fun(arr,n+1);
    if(len/2<=n)
    {
        return c;
    }
    arr[n] = arr[n] + arr[len-1-n];
    arr[len-1-n]=arr[n];
    return c;

}
*/
/*
void fun(int *arr, int n=0)
{
    static int len;
    if(arr[n*2]==-1)
    {
        len = n*2;
        return;
    }
    else{
        if(arr[n*2+1]==-1)
        {
            len = n*2+1;
            return;
        }
    }
    fun(arr,n+1);
    arr[n] = arr[n] + arr[len-1-n];
    arr[len-1-n]=arr[n];
}*/

bool fun(int *arr, int n=0)
{
    static int len;
    if(arr[n*2]==-1)
    {
        len = n*2;
        return true;
    }
    else{
        if(arr[n*2+1]==-1)
        {
            len = n*2+1;
            return true;
        }
    }
    if(fun(arr,n+1)==false)
    {
        return false;
    }
    return arr[n]==arr[len-1-n];
}

int main()
{
    int n;
    cin >> n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
    }
    if(fun(p))
    {
        cout << "YES";
    }
    return 0;
}

