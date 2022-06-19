#modules
QT += core gui widgets
# //@tag 1. 添加serialport模块
QT += serialport


CONFIG += c++17
win32-msvc*:QMAKE_CXXFLAGS += /utf-8
# QMAKE_LFLAGS += "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""


#sources
SOURCES += \
    $$files($$PWD/src/*.cpp)\
    $$files($$PWD/src/gobal/*.cpp)\
    $$files($$PWD/src/models/*.cpp)\
    $$files($$PWD/src/bridge/*.cpp)

HEADERS += \
    $$files($$PWD/src/*.h)\
    $$files($$PWD/src/gobal/*.h)\
    $$files($$PWD/src/models/*.h)\
    $$files($$PWD/src/bridge/*.h)


FORMS += $$PWD/src/mainwindow.ui

RESOURCES +=   \
    # $$PWD/libs/Material/components/*.qrc 直接这样写会报错
    $$PWD/libs/Material/components/resources.qrc


#includepath
INCLUDEPATH += "$$PWD/src/gobal"
INCLUDEPATH += "$$PWD/libs/Material/components" 
#libs
LIBS += $$PWD/libs/Material/staticlib/libcomponents.a
PRE_TARGETDEPS += $$PWD/libs/Material/staticlib/libcomponents.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
