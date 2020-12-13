#ifndef EXPLORATION_THREAD_H
#define EXPLORATION_THREAD_H

#include <QThread>

#include "agent_explorateur.h"
#include "fenetre_affichage_foret.h"

class Exploration_thread : public QThread
{
    Q_OBJECT
public:
    void run();
    Agent_explorateur* agent;
    Fenetre_affichage_foret* affichage;
};

#endif // EXPLORATION_THREAD_H
