#include <iostream>
#include <clocale>

using namespace std;

void coutp(unsigned int x)
{
    int n=sizeof(int)*8;
    unsigned  maska=(1<<(n-1));
    for(int i=1; i<=n;i++)
    {
        cout<<((x&maska)>>(n-i));
        maska=maska>>1;
    }
}


int main() {
    setlocale(LC_ALL, "rus");

    //№1
    unsigned int num = 0x0;
    coutp(num);
    cout << endl;
    unsigned int maska = 0x20A0;
    coutp(num | maska);
    cout << "\n\n\n";


    //№2
    num = 0xFFFFFFFF;
    coutp(num);
    cout << endl;
    maska = 0x0FFFFFFF;
    coutp(num & maska);
    cout << "\n\n\n";


    //№3
    num = 0x1;
    coutp(num);
    cout << endl;
    //unsigned short maska = 0x20A0;
    coutp(num << 9);
    cout << "\n\n\n";

    //№4
    num = 0x00000000;
    coutp(num);
    cout << endl;
    maska = 0x80000000;
    coutp(maska);
    cout << "\nВведите номер бита >> ";
    int a;
    cin >> a;
    a = 31 - a;
    maska = maska >> a;
    coutp(num | maska);
    cout << "\n\n\n";
    return 0;
}
