TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += ZMQ_STATIC
LIBS += -L$$PWD/../lib -lzmq -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += main.cpp \
    Dobbelsteen.cpp \
    InputUtils.cpp \
    cards.cpp \
    functies.cpp \
    playcards.cpp \
    playdice.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Dobbelsteen.h \
    InputUtils.h \
    cards.h \
    functies.h \
    playcards.h \
    playdice.h
