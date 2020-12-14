#include "environement_foret.h"

#include "QDebug"

Environement_foret::Environement_foret(int taille_foret_x, int taille_foret_y, double proba_vide, double proba_trou, double proba_monstre, double proba_caillou)
{
    //On crée un tableau vide
    for(int i = 0; i < taille_foret_y; i++)
    {
        QVector<QVector<typeCase>> ligne_case_prov;

        for(int j = 0; j < taille_foret_x; j++)
        {
            ligne_case_prov;
            QVector<typeCase> case_prov;
            ligne_case_prov.append(case_prov);
        }
        this->tableau.push_back(ligne_case_prov);
    }

    //On place la sortie
    int position_y = QRandomGenerator::global()->bounded(tableau[0].size());
    int position_x = QRandomGenerator::global()->bounded(tableau.size());
    this->tableau[position_x][position_y].push_back(sortie);

    //On place les éléments du jeu
    for(int i = 0; i < taille_foret_y; i++)
    {
        for(int j = 0; j < taille_foret_x; j++)
        {
            double valeur_alea = QRandomGenerator::global()->generateDouble() * (proba_vide + proba_trou + proba_monstre + proba_caillou);
            //La case est vide
            if(valeur_alea <= proba_vide && element_sur_case(i, j, sortie) == -1){
            }
            //On crée les trous
            else if(valeur_alea <= proba_vide + proba_trou && element_sur_case(i, j, sortie) == -1)
            {
                this->tableau[i][j].append(trou);

                //On crée les cases avec du vent
                if(i + 1 < taille_foret_y)
                    this->tableau[i+1][j].append(vent);

                if(i - 1 >= 0)
                    this->tableau[i-1][j].append(vent);

                if(j + 1 < taille_foret_x)
                    this->tableau[i][j+1].append(vent);

                if(j - 1 >= 0)
                    this->tableau[i][j-1].append(vent);

            }
            //On crée les monstres
            else if(valeur_alea <= proba_vide + proba_trou + proba_monstre && element_sur_case(i, j, sortie) == -1)
            {
                this->tableau[i][j].append(monstre);
                //On crée les cases avec des odeurs
                if(i + 1 < taille_foret_y)
                    this->tableau[i+1][j].append(odeur);

                if(i - 1 >= 0)
                    this->tableau[i-1][j].append(odeur);

                if(j + 1 < taille_foret_x)
                    this->tableau[i][j+1].append(odeur);

                if(j - 1 >= 0)
                    this->tableau[i][j-1].append(odeur);
            }
            //On crée les caillou
            else if(element_sur_case(i, j, sortie) == -1)
            {
                this->tableau[i][j].append(caillou);
            }
        }
    }
}


int Environement_foret::element_sur_case(int x, int y, typeCase element)
{
    for(int i = 0; i < tableau[x][y].length(); i++)
    {
        if(tableau[x][y][i] == element)
        {

            return i;
        }
    }

    return -1;
}
