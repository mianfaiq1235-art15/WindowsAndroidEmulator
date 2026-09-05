@echo off
REM Windows Android Emulator - Build Script
REM Automates the complete build process

setlocal enabledelayedexpansion

echo ============================================================
echo Windows Android Emulator - Build Script
echo ============================================================
echo.

REM Check for required tools
echo Checking system requirements...

REM Check CMake
cmake --version >nul 2>&1
if errorlevel 1 (
    echo [ERROR] CMake not found. Please install CMake and add to PATH.
    echo Download: https://cmake.org/download/
    goto error
)
echo [OK] CMake found

REM Check Visual Studio compiler
cl.exe >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Visual Studio C++ compiler not found.
    echo Install Visual Studio 2022 with C++ development tools.
    goto error
)
echo [OK] Visual Studio compiler found

REM Check Python
python --version >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Python not found. Please install Python 3.9+
    goto error
)
echo [OK] Python found

echo.
echo Running setup script...
python scripts/setup.py
if errorlevel 1 goto error

echo.
echo Creating build directory...
if not exist build mkdir build
cd build

echo.
echo Configuring CMake...
cmake -G "Visual Studio 17 2022" -A x64 ..
if errorlevel 1 (
    echo [ERROR] CMake configuration failed
    goto error
)

echo.
echo Building project...
cmake --build . --config Release
if errorlevel 1 (
    echo [ERROR] Build failed
    goto error
)

echo.
echo ============================================================
echo Build completed successfully!
echo ============================================================
echo.
echo Executable location: %CD%\bin\Release\WindowsAndroidEmulator.exe
echo.
echo Run the emulator:
echo   bin\Release\WindowsAndroidEmulator.exe
echo.
echo Or from project root:
echo   scripts\run.bat
echo.

cd ..
goto end

:error
echo.
echo ============================================================
echo Build failed! See errors above.
echo ============================================================
pause
exit /b 1

:end
pause
