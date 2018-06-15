#ifndef CPROGRAM_H
#define CPROGRAM_H
#include <QTimer>
#include <QWidget>
#include "CMap.h"
/** \brief  Definicja klasy CProgram
*
*  Klasa odpowiada za wyświetlanie programu, zawiera obiekt klasy CMap.
*  W klasie CProgram znajdują się parametry okna programu oraz inicjalizacja QTimer.
* \see CMap
*/
class CProgram :public QWidget
{
    Q_OBJECT
private:
///Mapa należąca do obiektu klasy CProgram
    CMap *map;
public:
    /** \brief Konstruktor klasy CProgram
    *
    * \return obiekt klasy CProgram
    */
    CProgram();
public slots:
    ///\brief Krok programu
    void step();
};

#endif // CPROGRAM_H
