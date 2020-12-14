#include "fenetre_affichage_foret.h"

Fenetre_affichage_foret::Fenetre_affichage_foret(Agent_explorateur* agent, QWidget *parent)
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
    this->agent = agent;
}

void Fenetre_affichage_foret::rafraichissement_image()
{
    resize(width(), height()-1);
    resize(width(), height()+1);
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
    int foret_dimention_x = this->agent->carte_foret[0].size();
    int foret_dimention_y = this->agent->carte_foret.size();


    //On parcoure toutes les cellules du tableau est on affiche les entités
    for(int i = 0; i < foret_dimention_y; i++)
    {
        for(int j = 0; j < foret_dimention_x; j++)
        {
            //On affiche la sortie
            if(this->agent->carte_foret[i][j].decouverte == false)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0,0,0);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            if(this->agent->carte_foret[i][j].valable == true)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0.5,0.5,0.5);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            if(this->agent->element_sur_case(i, j, sortie) != -1)
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
            if(this->agent->element_sur_case(i, j, vent) != -1)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0.25,0.6,1);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            if(this->agent->element_sur_case(i, j, trou) != -1)
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
            if(this->agent->element_sur_case(i, j, odeur) != -1)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0.6, 0.4, 0.12);
                glVertex2f(position_point_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y);
                glVertex2f(position_point_x + taille_case_x, position_point_y + taille_case_y);
                glVertex2f(position_point_x, position_point_y + taille_case_y);
                glEnd();
            }
            if(this->agent->element_sur_case(i, j, monstre) != -1)
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
            if(this->agent->element_sur_case(i, j, joueur) != -1)
            {
                double position_point_x = (double)((double)2 / (double)foret_dimention_x) * i - 1;
                double position_point_y = (double)((double)2 / (double)foret_dimention_y) * j - 1;

                double taille_case_x = (double)2 / (double)foret_dimention_x;
                double taille_case_y = (double)2 / (double)foret_dimention_y;

                glBegin(GL_POLYGON);
                glColor3f(0.93, 0.5, 0.93);
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
