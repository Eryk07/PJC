#include <windows.h>
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <iostream>
#include <list>
#include <string>
#include "CMapa.h"

using namespace std;


void MoveAndCheckIfEndOfMap(CObjects *object, int step, int nXSize, int nYSize);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    static int nYSize = 600;
    static int nXSize = 600;

	CMapa mapka;

	CObjects* wtf = new CObjects;
	wtf->name = "dupa";

	CObjects* sd = new CObjects;
	sd->name = "ojoj";
	
	mapka.addToList(wtf);
	mapka.addToList(sd);

    QLabel *label=new QLabel(&w);

	for (int i = 0; i < 5; i++) {

       for (list<CObjects*>::iterator iter = mapka.objects.begin(); iter != mapka.objects.end(); iter++)
       {

       string x = to_string((*iter)->x);
       string y = to_string((*iter)->y);

      string str =( ((*iter)->name) + " x: " +x+ " y: "+y+"\n");
     QString tmp= QString::fromStdString(str);
      // cout<<str;
       label->setText(tmp);
       label->setAlignment(Qt::AlignCenter | Qt::AlignRight);
       label->show();

       }

		for (list<CObjects*>::iterator iter = mapka.objects.begin(); iter != mapka.objects.end(); iter++)
		{
			(*iter)->Move(10,nXSize,nYSize);
			//iter++;
		}

    Sleep(2000);
	}

    return a.exec();

}


void MoveAndCheckIfEndOfMap(CObjects* object, int step, int nXSize, int nYSize)
{
	static int Ix = step;
	static int Iy = step;

	((*object).x) = (*object).x + Ix;
	(*object).y = (*object).y + Iy;


	if (object->x >= nXSize - 50) // put the -50 else it'll let you to up to x point
	{
		object->x = nXSize - 50;
		Ix = -Ix++;// put ++ so its less predictable
	}

	if (object->y >= nYSize - 50)
	{
		object->y = nYSize - 50;
		Iy = -Iy++;
	}

	if (object->x < 50)
	{
		object->x = 50;
		Ix = -Ix;
	}

	if (object->y < 50)
	{
		object->y = 50;
		Iy = -Iy;
	}
}
