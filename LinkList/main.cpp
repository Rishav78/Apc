#include <iostream>

using namespace std;

struct List
{
    int value;
    List *ptr;
};

int main()
{
    List *start = nullptr;
    while(true)
    {
        int n;
        cin >> n;
        if(n==1)// create
        {
            List *ptr = new List;
            cin >> ptr->value;
            ptr->ptr = nullptr;
            if(start==nullptr)
            {
                start=ptr;
            }
            else{
            List *p = start;
            while(p->ptr!=nullptr)
            {
                p = p->ptr;
            }
            p->ptr = ptr;
            }
        }
        else
        {
            List *p = start;
            while(p->ptr!=nullptr)
            {
                cout << p->value << endl;
                p = p->ptr;
            }
        }
    }
    return 0;
}
