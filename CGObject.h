#ifndef CGOBJECT_H
#define CGOBJECT_H
#include <QGraphicsItem>
#include <QPainter>
#include "CObject.h"

class CObject;
class CMap;
/** \brief  Definicja klasy CGObject
*
*  Klasa odpowiada za wyświetlanie graficznych odpowiedników obiektów klasy logicznej CObject.
*  * \see CObject
* Klasa jest matką pozostałych klas graficznych: CGDisease, CGDoctor, CGMedicament, CGPatient, .
*/
class CGObject :public QGraphicsItem
{
protected:
    ///Obiekt na który wskazuje obiekt graficzny
    CObject *object;
    ///Mapa na której znajduje się obiekt graficzny
    CMap *map;
public:
    /** \brief Konstruktor klasy CGObject, dziedziczony przez klasy pochodne
    *
    * \param *o wskaźnik na obiekt który graficznie przedstawia klasa CGObject
    * \return obiekt klasy CGObject
    */
    CGObject(CObject *o);
    /** \brief Wczytaj CObject
     * Wczytuje obiekt klasy CObject, ustale jego pozycję na mapie zgodnie z jego logiką
     *
    * \return obiekt typu CObject
    */
    CObject* get_CObject();
    /** \brief Namaluj w oknie
     *
    * \param painter "pędzel" malowania obiektu w oknie
    * \param option opcje widgetu
    * \param widget wskaźnik na okno
    */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget) = 0;
    /** \brief Prostokąt obiektu
     *
     * Funkcja wirtualna, dziedziczona do klas pochodnych
     * \return prostokąt typu QRectF
     */
    virtual QRectF boundingRect() const = 0;
    /** \brief Odśwież obiekt graficzny
     *
     * Funkcja wirtualna, dziedziczona do klas pochodnych
     */
     virtual void updateG() = 0;
};

#endif // CGOBJECT_H
