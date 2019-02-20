#include <iostream>

using namespace std;

void fun(int **arr, int n, int m, int i, int j,bool flag=true)
{
    if(j<0 || j>=m || i>=n)
    {
        return;
    }
    if(flag==true)
    {
        cout << arr[i][j] << endl;
    }
    else
    {
        for(int k=j;k<m;k=k+2)
        {
            cout << arr[i][k] << endl;
        }
    }
    fun(arr,n,m,i+1,j-1,false);
}

int main()
{
    int n,m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
        }
    }
    int a,b;
    cin >> a >> b;
    fun(arr,n,m,a,b);
    return 0;
}
