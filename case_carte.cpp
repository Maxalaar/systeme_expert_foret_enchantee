#include "case_carte.h"

Case_carte::Case_carte(int position_x, int position_y)
{
    decouverte = false;
    valable = false;
    desirabilite = 0;
    this->position_x = position_x;
    this->position_y = position_y;
}
