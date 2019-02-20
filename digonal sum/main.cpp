#include <iostream>

using namespace std;

bool fun(int **arr, int n, int m, int i, int j, int num, int sum=0)
{
    if(j<0 || j>=m || i>=n)
    {
        if(sum==num){return true;}
        return false;
    }
    if(fun(arr,n,m,i+1,j-1,num,sum+arr[i][j]))
    {
        cout << arr[i][j] << endl;
        return true;
    }
    if(fun(arr,n,m,i+1,j+1,num,sum+arr[i][j]))
    {
        cout << arr[i][j] << endl;
        return true;
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n>> m;
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
    int a,b,sum;
    cin >> a>> b>> sum;
    fun(arr,n,m,a,b,sum);
    return 0;
}
