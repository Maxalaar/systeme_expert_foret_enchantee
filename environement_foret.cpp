#include "environement_foret.h"

Environement_foret::Environement_foret(int taille_foret_x, int taille_foret_y, double proba_vide, double proba_trou, double proba_monstre, double proba_caillou)
{
    //On crée un tableau vide
    for(int i = 0; i < taille_foret_y; i++)
    {
        QVector<typeCase> ligne_case_prov;

        for(int j = 0; j < taille_foret_x; j++)
        {
            ligne_case_prov.push_back(vide);
        }

        this->tableau.push_back(ligne_case_prov);
    }

    //On place la sortie
    int position_x = QRandomGenerator::global()->bounded(tableau[0].size());
    int position_y = QRandomGenerator::global()->bounded(tableau.size());
    this->tableau[position_x][position_y] = sortie;


    //On place les éléments du jeu
    for(int i = 0; i < taille_foret_x; i++)
    {
        for(int j = 0; j < taille_foret_y; j++)
        {
            double valeur_alea = QRandomGenerator::global()->generateDouble() * (proba_vide + proba_trou + proba_monstre + proba_caillou);

            //La case est vide
            if(valeur_alea <= proba_vide && this->tableau[i][j] != sortie){

            }
            //On crée les trous
            else if(valeur_alea <= proba_vide + proba_trou && this->tableau[i][j] != sortie)
            {
                this->tableau[i][j] = trou;

                //On crée les cases avec du vent
                if(i + 1 < taille_foret_x && tableau[i+1][j] != sortie && this->tableau[i+1][j] != trou)
                    this->tableau[i+1][j] = vent;

                if(i - 1 >= 0 && tableau[i-1][j] != sortie && this->tableau[i-1][j] != trou)
                    this->tableau[i-1][j] = vent;

                if(j + 1 < taille_foret_y && tableau[i][j + 1] != sortie && this->tableau[i][j+1] != trou)
                    this->tableau[i][j + 1] = vent;

                if(j - 1 >= 0 && tableau[i][j-1] != sortie && this->tableau[i][j-1] != trou)
                    this->tableau[i][j - 1] = vent;

            }
            //On crée les monstres
            else if(valeur_alea <= proba_vide + proba_trou + proba_monstre && this->tableau[i][j] != sortie && this->tableau[i][j] != trou && this->tableau[i][j] != vent)
            {
                this->tableau[i][j] = monstre;
            }
            //On crée les caillou
            else if(this->tableau[i][j] != sortie && this->tableau[i][j] != trou && this->tableau[i][j] != vent)
            {
                this->tableau[i][j] = caillou;
            }
        }
    }
}
