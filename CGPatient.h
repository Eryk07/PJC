#ifndef CGPATIENT_H
#define CGPATIENT_H
#include "CGObject.h"
#include "CPatient.h"
#include <QRandomGenerator>
/** \brief  Definicja klasy CGPatient
*
*  Klasa odpowiada za wyświetlanie graficznych odpowiedników obiektów klasy logicznej CPatient.
*  * \see CPatient
* Klasa wyświetla pacjenta zgodnie z parametrami logicznymi zebranymi w klasie CPatient.
*/
class CGPatient :public CGObject
{
public:
    /** \brief Konstruktor klasy CGPatient
    *
    * \param *o wskaźnik na obiekt który graficznie przedstawia klasa CGPatient
    * \return obiekt klasy CGPatient
    */
    CGPatient(CObject *o);
    /** \brief Kształt obiektu graficzengo
     *
     * Funkcja nadpisuje funkcję o tej samej nazwie z klasy matki
    * \return ścieżka namalowanego obiektu
    */
    QPainterPath shape() const override;
    /** \brief Namaluj w oknie
     *
    * \param painter "pędzel" malowania obiektu w oknie
    * \param option opcje widgetu
    * \param widget wskaźnik na okno
    */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    /** \brief Prostokąt obiektu
     *
     * Funkcja nadpisuje funkcję o tej samej nazwie z klasy matki
     * \return prostokąt typu QRectF
     */
    QRectF boundingRect() const override;
    /** \brief Odśwież obiekt graficzny
     *
     * Funkcja nadpisuje funkcję o tej samej nazwie z klasy matki
     */
    void updateG() override;
};

#endif // CGPATIENT_H
