@echo off
setlocal enabledelayedexpansion

echo setting up compile command and flags

:: Compiler und Flags setzen
set compiler=g++
set FLAGS= 
set exeName=WorldGen
set fileName=generation.cpp
::! Statische Verlinkung erzwingen (bei fehlern ggf. -static weglassen)
:: Alle benötigten SFML Module sowie Abhängigkeiten verlinken
set linkingFlags=-static

:: Include- und Library-Pfade setzen
set lAndIPaths=-I"./include" -I"F:/Dropbox/Dropbox/CPP_LIBARIES/hppLibs" -I"F:/Dropbox/Dropbox/CPP_LIBARIES/windows/include/" -L"F:/Dropbox/Dropbox/CPP_LIBARIES/windows/lib/"

:: Setzen des Compile-Commands inkl. statischer Verlinkung
set compileCommand=%compiler% ./scripts/%fileName% -o %exeName%.exe %lAndIPaths% %linkingFlags%

echo Compiling %exeName% Script ...

echo %compileCommand%

%compileCommand%

:: Fehlerprüfung
if %errorlevel% neq 0 (
    echo Fehler: Compiling Not successful!
    pause
    exit /b 1
)

echo Compilation successful.

:: Prüfen, ob Datei existiert
if not exist %exeName%.exe (
    echo Fehler: %exeName%.exe was not created!
    pause
    exit /b 1
)

:: Nachfragen, ob das Programm gestartet werden soll
set /p runTest=Enter 't' to run the program for tests: 
if /i "%runTest%" == "t" (
    echo Running: %exeName%.exe %FLAGS%
    %exeName%.exe %FLAGS%
) else (
    echo Skipping test run.
)

pause
exit
