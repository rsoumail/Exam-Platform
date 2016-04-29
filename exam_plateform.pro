#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T12:54:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_plateform
TEMPLATE = app


SOURCES += \
    source_entite/administrateur.cpp \
    source_entite/candidat.cpp \
    source_entite/candidature.cpp \
    source_entite/concours.cpp \
    source_entite/dossier.cpp \
    source_entite/groupe.cpp \
    source_entite/organisateur.cpp \
    source_entite/personne.cpp \
    source_modele/administrateur_manager.cpp \
    source_modele/candidat_manager.cpp \
    source_modele/candidature_manager.cpp \
    source_modele/concours_manager.cpp \
    source_modele/dossier_manager.cpp \
    source_modele/groupe_manager.cpp \
    source_modele/organisateur_manager.cpp \
    source_utile/fonctions.cpp \
    source_vue/candidatscreen.cpp \
    source_vue/connexion.cpp \
    source_vue/creecompteframe.cpp \
    source_vue/demandescandidatureframe.cpp \
    source_vue/dossieraccepteframe.cpp \
    source_vue/dossierrejeteframe.cpp \
    source_vue/listeadmisframe.cpp \
    source_vue/listeechouesframe.cpp \
    source_vue/main.cpp \
    source_vue/mondossierframe.cpp \
    source_vue/monresultatframe.cpp \
    source_vue/organisateurscreen.cpp \
    source_vue/register.cpp \
    source_entite/utilisateur.cpp \
    source_utile/httpdownloader.cpp \
    source_vue/admincreecompteframe.cpp \
    source_vue/administrateurscreen.cpp \
    source_vue/voirprofilframe.cpp \
    source_vue/modifierprofilframe.cpp \
    source_vue/adminlistecompteframe.cpp

HEADERS  += \
    include_entite/administrateur.h \
    include_entite/candidat.h \
    include_entite/candidature.h \
    include_entite/concours.h \
    include_entite/dossier.h \
    include_entite/groupe.h \
    include_entite/organisateur.h \
    include_entite/personne.h \
    include_libxl/enum.h \
    include_libxl/IBookT.h \
    include_libxl/IFontT.h \
    include_libxl/IFormatT.h \
    include_libxl/ISheetT.h \
    include_libxl/libxl.h \
    include_libxl/setup.h \
    include_modele/administrateur_manager.h \
    include_modele/candidat_manager.h \
    include_modele/candidature_manager.h \
    include_modele/concours_manager.h \
    include_modele/dossier_manager.h \
    include_modele/groupe_manager.h \
    include_modele/organisateur_manager.h \
    include_utile/fonctions.h \
    include_vue/candidatscreen.h \
    include_vue/connexion.h \
    include_vue/creecompteframe.h \
    include_vue/demandescandidatureframe.h \
    include_vue/dossieraccepteframe.h \
    include_vue/dossierrejeteframe.h \
    include_vue/listeadmisframe.h \
    include_vue/listeechouesframe.h \
    include_vue/mondossierframe.h \
    include_vue/monresultatframe.h \
    include_vue/organisateurscreen.h \
    include_vue/register.h \
    include_entite/utilisateur.h \
    include_utile/httpdownloader.h \
    include_utile/httpdownloader.h \
    include_vue/admincreecompteframe.h \
    include_vue/administrateurscreen.h \
    include_vue/voirprofilframe.h \
    include_vue/modifierprofilframe.h \
    include_vue/adminlistecompteframe.h

FORMS    += connexion.ui \
    register.ui \
    candidatscreen.ui \
    mondossierframe.ui \
    dossieraccepteframe.ui \
    dossierrejeteframe.ui \
    monresultatframe.ui \
    listeadmisframe.ui \
    listeechouesframe.ui \
    organisateurscreen.ui \
    demandescandidatureframe.ui \
    creecompteframe.ui \
    administrateurscreen.ui \
    admincreecompteframe.ui \
    voirprofilframe.ui \
    modifierprofilframe.ui \
    adminlistecompteframe.ui


win32 {

    INCLUDEPATH = ../../../include_cpp
    LIBS += ../../../lib/libxl.lib

    QMAKE_POST_LINK +=$$quote(cmd /c copy /y ..\..\..\bin\libxl.dll .)

} else:macx {

    INCLUDEPATH = ../../include_cpp
    LIBS += -framework LibXL

    QMAKE_LFLAGS += -F../../
    QMAKE_POST_LINK +=$$quote(mkdir $${TARGET}.app/Contents/Frameworks;cp -R ../../LibXL.framework $${TARGET}.app/Contents/Frameworks/)

} else {

    INCLUDEPATH += include_libxl/ \
                   include_entite/ \
                   include_modele/ \
                   include_utile/ \
                   include_vue/


    LIBS += lib64/libxl.so

    QMAKE_LFLAGS_DEBUG = "-Wl,-rpath,lib64/"
    QMAKE_LFLAGS_RELEASE = "-Wl,-rpath,lib64/"
}
