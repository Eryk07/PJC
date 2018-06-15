#ifndef CGMEDICAMENT_H
#define CGMEDICAMENT_H
#include "CGObject.h"
#include "CMedicament.h"
/** \brief  Definicja klasy CGMedicament
*
*  Klasa odpowiada za wyświetlanie graficznych odpowiedników obiektów klasy logicznej CMedicament.
*  * \see CMedicament
* Klasa wyświetla lek zgodnie z parametrami logicznymi zebranymi w klasie CMedicament.
*/
class CGMedicament :public CGObject
{
public:
    /** \brief Konstruktor klasy CGMedicament
    *
    * \param *o wskaźnik na obiekt który graficznie przedstawia klasa CGMedicament
    * \return obiekt klasy CGMedicament
    */
    CGMedicament(CObject *o);
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
    /** \brief Przezroczystość obiektu CGMedicament
     * \return przezroczystość obiektu
     */
    qreal opacity();

};

#endif // CGMEDICAMENT_H
