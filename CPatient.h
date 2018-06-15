#ifndef CPATIENT_H
#define CPATIENT_H
#include "CHuman.h"
#include "CDisease.h"
#include "CDoctor.h"

/** \brief  Definicja klasy CPatient
*
*  Klasa odpowiada za zachowanie obiektów klasy CPatient, która jest pochodną klasy CHuman na planszy.
* \see CPatient
* Klasa definiuje parametry i zachowanie pacjenta na mapie.
*/
class CPatient :public CHuman
{
protected:
    /// Wektor chorób pacjenta
    std::vector<CDisease*> diseases;
public:
    /** \brief Konstruktor klasy CPatient
    *
    * \param m mapa na której znajduje się obiekt klasy CPatient
    * \return obiekt klasy CPatient
    */
    CPatient(CMap *m);
  ///\brief Domyślny destruktor
    ~CPatient();
   ///\brief Ruch pacjenta, jeśli nie ma żadnego obiektu w pobliżu to chodzi losowo
    void move();
    /** \brief Aktualizacja stanu pacjenta - zebranie chorób, wizyt lekarza, zmiana ruchu
 * Sprawdzenie obiektów z mapy, jeśli pacjent:
   *     najdzie na chorobę to się zaraża,
   *     spotka lekarza to zostaje wyleczony,
   *     spotka innego pacjenta lub najdzie na lek to ucieka,
   *     jeśli wyjdzie za granicę mapy to ucieka,
   *    jeśli nic nie ma w otoczeniu to znowu robi losowy ruch
 */
    void update();
    /** \brief Zarażenie się pacjenta
    * \param *disease wskaźnik na chorobę którą zaraża się pacjent
    */
    void get_infected(CDisease *disease);
    ///\brief Zachorowanie pacjenta - maleje zdrowie
    void reduce_health();
    ///\brief Jeśli zdrowie równe 0 - pacjent umiera :(
    void die();
};

#endif // CPATIENT_H
