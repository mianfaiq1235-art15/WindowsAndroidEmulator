# Complete Build Guide for Windows Android Emulator

## Table of Contents
1. [System Requirements](#system-requirements)
2. [Installation Prerequisites](#installation-prerequisites)
3. [Project Structure](#project-structure)
4. [Component Setup](#component-setup)
5. [Build Process](#build-process)
6. [Running the Emulator](#running-the-emulator)
7. [Troubleshooting](#troubleshooting)

---

## System Requirements

### Minimum Requirements
- **OS**: Windows 10/11 (64-bit)
- **RAM**: 8GB (4GB minimum)
- **CPU**: Intel i5/AMD Ryzen 5 or equivalent (4+ cores recommended)
- **GPU**: NVIDIA GTX 960 / AMD R9 290 or equivalent with DirectX 11 support
- **Disk Space**: 500MB free space
- **Network**: Internet connection for Google Play Store

### Recommended Specifications
- **OS**: Windows 11 (64-bit)
- **RAM**: 16GB+
- **CPU**: Intel i7/AMD Ryzen 7 with 8+ cores
- **GPU**: NVIDIA RTX 2060 or better
- **Disk Space**: 2GB free space
- **SSD**: Required for optimal performance

---

## Installation Prerequisites

### Step 1: Install Visual Studio 2022

1. Download from: https://visualstudio.microsoft.com/vs/
2. Run the installer
3. Select **"Desktop development with C++"** workload
4. Include these components:
   - MSVC v143 - VS 2022 C++ x64/x86 build tools
   - Windows 11 SDK
   - CMake tools for Windows
   - Visual Studio Git tools

### Step 2: Install CMake

1. Download from: https://cmake.org/download/
2. Choose: **cmake-3.27.0-windows-x86_64.msi** (or latest version)
3. Run installer and select: **"Add CMake to the system PATH"**
4. Verify installation:
```bash
cmake --version
```

### Step 3: Install Python 3.9+

1. Download from: https://www.python.org/downloads/
2. Run installer (Python 3.11.5 recommended)
3. **IMPORTANT**: Check **"Add Python to PATH"**
4. Click **"Install Now"**
5. Verify installation:
```bash
python --version
pip --version
```

### Step 4: Install Git

1. Download from: https://git-scm.com/download/win
2. Run installer with default settings
3. Verify installation:
```bash
git --version
```

---

## Project Structure

```
WindowsAndroidEmulator/
├── CMakeLists.txt                 # Main build configuration
├── README.md                       # Project overview
├── DEVELOPMENT.md                  # Development guide
├── BUILD_GUIDE.md                  # This file
├── QUICKSTART.md                   # Quick start guide
├── CONTRIBUTING.md                 # Contribution guidelines
│
├── src/                            # Source code
│   ├── main.cpp                    # Entry point
│   ├── core/                       # Emulator engine
│   │   ├── emulator.h/cpp
│   │   └── CMakeLists.txt
│   ├── ui/                         # Windows UI
│   │   ├── window.h/cpp
│   │   └── CMakeLists.txt
│   ├── system/                     # Android system
│   │   ├── android_system.h/cpp
│   │   └── CMakeLists.txt
│   ├── graphics/                   # DirectX 11 rendering
│   │   ├── graphics.h/cpp
│   │   └── CMakeLists.txt
│   └── utils/                      # Utility functions
│       ├── utils.h/cpp
│       └── CMakeLists.txt
│
├── config/                         # Configuration files
│   └── emulator.cfg               # Default settings
│
├── scripts/                        # Build scripts
│   ├── setup.py                   # Environment setup
│   ├── build.bat                  # Build automation
│   └── run.bat                    # Run emulator
│
├── resources/                      # Assets and icons
├── build/                          # Build artifacts (generated)
├── bin/                            # Executable output (generated)
├── requirements.txt                # Python dependencies
└── .gitignore                      # Git ignore rules
```

---

## Component Setup

### Component 1: Core Emulator Engine

**Location**: `src/core/`

**Files**:
- `emulator.h` - Header with class definition
- `emulator.cpp` - Implementation

**Capabilities**:
- Initialize emulator with configurable resources
- Manage RAM allocation (512MB - 8GB)
- Control CPU cores (1-8)
- Display resolution management (800x600 - 2560x1440)
- FPS control (30-120)
- APK loading and installation

**Build**: Compiled as object library via `src/core/CMakeLists.txt`

---

### Component 2: Windows UI System

**Location**: `src/ui/`

**Files**:
- `window.h` - Window class definition
- `window.cpp` - Windows API implementation

**Capabilities**:
- Create native Windows application window
- Handle window events (close, paint, resize)
- Message loop processing
- Window state management

**Framework**: Pure Windows API (no external UI frameworks)

**Build**: Compiled as object library via `src/ui/CMakeLists.txt`

---

### Component 3: Android System Emulation

**Location**: `src/system/`

**Files**:
- `android_system.h` - Android system interface
- `android_system.cpp` - System implementation

**Capabilities**:
- Android 13.0 emulation
- App lifecycle management (start/stop)
- Package installation from APK
- System resource allocation
- Google Play Store integration

**Build**: Compiled as object library via `src/system/CMakeLists.txt`

---

### Component 4: Graphics Engine

**Location**: `src/graphics/`

**Files**:
- `graphics.h` - Graphics interface
- `graphics.cpp` - DirectX 11 implementation

**Capabilities**:
- DirectX 11 rendering pipeline
- GPU acceleration support
- Resolution switching
- Frame buffering
- VSYNC control

**Dependencies**:
- Direct3D 11
- DXGI (DirectX Graphics Infrastructure)

**Build**: Compiled as object library via `src/graphics/CMakeLists.txt`

---

### Component 5: Utility Functions

**Location**: `src/utils/`

**Files**:
- `utils.h` - Utility declarations
- `utils.cpp` - Implementation

**Utilities**:
- File I/O operations
- String manipulation
- Configuration file parsing (singleton pattern)
- Memory utilities

**Build**: Compiled as object library via `src/utils/CMakeLists.txt`

---

## Build Process

### Quick Build (Automated)

**For Windows 10/11**, use the build script:

```bash
cd WindowsAndroidEmulator
scripts\build.bat
```

This script automatically:
- Validates Visual Studio installation
- Creates build directory
- Runs CMake configuration
- Compiles all components
- Links executable
- Copies resources

### Manual Build Process

#### Step 1: Clone and Setup

```bash
# Clone repository
git clone https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator.git
cd WindowsAndroidEmulator

# Run setup script (validates dependencies)
python scripts/setup.py
```

**Expected Output**:
```
============================================================
Windows Android Emulator - Setup
============================================================
Checking system requirements...
✓ Visual Studio C++ compiler found
✓ CMake found
✓ Python found
✓ Git found

Installing Python dependencies...
✓ Python dependencies installed

Creating directory structure...
✓ Created build/
✓ Created bin/
✓ Created android_data/
✓ Created resources/
✓ Created logs/

============================================================
Setup completed successfully!
============================================================
```

#### Step 2: Create Build Directory

```bash
mkdir build
cd build
```

#### Step 3: Configure with CMake

```bash
# Configure for Visual Studio 2022 (64-bit)
cmake -G "Visual Studio 17 2022" -A x64 ..
```

**Expected Output**:
```
-- The CXX compiler identification is MSVC 19.3x.xxxxx
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/...
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler features
-- Configuring done
-- Generating done
-- Build files have been written to: C:/.../build
```

#### Step 4: Build the Project

**Release Build (Optimized)**:
```bash
cmake --build . --config Release
```

**Debug Build (With debugging info)**:
```bash
cmake --build . --config Debug
```

**Expected Output**:
```
Microsoft (R) Build Engine version 17.x.x
[1/5] Building CXX object src/core/CMakeFiles/core.dir/emulator.cpp.obj
[2/5] Building CXX object src/ui/CMakeFiles/ui.dir/window.cpp.obj
[3/5] Building CXX object src/system/CMakeFiles/system.dir/android_system.cpp.obj
[4/5] Building CXX object src/graphics/CMakeFiles/graphics.dir/graphics.cpp.obj
[5/5] Building CXX object src/utils/CMakeFiles/utils.dir/utils.cpp.obj
[6/6] Linking CXX executable bin/Release/WindowsAndroidEmulator.exe

Build succeeded.
```

#### Step 5: Verify Build

```bash
# Check if executable exists
dir bin\Release\WindowsAndroidEmulator.exe
```

---

## Running the Emulator

### Method 1: Direct Execution

```bash
# Navigate to build directory
cd build\bin\Release

# Run the emulator
WindowsAndroidEmulator.exe
```

### Method 2: Using Run Script

```bash
# From project root
scripts\run.bat
```

### Method 3: From Visual Studio

```bash
# In build directory
start WindowsAndroidEmulator.sln

# Or directly in Visual Studio:
# 1. Open build/WindowsAndroidEmulator.sln
# 2. Right-click "WindowsAndroidEmulator" project
# 3. Set as Startup Project
# 4. Press Ctrl+F5 to run
```

### First Launch Output

```
Windows Android Emulator v1.0.0
Initializing emulator...
RAM: 2048MB
CPU Cores: 2
Resolution: 1280x720
Target FPS: 60
Initializing Android system...
Android Version: 13.0
Allocated RAM: 2048MB
Main window created: 1280x800
```

---

## Configuration

### Edit Emulator Settings

Edit `config/emulator.cfg`:

```ini
# System Configuration
ram=2048              # RAM in MB (512-8192)
cpu_cores=2           # CPU cores (1-8)
cpu_thread_count=4    # Thread count (1-16)

# Display Settings
resolution_width=1280 # Width in pixels
resolution_height=720 # Height in pixels
target_fps=60         # FPS limit (30-120)
vsync=1               # V-Sync enabled (0/1)

# Performance
enable_gpu_acceleration=true
enable_kvm=false      # Hyper-V support
enable_snapshot=true  # Save states

# Google Services
enable_google_play_store=true
enable_google_sync=true
```

### Load Custom Configuration

```cpp
// In main.cpp, before creating emulator
Utils::Config& config = Utils::Config::GetInstance();
config.LoadConfig("config/emulator.cfg");

uint32_t ram = std::stoi(config.GetValue("ram", "2048"));
emulator.SetRAM(ram);
```

---

## Step-by-Step Build Instructions for Windows 10

### COMPLETE BUILD PROCESS (Copy & Paste)

**Open Command Prompt (cmd.exe) and execute:**

```batch
REM Step 1: Clone or navigate to project
cd %USERPROFILE%\Desktop
git clone https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator.git
cd WindowsAndroidEmulator

REM Step 2: Run setup
python scripts/setup.py

REM Step 3: Create and enter build directory
mkdir build
cd build

REM Step 4: Configure CMake
cmake -G "Visual Studio 17 2022" -A x64 ..

REM Step 5: Build (Release)
cmake --build . --config Release

REM Step 6: Run emulator
bin\Release\WindowsAndroidEmulator.exe
```

### Expected Total Build Time: 2-5 minutes

---

## Building from Visual Studio IDE

### Option A: Open as Folder

1. Open **Visual Studio 2022**
2. **File → Open → Folder**
3. Navigate to `WindowsAndroidEmulator` folder
4. VS automatically detects CMake project
5. **Build → Build All** (Ctrl+Shift+B)
6. **Debug → Start Without Debugging** (Ctrl+F5)

### Option B: Generate Solution File

```bash
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
start WindowsAndroidEmulator.sln
```

Then in Visual Studio:
1. Solution Explorer → Right-click **WindowsAndroidEmulator**
2. Set as **Startup Project**
3. Press **F5** to run

---

## Troubleshooting

### Error: "CMake not found"

**Solution**:
```bash
# Add CMake to PATH
setx PATH "%PATH%;C:\Program Files\CMake\bin"
# Restart command prompt
```

### Error: "Visual Studio compiler not found"

**Solution**:
```bash
# Run Visual Studio Developer Command Prompt
# Or manually set environment:
"C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
```

### Error: "DirectX headers not found"

**Solution**:
- Install Windows SDK 10.0 or later
- Add to CMake: `-DWINDOWS_SDK_PATH="C:\Program Files (x86)\Windows Kits\10"`

### Error: "Link failed"

**Solution**:
```bash
# Clean build
rmdir /s /q build
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
cmake --build . --config Release -- /V:minimal
```

### Error: "Window creation failed"

**Solution**:
- Ensure GPU drivers are updated
- Disable fullscreen optimizations
- Run as Administrator

### Low FPS or Performance Issues

**Solution**:
1. Edit `config/emulator.cfg`
2. Reduce `resolution_width/height`
3. Lower `target_fps`
4. Increase allocated RAM
5. Reduce `cpu_cores` if CPU bottleneck

---

## Performance Optimization

### For Low-End Systems (4GB RAM)

```ini
ram=1024
cpu_cores=1
resolution_width=800
resolution_height=600
target_fps=30
enable_gpu_acceleration=true
```

### For Mid-Range Systems (8GB RAM)

```ini
ram=2048
cpu_cores=2
resolution_width=1280
resolution_height=720
target_fps=60
enable_gpu_acceleration=true
```

### For High-End Systems (16GB+ RAM)

```ini
ram=4096
cpu_cores=4
resolution_width=1920
resolution_height=1080
target_fps=120
enable_gpu_acceleration=true
```

---

## Deployment

### Create Portable Build

```bash
# After successful build
cd build\bin\Release
mkdir WindowsAndroidEmulator_portable
copy WindowsAndroidEmulator.exe WindowsAndroidEmulator_portable\
copy ...\config\emulator.cfg WindowsAndroidEmulator_portable\
copy ...\requirements.txt WindowsAndroidEmulator_portable\

# Zip the folder
```

### Installer Creation (Optional)

Use NSIS (Nullsoft Scriptable Install System):
```bash
# Download: https://nsis.sourceforge.io/
# Create: installer.nsi
# Build: makensis installer.nsi
```

---

## Next Steps

1. ✅ Build successful → Start emulator
2. 📱 Test APK installation → Copy .apk to `android_data/`
3. 🎮 Install apps → Use Google Play Store integration
4. ⚙️ Configure settings → Edit `config/emulator.cfg`
5. 🐛 Debug issues → Check `logs/` directory

---

## Support & Documentation

- GitHub Issues: https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator/issues
- Wiki: https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator/wiki
- Documentation: See README.md and DEVELOPMENT.md
