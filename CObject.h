#ifndef COBJECT_H
#define COBJECT_H
#include <QGraphicsItem>
#include "CMap.h"
class CMap;

/** \brief  Definicja klasy CObject
*
*  Klasa odpowiada za zachowanie obiektów klasy CObject, która jest matką innych klas logicznych programu.
* \see CObject
* Klasa definiuje parametry obiektu.
*/
class CObject
{
protected:
    ///Połozenie obiektu w osi x
    qreal x;
    ///Połozenie obiektu w osi y
    qreal y;
    ///Kąt obrócenia obiektu
    qreal angle;
    ///Zakres obiektu
    qreal range;
    ///Zdrowie obiektu
    qreal  health;
    ///Mapa obiektu
    CMap *map;
public:
    /** \brief Konstruktor klasy CObject
    *
    * Konstruktor klasy CObject, dziedziczony do klas pochodnych:
    * \see CNonMoving
    * \see CHuman
    * \param xv początkowa pozycja obiektu w osi x
    * \param yv początkowa pozycja obiektu w osi y
    * \param anglev początkowy kąt obrócenia obiektu
    * \param rangev zakres obiektu
    * \param healthv zdrowie obiektu
    * \param *m mapa na której znajduje się obiekt
    * \return obiekt klasy CObject
    */
    CObject(qreal xv, qreal yv, qreal anglev, qreal rangev, qreal healthv, CMap *m);
    /** \brief Zwracanie chronionej wartości x
    * \return x
    */
    qreal get_x();
    /** \brief Zwracanie chronionej wartości y
    * \return y
    */
    qreal get_y();
    /** \brief Zwracanie chronionej wartości angle
    * \return angle
    */
    qreal get_angle();
    /** \brief Zwracanie chronionej wartości range
    * \return range
    */
    qreal get_range();
    /** \brief Zwracanie chronionej wartości health
    * \return health
    */
    qreal get_health();
    /** \brief Zwracanie chronionej wartości map
    * \return map
    */
    CMap *get_map();
    /** \brief Uaktualnienie pozycji, stanu obiektu CObject
    * Funkcja wirtualna dziedziczona do klas pochodnych
    */
    virtual void update()=0;
};

#endif // COBJECT_H
