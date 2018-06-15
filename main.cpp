#include <QApplication>
#include <QWidget>
#include "CProgram.h"
/**
* \mainpage
* \par Liszaj
* Program symulujący zarażanie się chorobami przez pacjentów i leczenie przez lekarzy.
* \author Eryk Kołodziejczyk
* \date 2018.06.14
* \version 1.0
* \par Kontakt:
* \a 278211@pw.edu.pl
*/

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    CProgram *program = new CProgram();

    return app.exec();
}
