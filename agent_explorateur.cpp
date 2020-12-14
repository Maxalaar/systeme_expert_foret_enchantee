#include "agent_explorateur.h"

#include "QDebug"

Agent_explorateur::Agent_explorateur(Environement_foret* foret)
{
    ajout_nouvel_environnement(foret);
}



int Agent_explorateur::deplacement(int x, int y)
{
    int taille_foret_y = foret->tableau[0].size();
    int taille_foret_x = foret->tableau.size();

    if(position_y != -1 && position_x != -1)
    {
        int int_prov = foret->element_sur_case(position_x, position_y, joueur);
        this->foret->tableau[position_x][position_y].remove(int_prov);

        int_prov = element_sur_case(position_x, position_y, joueur);
        this->carte_foret[position_x][position_y].liste_element.remove(int_prov);
    }

    position_x = x;
    position_y = y;

    carte_foret[x][y].liste_element = foret->tableau[x][y];
    foret->tableau[x][y].append(joueur);
    carte_foret[x][y].liste_element.append(joueur);

    //On marque les cases
    carte_foret[x][y].decouverte = true;
    carte_foret[x][y].valable = false;

    if(y + 1 < taille_foret_y && carte_foret[x][y+1].decouverte != true)
        carte_foret[x][y+1].valable = true;

    if(y - 1 >= 0 &&  carte_foret[x][y-1].decouverte != true)
        carte_foret[x][y-1].valable = true;

    if(x + 1 < taille_foret_x && carte_foret[x+1][y].decouverte != true)
        carte_foret[x+1][y].valable = true;

    if(x - 1 >= 0 &&  carte_foret[x-1][y].decouverte != true)
        carte_foret[x-1][y].valable = true;

    //On applique les element de la case
    for(int i = 0; i < carte_foret[x][y].liste_element.length(); i++)
    {
        if(carte_foret[x][y].liste_element[i] == sortie)
        {
            this->mes_performance += 10*taille_foret_x*taille_foret_y;
            return 1;
        }
        if(carte_foret[x][y].liste_element[i] == trou)
        {
            this->mes_performance -= 10*taille_foret_x*taille_foret_y;
            return -1;
        }
        if(carte_foret[x][y].liste_element[i] == vent)
        {
            //On regarde commbien de case adjacente pour coisire la pénaliter pour les case qui ne le sont pas decouverte
            int nombre_case_non_revele = 0;
            if(y + 1 < taille_foret_y && carte_foret[x][y+1].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            if(y - 1 >= 0 && carte_foret[x][y-1].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            if(x + 1 < taille_foret_x && carte_foret[x+1][y].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            if(x - 1 >= 0 && carte_foret[x-1][y].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            //On calcule les pénaliter
            int penaliter = 44 / nombre_case_non_revele;

            //On place les pénaliter
            if(y + 1 < taille_foret_y && carte_foret[x][y+1].decouverte == false)
            {
                carte_foret[x][y+1].desirabilite -= penaliter;
            }

            if(y - 1 >= 0 && carte_foret[x][y-1].decouverte == false)
            {
                carte_foret[x][y-1].desirabilite -= penaliter;
            }

            if(x + 1 < taille_foret_x && carte_foret[x+1][y].decouverte == false)
            {
                carte_foret[x+1][y].desirabilite -= penaliter;
            }

            if(x - 1 >= 0 && carte_foret[x-1][y].decouverte == false)
            {
                carte_foret[x-1][y].desirabilite -= penaliter;
            }
        }
        if(carte_foret[x][y].liste_element[i] == monstre)
        {
            this->mes_performance -= 10*taille_foret_x*taille_foret_y;
            return -1;
        }
        if(carte_foret[x][y].liste_element[i] == odeur)
        {
            //On regarde commbien de case adjacente pour coisire la pénaliter pour les case qui ne le sont pas decouverte
            int nombre_case_non_revele = 0;
            if(y + 1 < taille_foret_y && carte_foret[x][y+1].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            if(y - 1 >= 0 && carte_foret[x][y-1].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            if(x + 1 < taille_foret_x && carte_foret[x+1][y].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            if(x - 1 >= 0 && carte_foret[x-1][y].decouverte == false)
            {
                nombre_case_non_revele += 1;
            }

            //On calcule les pénaliter
            int penaliter = 40 / nombre_case_non_revele;

            if(y + 1 < taille_foret_y && carte_foret[x][y+1].decouverte == false)
            {
                carte_foret[x][y+1].desirabilite -= penaliter;
                carte_foret[x][y+1].risque_monstre += penaliter;
            }

            if(y - 1 >= 0 && carte_foret[x][y-1].decouverte == false)
            {
                carte_foret[x][y-1].desirabilite -= penaliter;
                carte_foret[x][y-1].risque_monstre += penaliter;
            }

            if(x + 1 < taille_foret_x && carte_foret[x+1][y].decouverte == false)
            {
                carte_foret[x+1][y].desirabilite -= penaliter;
                carte_foret[x+1][y].risque_monstre += penaliter;
            }

            if(x - 1 >= 0 && carte_foret[x-1][y].decouverte == false)
            {
                carte_foret[x-1][y].desirabilite -= penaliter;
                carte_foret[x-1][y].risque_monstre += penaliter;
            }
        }
        if(carte_foret[x][y].liste_element[i] == caillou)
            nombre_caillou += 1;
    }

    if((carte_foret[x][y].liste_element.length() == 1 && carte_foret[x][y].liste_element[0] == joueur) || carte_foret[x][y].liste_element.length() == 0)
    {
        if(y + 1 < taille_foret_y)
            carte_foret[x][y+1].desirabilite = 0;

        if(y - 1 >= 0)
            carte_foret[x][y-1].desirabilite = 0;

        if(x + 1 < taille_foret_x)
            carte_foret[x+1][y].desirabilite = 0;

        if(x - 1 >= 0)
            carte_foret[x-1][y].desirabilite = 0;
    }


    return 0;
}

int Agent_explorateur::action()
{
    int position_x_action = -1;
    int position_y_action = -1;
    double desirabilite_max_actuelle = -1000/*std::numeric_limits<double>::min()*/;

    for(int i = 0; i < this->carte_foret[0].length(); i++)
    {
        for(int j = 0; j < this->carte_foret.length(); j++)
        {
            if(carte_foret[i][j].valable == true && carte_foret[i][j].desirabilite > desirabilite_max_actuelle)
            {
                desirabilite_max_actuelle = carte_foret[i][j].desirabilite;
                position_x_action = i;
                position_y_action = j;
            }
        }
    }

    if(carte_foret[position_x_action][position_y_action].risque_monstre >= 20 && nombre_caillou > 0)
    {
        qDebug() << "L'agent lance un caillou en :" << position_x_action << "," << position_y_action;
        nombre_caillou -= 1;
        if (foret->element_sur_case(position_x, position_y, monstre) != -1)
        {
            foret->tableau[position_x_action][position_y_action].remove(foret->element_sur_case(position_x, position_y, monstre));
            qDebug() << "Monstre touché !";
        }
        else
        {
            qDebug() << "Il n'y a pas de monstre dommage...";
        }
        qDebug() << "Il reste :" << nombre_caillou << "caillou(x)";
    }

    qDebug() << "L'agent ce dépalce en : " << position_x_action << "," << position_y_action << " Mesure de performance : " << this->mes_performance;
    return deplacement(position_x_action, position_y_action);
}

int Agent_explorateur::element_sur_case(int x, int y, typeCase element)
{
    for(int i = 0; i < carte_foret[x][y].liste_element.length(); i++)
    {
        if(carte_foret[x][y].liste_element[i] == element)
        {

            return i;
        }
    }

    return -1;
}

void Agent_explorateur::ajout_nouvel_environnement(Environement_foret *foret)
{
    this->foret = foret;

    this->position_x = -1;
    this->position_y = -1;

    QVector<QVector<Case_carte>> carte_foret_vide;
    carte_foret = carte_foret_vide;

    for(int i = 0; i < this->foret->tableau.length(); i++)
    {
        QVector<Case_carte> ligne_case_prov;

        for(int j = 0; j < this->foret->tableau[0].length(); j++)
        {
            Case_carte case_prov(j, i);
            ligne_case_prov.append(case_prov);
        }
        this->carte_foret.push_back(ligne_case_prov);
    }

    int position_y;
    int position_x;
    do
    {
        position_y = QRandomGenerator::global()->bounded(foret->tableau[0].size());
        position_x = QRandomGenerator::global()->bounded(foret->tableau.size());
    }
    while(foret->element_sur_case(position_x, position_y, monstre) != -1 || foret->element_sur_case(position_x, position_y, trou) != -1 || foret->element_sur_case(position_x, position_y, odeur) != -1 || foret->element_sur_case(position_x, position_y, vent) != -1 || foret->element_sur_case(position_x, position_y, sortie) != -1);

    deplacement(position_x, position_y);
}

void Agent_explorateur::tout_reveler()
{
    for(int i = 0; i < this->carte_foret[0].length(); i++)
    {
        for(int j = 0; j < this->carte_foret.length(); j++)
        {
            carte_foret[i][j].liste_element = foret->tableau[i][j];
            carte_foret[i][j].decouverte = true;
            carte_foret[i][j].valable = false;
        }
    }
}
