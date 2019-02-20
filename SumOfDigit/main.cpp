#include <iostream>

using namespace std;

int SumOfDigit(int n, int sum=0) // 1234 => 4 + 3 + 2 + 1
{
    if(n<10)
    {
        return sum+n;
    }
    return SumOfDigit(n/10, sum+n%10);
}

/*int SumOfDigit(int n) // 1234 => 1 + 2 + 3 + 4
{
    if(n<10)
    {
        return n;
    }
    return (n%10 + SumOfDigit(n/10));
}*/

int main()
{
    int n;
    cin >> n;
    cout << SumOfDigit(n);
    return 0;
}
