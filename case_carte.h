#ifndef CASE_CARTE_H
#define CASE_CARTE_H

#include "environement_foret.h"

class Case_carte
{
public:
    Case_carte(int position_x, int position_y);
    QVector<typeCase> liste_element;
    int desirabilite;
    bool decouverte;
    bool valable;
    int position_x;
    int position_y;
};

#endif // CASE_CARTE_H
