#include "exploration_thread.h"

void Exploration_thread::run()
{
    Environement_foret* foret;
    while (true)
    {
        QThread::msleep(250);
        int resultat = agent->action();
        affichage->rafraichissement_image();

        if(resultat == 1)
        {
            agent->tout_reveler();
            affichage->rafraichissement_image();
            QThread::msleep(3000);

            foret = new Environement_foret(agent->foret->tableau.length() + 1, agent->foret->tableau.length() + 1, 0.60, 0.30, 0.05, 0.05);
            agent->ajout_nouvel_environnement(foret);
        }

    }
}
