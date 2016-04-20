#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T12:54:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_plateform
TEMPLATE = app


SOURCES += main.cpp\
        connexion.cpp \
    register.cpp \
    candidatscreen.cpp \
    mondossierframe.cpp \
    dossieraccepteframe.cpp \
    dossierrejeteframe.cpp \
    monresultatframe.cpp \
    listeadmisframe.cpp \
    listeechouesframe.cpp \
    organisateurscreen.cpp \
    demandescandidatureframe.cpp

HEADERS  += connexion.h \
    register.h \
    candidatscreen.h \
    mondossierframe.h \
    dossieraccepteframe.h \
    dossierrejeteframe.h \
    monresultatframe.h \
    listeadmisframe.h \
    listeechouesframe.h \
    organisateurscreen.h \
    demandescandidatureframe.h

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
    demandescandidatureframe.ui


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

    INCLUDEPATH = ../../include_cpp
    LIBS += lib64/libxl.so

    QMAKE_LFLAGS_DEBUG = "-Wl,-rpath,lib64/"
    QMAKE_LFLAGS_RELEASE = "-Wl,-rpath,lib64/"
}
