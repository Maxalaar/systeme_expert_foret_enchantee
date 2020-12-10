#ifndef ENVIRONEMENT_FORET_H
#define ENVIRONEMENT_FORET_H

#include <QVector>
#include <QRandomGenerator>

enum typeCase {vide, trou, vent, caillou, monstre, sortie, joueur};

class Environement_foret
{
public:
    Environement_foret(int taille_foret_x, int taille_foret_y, double proba_vide, double proba_trou, double proba_monstre, double proba_caillou);
    QVector<QVector<typeCase>> tableau;
};

#endif // ENVIRONEMENT_FORET_H
