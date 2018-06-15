#ifndef CNONMOVING_H
#define CNONMOVING_H
#include "CObject.h"
/** \brief  Definicja klasy CNonMoving
*
*  Klasa odpowiada za zachowanie obiektów klasy CNonMoving, która jest pochodną klasy CObject na planszy.
* \see CObject
* Klasa definiuje parametry i zachowanie obiektów nieruchomych na mapie.
*/
class CNonMoving :public CObject
{
protected:
    ///Wartość wyświetlana przez obiekt
    qreal value;
public:
    /** \brief Konstruktor klasy CNonMoving
    *
    * Konstruktor klasy CNonMoving, dziedziczony do klas pochodnych:
    * \see CMedicament
    * \see CDisease
    * \param xv początkowa pozycja obiektu w osi x
    * \param yv początkowa pozycja obiektu w osi y
    * \param anglev początkowy kąt obrócenia obiektu
    * \param rangev zakres obiektu
    * \param healthv zdrowie obiektu
    * \param valuev wartość jaką ma obiekt na mapie
    * \param *m mapa na której znajduje się obiekt
    * \return obiekt klasy CNonMoving
    */
    CNonMoving(qreal xv, qreal yv, qreal anglev, qreal rangev, qreal healthv, qreal valuev, CMap *m);
    /** \brief Zwracanie prywatnej wartości value
    * \return value
    */
    qreal get_value();
    /** \brief Uaktualnienie pozycji, stanu obiektu CNonMoving
    * Funkcja wirtualna dziedziczona do klas pochodnych
    */
    virtual void update()=0;
};

#endif // CNONMOVING_H
