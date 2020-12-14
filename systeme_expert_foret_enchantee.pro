QT       += core gui
QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += -lOpengl32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agent_explorateur.cpp \
    case_carte.cpp \
    environement_foret.cpp \
    exploration_thread.cpp \
    fenetre_affichage_foret.cpp \
    main.cpp

HEADERS += \
    agent_explorateur.h \
    case_carte.h \
    environement_foret.h \
    exploration_thread.h \
    fenetre_affichage_foret.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
