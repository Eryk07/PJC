#ifndef CGDISEASE_H
#define CGDISEASE_H
#include "CGObject.h"
#include "CDisease.h"
/** \brief  Definicja klasy CGDisease
*
*  Klasa odpowiada za wyświetlanie graficznych odpowiedników obiektów klasy logicznej CDisease.
*  * \see CDisease
* Klasa wyświetla chorobę zgodnie z parametrami logicznymi zebranymi w klasie CDisease.
*/
class CGDisease :public CGObject
{
public:
    /** \brief Konstruktor klasy CGDisease
    *
    * \param *o wskaźnik na obiekt który graficznie przedstawia klasa CGDisease
    * \return obiekt klasy CGDisease
    */
    CGDisease(CObject *o);
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

#endif // CGDISEASE_H
