#include <iostream>

using namespace std;

int ShortestPath(int **str,int row, int col, int i=0, int j=0, int sum=0)
{
    static int len = row*col;
    if(i<0 || j<0 || i>=row || j>=col || str[i][j]==2)
    {
        return len;
    }
    else{
        if(str[i][j]==-1)
        {
            if(sum<len)
            {
                len=sum;
            }
            return len;
        }
    }
    int dup=str[i][j];
    str[i][j]=2;
    ShortestPath(str,row,col,i+1,j,sum+1); //bottom
    str[i][j]=dup;
    dup=str[i][j];
    str[i][j]=2;
    ShortestPath(str,row,col,i,j+1,sum+1); //right
    str[i][j]=dup;
    dup=str[i][j];
    str[i][j]=2;
    ShortestPath(str,row,col,i-1,j,sum+1); //top
    str[i][j]=dup;
    dup=str[i][j];
    str[i][j]=2;
    ShortestPath(str,row,col,i,j-1,sum+1); //left
    str[i][j]=dup;
    return len;
}

int main()
{
    int n,m;
    int **arr;
    cin >> n >> m;
    arr = new int*[n];
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
    int i,j;
    cin >> i >> j;
    cout << ShortestPath(arr,n,m,i,j);
    for(int i=0;i<n;i++)
    {
        delete arr[i];
    }
    delete arr;
    return 0;
}
