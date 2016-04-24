#include <QCoreApplication>
#include "huge.h"
#include <QDebug>
#include <QTextCodec>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    /* ТЕСТ Huge */
    Huge one("9999999999999999999999999999999999999999999999");
    Huge two("1111111111111111111111111111111111111111111111");
    cout << one << " + " << two << " = " << one + two << endl;

    return a.exec();
}
