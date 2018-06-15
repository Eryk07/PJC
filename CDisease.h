#ifndef CDISEASE_H
#define CDISEASE_H
#include "CNonMoving.h"

/** \brief  Definicja klasy CDisease
*
*  Klasa odpowiada za zachowanie obiektów klasy CDisease, która jest pochodną klasy CNonMoving na planszy.
* \see CNonMoving
* Klasa definiuje parametry i zachowanie choroby na mapie.
*/

class CDisease :public CNonMoving
{

public:
   /** \brief Konstruktor klasy CDisease
   *
   * \param *m mapa na której znajduje się obiekt klasy CDisease
   * \return obiekt klasy CDisease
   */
    CDisease(CMap *m);
    ///\brief Destruktor klasy CDisease
    ~CDisease();
    ///\brief Aktualizacja stanu obiektu choroba
    void update();
   ///\brief Infekcja pacjenta który przeszedł przez chorobę
    void infect();
};

#endif // CDISEASE_H
