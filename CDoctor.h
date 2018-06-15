#ifndef CDOCTOR_H
#define CDOCTOR_H
#include "CHuman.h"
#include "CMedicament.h"
#include "CPatient.h"
//class CPatient{};

/** \brief  Definicja klasy CDoctor
*
*  Klasa odpowiada za zachowanie obiektów klasy CDoctor, która jest pochodną klasy CHuman na planszy.
* \see CHuman
* Klasa definiuje parametry i zachowanie doktora na mapie.
*/

class CDoctor :public CHuman
{
protected:
    /// Wektor leków zebranych przez lekarza
    std::vector<CMedicament*> medicaments;
public:
    /** \brief Konstruktor klasy CDoctor
    *
    * \param *m mapa na której znajduje się obiekt klasy CDoctor
    * \return obiekt klasy CDoctor
    */
    CDoctor(CMap *m);
    ///\brief Destruktor klasy CDoctor
    ~CDoctor();
    ///\brief Ruch lekarza - szukanie lekarstw a potem pacjentów
    void move();
    /** \brief Aktualizacja stanu lekarza - zebranie leków, wizyt u pacjenta, zmiana ruchu
 *  Sprawdzenie obiektów z mapy, jeśli pacjent:
  *       najdzie na chorobę to się zaraża,
  *       spotka lekarza to zostaje wyleczony,
  *       spotka innego pacjenta lub najdzie na lek to ucieka,
  *       jeśli wyjdzie za granicę mapy to ucieka,
  *      jeśli nic nie ma w otoczeniu to znowu robi losowy ruch
 */
    void update();
    /** \brief Zebranie lekarstwa
    * \param *medicament wskaźnik na lek który zostaje zebrany
    */
    void collect(CMedicament *medicament);
    /** \brief Uleczenie człowieka
    * \param *man wskaźnik na człowieka, który zostaje uleczony
    */
    void cure(CHuman *man );

};
#endif // CDOCTOR_H

