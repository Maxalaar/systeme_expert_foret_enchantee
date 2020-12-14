#ifndef AGENT_EXPLORATEUR_H
#define AGENT_EXPLORATEUR_H

#include "environement_foret.h"
#include "case_carte.h"

class Agent_explorateur
{
public:
    Agent_explorateur(Environement_foret* foret);
    int deplacement(int x, int y);
    int action();
    QVector<QVector<Case_carte>> carte_foret;
    int element_sur_case(int x, int y, typeCase element);
    void ajout_nouvel_environnement(Environement_foret* foret);
    Environement_foret* foret;
    void tout_reveler();

private:
    int temps_action = 100;
    int position_y;
    int position_x;
    int mes_performance = 0;
    int nombre_caillou = 0;
};

#endif // AGENT_EXPLORATEUR_H
