#include <QApplication>

#include "environement_foret.h"
#include "fenetre_affichage_foret.h"
#include "agent_explorateur.h"
#include "exploration_thread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Environement_foret* foret_1 = new Environement_foret(3, 3, 0.85, 0.05, 0.05, 0.05);

    Agent_explorateur* agent_explorateur = new Agent_explorateur(foret_1);

    Fenetre_affichage_foret* fenetre_affichage_1 = new Fenetre_affichage_foret(agent_explorateur);

    Exploration_thread* exploration_thread = new Exploration_thread();
    exploration_thread->agent = agent_explorateur;
    exploration_thread->affichage = fenetre_affichage_1;
    exploration_thread->start();

    fenetre_affichage_1->show();

//    agent_explorateur->deplacement(0, 0);

    return a.exec();
}
