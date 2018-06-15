#ifndef CGDOCTOR_H
#define CGDOCTOR_H
#include "CGObject.h"
#include "CDoctor.h"
/** \brief  Definicja klasy CGDoctor
*
*  Klasa odpowiada za wyświetlanie graficznych odpowiedników obiektów klasy logicznej CDoctor
*  * \see CDoctor
* Klasa wyświetla lekarza zgodnie z parametrami logicznymi zebranymi w klasie CDoctor.
*/
class CGDoctor :public CGObject
{
public:
    /** \brief Konstruktor klasy CGDoctor
    *
    * \param *o wskaźnik na obiekt który graficznie przedstawia klasa CGDoctor
    * \return obiekt klasy CGDoctor
    */
    CGDoctor(CObject *o);
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

#endif // CGDOCTOR_H
