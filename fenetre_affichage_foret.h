#ifndef FENETRE_AFFICHAGE_FORET_H
#define FENETRE_AFFICHAGE_FORET_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QDebug>
#include <QString>

#include "environement_foret.h"
#include "agent_explorateur.h"

class Fenetre_affichage_foret : public QOpenGLWindow
{
public:
    Fenetre_affichage_foret(Agent_explorateur* agent, QWidget *parent = nullptr);
    void rafraichissement_image();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    QOpenGLContext *context;
    QOpenGLFunctions *openGLFunctions;
    Agent_explorateur* agent;

public slots:
//    void rafraichissement_image(void);

};

#endif // FENETRE_AFFICHAGE_FORET_H
