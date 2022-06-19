@echo off
title qmake and nmake build prompt
set MINGW_PATH=D:\Application\Qt\Tools\mingw810_64
set QT_DIR=D:\Application\Qt\5.15.2\mingw81_64
set BUILD_DIR=%cd%\build
set PRO_DIR=%cd%
set PATH=%MINGW_PATH%\bin;%QT_DIR%\bin;%PATH%

if not exist %BUILD_DIR% (
    md %BUILD_DIR%
)

cd build
qmake.exe %PRO_DIR%\SerialAir.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=console"
if exist %BUILD_DIR%\debug\SerialAir.exe del %BUILD_DIR%\debug\SerialAir.exe
@REM D:\Application\Qt\Tools\QtCreator\bin\jom.exe -j4
%MINGW_PATH%\bin\mingw32-make -f Makefile.Debusg

cd debug
if not exist %BUILD_DIR%\debug\Qt5Core.dll (
    windeployqt SerialAir.exe
)

rem if exist %BUILD_DIR%\debug\SerialAir.exe start SerialAir.exe
rem sleep 3
rem exit
