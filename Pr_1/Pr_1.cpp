#include <iostream>
#include <clocale>
#include <bitset>

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

    return 0;
}
