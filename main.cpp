#include <QCoreApplication>
#include "bignumber.h"
#include "huge.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    /* ТЕСТ BigNumber - НАЧАЛО */
    BigNumber num1("111111111111111111111111111111"), //9999999
              num2("999999999999999999999999999999");//99999
    auto num3 = num1 + num2;

    num1.print();
    cout << " + ";
    num2.print();
    cout << " = ";
    num3.print();
    cout << endl;
    /* ТЕСТ BigNumber - КОНЕЦ */

    /* ТЕСТ Huge - НАЧАЛО */
    Huge huge("987654321098765432100000000000000000356480324202655800003");
    cout << huge << endl;
    /* ТЕСТ Huge - НАЧАЛО */

    return a.exec();
}
