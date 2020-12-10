#include <QApplication>

#include "environement_foret.h"
#include "fenetre_affichage_foret.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Environement_foret* foret_1 = new Environement_foret(100, 100, 0.85, 0.05, 0.05, 0.05);
    Fenetre_affichage_foret* fenetre_affichage_1 = new Fenetre_affichage_foret(foret_1);
    fenetre_affichage_1->show();

    return a.exec();
}
