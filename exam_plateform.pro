#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T12:54:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
QT       += printsupport

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
    source_vue/adminlistecompteframe.cpp \
    source_vue/adminlisteconcoursframe.cpp \
    source_vue/admincreerconcoursframe.cpp \
    source_vue/organisateurinscriptionframe.cpp \
    source_vue/organisateuraffichernotesframe.cpp \
    source_vue/organisteurvalidationframe.cpp \
    source_utile/downloadmanager.cpp \
    source_utile/uploadmanager.cpp \
    source_utile/filedownloader.cpp

HEADERS  += \
    include_entite/administrateur.h \
    include_entite/candidat.h \
    include_entite/candidature.h \
    include_entite/concours.h \
    include_entite/dossier.h \
    include_entite/groupe.h \
    include_entite/organisateur.h \
    include_entite/personne.h \
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
    include_vue/admincreecompteframe.h \
    include_vue/administrateurscreen.h \
    include_vue/voirprofilframe.h \
    include_vue/modifierprofilframe.h \
    include_vue/adminlistecompteframe.h \
    include_vue/adminlisteconcoursframe.h \
    include_vue/admincreerconcoursframe.h \
    include_vue/organisateurinscriptionframe.h \
    include_vue/organisateuraffichernotesframe.h \
    include_vue/organisteurvalidationframe.h \
    include_utile/downloadmanager.h \
    include_utile/uploadmanager.h \
    include_utile/filedownloader.h

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
    adminlistecompteframe.ui \
    adminlisteconcoursframe.ui \
    admincreerconcoursframe.ui \
    organisateurinscriptionframe.ui \
    organisateuraffichernotesframe.ui \
    organisteurvalidationframe.ui

    INCLUDEPATH += include_entite/ \
                   include_modele/ \
                   include_utile/ \
                   include_vue/


