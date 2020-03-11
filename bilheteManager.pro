QT += core network quick printsupport sql quickcontrols2 concurrent widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../../testeRodarHttpWidgts/requesthttp.cpp \
        bilheteentradaousaida/bilheteentradaousaida.cpp \
        bilheteformatar.cpp \
        cabecalhobilhete.cpp \
        centrobilhete.cpp \
        configbancogeral.cpp \
        control.cpp \
        gerararquivopdf.cpp \
        main.cpp \
        salvartextstring.cpp \
        telaconfiggeral/telaconfiggeral.cpp \
        tododto.cpp \
        tododtoinformacoesteladebusca.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../../../testeRodarHttpWidgts/requesthttp.h \
    bilheteentradaousaida/bilheteentradaousaida.h \
    bilheteformatar.h \
    cabecalhobilhete.h \
    centrobilhete.h \
    configbancogeral.h \
    control.h \
    gerararquivopdf.h \
    salvartextstring.h \
    telaconfiggeral/telaconfiggeral.h \
    tododto.h \
    tododtoinformacoesteladebusca.h \

DISTFILES += \
    ../../../Downloads/img10.png \
    ../../../Downloads/img12.jpg \
    ../../../Downloads/img2.png \
    ../../../Downloads/img3.png \
    ../../../Downloads/img4.png \
    ../../../Downloads/img5.png \
    ../../../Downloads/img6.png \
    ../../../Downloads/img7.png \
    ../../../Downloads/img8.png \
    ../../../Downloads/img9.png
