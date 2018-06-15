#ifndef CMAP_H
#define CMAP_H
#include "CGObject.h"
#include "CObject.h"
#include <QGraphicsScene>
///granica mapy
const int map_border = 800;

class CObject;
class CGObject;
/** \brief  Definicja klasy CMap
*
*  Klasa odpowiada za wyświetlanie zawartych w niej obiektów graficznych klasy CGObject.
* \see CGObject
*/
class CMap
{
private:
    /// Scena programu
    QGraphicsScene *scene;
    /// Wektor obiektów
    std::vector<CObject*> ObjectList;
    /// Wektor obiektów graficznych
    std::vector<CGObject*> GObjectList;
public:
    /** \brief Konstruktor klasy CMap
    *
    * \param *scene wskaźnik na scenę wyświetlaną w oknie
    * \return obiekt klasy CMap
    */
    CMap(QGraphicsScene *scene);
     /** \brief Zebranie obiektów w pobliżu danego obiektu
    * \param *o wskaźnik na dany obiekt
    * \return wektor obiektów w pobliżu danego obiektu
    */
    std::vector<CObject*> get_nearObjList(CObject *o);
    /** \brief Zebranie obiektów graficznych w pobliżu danego obiektu graficznego
   * \param *go wskaźnik na dany obiekt graficzny
   *  \return wektor obiektów graaficznych w pobliżu danego obiektu graficznego
   */
    std::vector<CGObject*> get_nearObjGList(CGObject *go);
    /** \brief Dodanie danego obiektu do wektora obiektów mapy
    * \param *object wskaźnik na dany obiekt
    */
    void addObject(CObject *object);
    /** \brief Dodanie danego obiektu graficznego do wektora obiektów graficznych mapy
    * \param *gobject wskaźnik na dany obiekt graficzny
    */
    void addGObject(CGObject *gobject);
    /** \brief Usunięcie obiektu i jego graficznego odpowiednika z mapy
    * \param *o wskaźnik na dany obiek
    */
    void deleteFromMap(CObject *o);

    friend class CProgram;
};
#endif // CMAP_H
