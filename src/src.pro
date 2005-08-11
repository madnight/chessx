# Plik utworzony przez menad?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: ./src
# Cel to program:  ../bin/chessdatabase

SOURCES += main.cpp 
INCLUDEPATH += ./database ./gui
TEMPLATE = app
CONFIG += release warn_on thread qt
QT += qt3support
INCLUDEPATH += compatibility
QT34 = compatibility/qt34
win32{
  TARGET = ../../bin/chessdatabase
  release{
    LIBS += gui/release/libgui.a database/release/libdatabase.a
  }
  else{
    LIBS += gui/debug/libgui.a database/debug/libdatabase.a
  }
}
else{
  TARGET = ../bin/chessdatabase
  LIBS += gui/libgui.a database/libdatabase.a
}
