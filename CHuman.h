#ifndef CHUMAN_H
#define CHUMAN_H
#include "CObject.h"
#include "CNonMoving.h"
///Szerokość obiektu CHuman
const int man_width = 25;
///Wysokość obiektu CHuman
const int man_height = 20;
///Prędkość obiektu CHuman
const int man_speed = 10;
/** \brief  Definicja klasy CHuman
*
*  Klasa odpowiada za zachowanie obiektów klasy CHuman, która jest pochodną klasy CObject na planszy.
* \see CObject
* Klasa definiuje parametry i zachowanie człowieka na mapie.
*/
class CHuman :public CObject
{   
public:
    /** \brief Konstruktor klasy CHuman
    *
    * Konstruktor klasy CHuman, dziedziczony do klas pochodnych:
    * \see CDoctor
    * \see CPatient
    * \param xv początkowa pozycja obiektu w osi x
    * \param yv początkowa pozycja obiektu w osi y
    * \param anglev początkowy kąt obrócenia obiektu
    * \param rangev zakres obiektu
    * \param healthv zdrowie obiektu
    * \param *m mapa na której znajduje się obiekt
    * \return obiekt klasy CHuman
    */
   CHuman(qreal xv, qreal yv, qreal anglev, qreal rangev,qreal healthv, CMap *m);
   /** \brief Uaktualnienie pozycji, stanu obiektu CHuman
   * Funkcja wirtualna dziedziczona do klas pochodnych
   */
   virtual void update()=0;
   /** \brief Ruch obiektu
   * Funkcja wirtualna dziedziczona do klas pochodnych
   */
    virtual void move()=0;
   /** \brief Losowy ruch obiektu
   * Losowy ruch obiektu, używany w przypadku gdy obiekt nie ma żadnych zadań
   * w danej chwili
   */
    void move_randomly();
    /** \brief Opuść granice mapy
    * Ruch obiektu w przypadku gdy wyjedzie poza mapę
    */
    void leave_border();
    /** \brief Idź do obiektu
    * Ruch obiektu CHuman w stronę wybranego obiektu na mapie
    * \param *o wskaźnik na docelowy obiekt
    */
    void go_to(CObject *o);
    /** \brief Zawróć
    * Zawracanie przedwybranymi obiektami klasy CNonMoving i CHuman
    * \param o wektor obiektów nieruchomych CNonMoving
    * \param  man wektor obiektów ludzkich CHuman
    */
    void get_back(std::vector<CNonMoving*> o, std::vector<CHuman*> man);
    ///\brief Uleczenie człoweka - zdrowie rośnie
    void get_cure();
};
#endif // CHUMAN_H
