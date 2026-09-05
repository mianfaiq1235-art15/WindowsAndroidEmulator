@echo off
REM Windows Android Emulator - Run Script
REM Launches the built emulator

setlocal enabledelayedexpansion

echo ============================================================
echo Windows Android Emulator
echo ============================================================
echo.

REM Check if executable exists
if exist "build\bin\Release\WindowsAndroidEmulator.exe" (
    echo Starting emulator...
    echo.
    build\bin\Release\WindowsAndroidEmulator.exe
) else if exist "build\bin\Debug\WindowsAndroidEmulator.exe" (
    echo Starting emulator (Debug build)...
    echo.
    build\bin\Debug\WindowsAndroidEmulator.exe
) else (
    echo [ERROR] Executable not found!
    echo.
    echo Please build the project first:
    echo   scripts\build.bat
    echo.
    pause
    exit /b 1
)
