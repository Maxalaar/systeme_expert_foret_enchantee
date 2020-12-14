#include "exploration_thread.h"

void Exploration_thread::run()
{
    int i = 0;
    Environement_foret* foret;
    while (true)
    {
        QThread::msleep(125);
        int resultat = agent->action();
        affichage->rafraichissement_image();

        if(resultat == 1)
        {
            agent->tout_reveler();
            QThread::msleep(2000);
            affichage->rafraichissement_image();
            i += 1;
            foret = new Environement_foret(agent->foret->tableau.length() + 1, agent->foret->tableau.length() + 1, 0.85, 0.05, 0.05, 0.025);
            agent->ajout_nouvel_environnement(foret);
        }

    }
}
