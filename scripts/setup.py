#!/usr/bin/env python3
"""
Setup script for Windows Android Emulator
Prepares the build environment and validates dependencies
"""

import os
import sys
import subprocess
import platform

def check_requirements():
    """Check if all required tools are installed"""
    print("Checking system requirements...")
    
    # Check Windows
    if platform.system() != "Windows":
        print("ERROR: This emulator only supports Windows")
        return False
    
    # Check Visual Studio
    try:
        result = subprocess.run(["cl.exe"], capture_output=True)
        print("✓ Visual Studio C++ compiler found")
    except FileNotFoundError:
        print("✗ Visual Studio C++ compiler not found")
        print("  Install Visual Studio 2022 with C++ development tools")
        return False
    
    # Check CMake
    try:
        subprocess.run(["cmake", "--version"], capture_output=True, check=True)
        print("✓ CMake found")
    except (FileNotFoundError, subprocess.CalledProcessError):
        print("✗ CMake not found")
        print("  Download from https://cmake.org/download/")
        return False
    
    # Check Python
    try:
        subprocess.run([sys.executable, "--version"], capture_output=True, check=True)
        print("✓ Python found")
    except subprocess.CalledProcessError:
        print("✗ Python not found")
        return False
    
    # Check Git
    try:
        subprocess.run(["git", "--version"], capture_output=True, check=True)
        print("✓ Git found")
    except FileNotFoundError:
        print("✗ Git not found")
        return False
    
    return True

def install_python_deps():
    """Install Python dependencies"""
    print("\nInstalling Python dependencies...")
    try:
        subprocess.run([sys.executable, "-m", "pip", "install", "-r", "requirements.txt"], check=True)
        print("✓ Python dependencies installed")
        return True
    except subprocess.CalledProcessError:
        print("✗ Failed to install Python dependencies")
        return False

def create_directories():
    """Create necessary directories"""
    print("\nCreating directory structure...")
    dirs = [
        "build",
        "bin",
        "android_data",
        "resources",
        "logs"
    ]
    
    for d in dirs:
        os.makedirs(d, exist_ok=True)
        print(f"✓ Created {d}/")

def main():
    print("=" * 60)
    print("Windows Android Emulator - Setup")
    print("=" * 60)
    
    if not check_requirements():
        print("\nSetup failed! Please install missing dependencies.")
        return 1
    
    if not install_python_deps():
        print("\nSetup failed!")
        return 1
    
    create_directories()
    
    print("\n" + "=" * 60)
    print("Setup completed successfully!")
    print("=" * 60)
    print("\nNext steps:")
    print("1. Navigate to the build directory:")
    print("   cd build")
    print("2. Configure CMake:")
    print("   cmake -G \"Visual Studio 17 2022\" -A x64 ..")
    print("3. Build the project:")
    print("   cmake --build . --config Release")
    print("4. Run the emulator:")
    print("   cd bin")
    print("   WindowsAndroidEmulator.exe")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
