#include "fenetre_affichage_foret.h"

Fenetre_affichage_foret::Fenetre_affichage_foret(Environement_foret* foret, QWidget *parent)
{
    //Je ne sais pas tros a quoi tous ça sert
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1);

    setFormat(format);
    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    openGLFunctions = context->functions();

    //Là je comprend mieux a quoi ça sert
    this->setTitle("La Foret Enchantée");
    this->resize(1280, 960);
    this->foret = foret;
}

void Fenetre_affichage_foret::initializeGL()
{

}

void Fenetre_affichage_foret::resizeGL(int w, int h)
{

}

void Fenetre_affichage_foret::paintGL()
{
    //On colore le fond en blanc
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    //On construe l'affichage de la foret
    int foret_dimention_x = this->foret->tableau[0].size();
    int foret_dimention_y = this->foret->tableau.size();


    //On parcoure toutes les cellules du tableau est on affiche les entités
    for(int i = 0; i < foret_dimention_x; i++)
    {
        for(int j = 0; j < foret_dimention_y; j++)
        {
            //On affiche la sortie
            if(this->foret->tableau[i][j] == sortie)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(1,1,0);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            else if(this->foret->tableau[i][j] == trou)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0,0,1);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            else if(this->foret->tableau[i][j] == vent)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0.45, 0.45, 0.45);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            else if(this->foret->tableau[i][j] == monstre)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(1, 0, 0);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            else if(this->foret->tableau[i][j] == caillou)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(1, 0.2, 0.5);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
        }
    }

    //On designe les lignes verticale du plateau
    for(int i = 0; i < foret_dimention_x; i++)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
        glVertex2f(position_point_x, -1);
        glVertex2f(position_point_x, 1);
        glEnd();
    }

    //On desiinge les lignes horizontal du plateau
    for(int i = 0; i < foret_dimention_y; i++)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        double position_point_y = (double)((double)2 / (double)foret_dimention_y) * i - 1;
        glVertex2f(-1, position_point_y);
        glVertex2f(1, position_point_y);
        glEnd();
    }
}
