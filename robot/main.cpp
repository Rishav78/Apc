#include <iostream>

using namespace std;

void fun(int **arr, int n, int m, int i, int j, int flag=0)
{
    if(i<0 || i>=n || j<0 || j>=m || arr[i][j]==-1 || arr[i][j]==0)
    {
        return;
    }
    arr[i][j]=0;
    fun(arr,n,m,i+1,j); //bottom
    fun(arr,n,m,i,j-1); //left
    fun(arr,n,m,i-1,j); //top
    fun(arr,n,m,i,j+1); //right
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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
