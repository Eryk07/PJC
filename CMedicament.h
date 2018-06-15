#ifndef CMEDICAMENT_H
#define CMEDICAMENT_H
#include "CNonMoving.h"
///Rozmiar leku
const int medicament_size = 10;
/** \brief  Definicja klasy CMedicament
*
*  Klasa odpowiada za zachowanie obiektów klasy CMedicament, która jest pochodną klasy CNonMoving na planszy.
* \see CNonMoving
* Klasa definiuje parametry i zachowanie leku na mapie.
*/
class CMedicament :public CNonMoving
{
public:
    /** \brief Konstruktor klasy CMedicament
    *
    * \param *m mapa na której znajduje się obiekt klasy CMedicament
    * \return obiekt klasy CMedicament
    */
    CMedicament(CMap *m);
    ///\brief Destruktor klasy CMedicament
    ~CMedicament();
    ///\brief Aktualizacja stanu obiektu lek
    void update();
    ///\brief Zebranie leku z mapy
    void get_Collected();
};

#endif // CMEDICAMENT_H
