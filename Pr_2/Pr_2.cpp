#include <iostream>
#include <fstream>
#include "string"

using namespace std;


//Чтение данных файла и вывод на монитор физического файла А
//постусловие: 0 - успешно; 1 - файл не открылся

int readTextFile(string nameTf) {
    ifstream itf(nameTf);
    if (!itf) return 1;
    int x;
    while (!itf.eof()) {
        itf >> x;
        cout << x << ' ';
    }
    cout << endl;
    itf.close();
    return 0;
}


int createTextFile(string nameTf, string nameNewTf) {
    ifstream itf(nameTf);
    if (!itf) return 1;
    ofstream otf(nameNewTf);
    int x;
    while (itf >> x) {
        if (x % 2 == 0)
            otf << ' ' << x;
        else otf << ' ';
    }
    otf.close();
    itf.close();
    return 0;
}


int addTo(string nameTf, int a, int b) {
    ofstream otf(nameTf, ios::app);
    if (!otf) return 1;

    otf << "\n" << a << ' ' << b;
    otf.close();
    return 0;
}

int main() {
    string name1;
    cout << "Введите имя первого файла >>";
    cin >> name1;
    name1+=".txt";
    int kod = readTextFile(name1);

    if (kod == 1) cout << "File not found";
    kod = createTextFile("A.txt", "B.txt");
    if (kod == 0)
        readTextFile("B.txt");
    else
        cout << "File not found";
    return 0;
}
