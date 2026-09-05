# Windows Android Emulator - Quick Start Guide

## ⚡ 30-Second Setup

### Prerequisite Installation (One-time setup)

Open **Command Prompt** and run each command:

```bash
# 1. Install Visual Studio 2022 C++ Build Tools
https://visualstudio.microsoft.com/vs/

# 2. Install CMake
choco install cmake -y
# OR download from: https://cmake.org/download/

# 3. Install Python
choco install python -y
# OR download from: https://www.python.org/downloads/

# 4. Install Git
choco install git -y
# OR download from: https://git-scm.com/
```

---

## 🚀 Quick Build & Run (Windows 10/11)

Open **Command Prompt** (cmd.exe) and paste this entire block:

```batch
@echo off
setlocal enabledelayedexpansion

REM Navigate to Desktop
cd /d %USERPROFILE%\Desktop

REM Clone repository
git clone https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator.git
cd WindowsAndroidEmulator

REM Run setup
python scripts/setup.py

REM Create build directory
mkdir build
cd build

REM Configure CMake
cmake -G "Visual Studio 17 2022" -A x64 ..

REM Build Release
cmake --build . --config Release

REM Run emulator
bin\Release\WindowsAndroidEmulator.exe

pause
```

---

## 📋 Step-by-Step Commands

### Step 1: Prepare Environment (One-time)

```bash
# Clone repository
git clone https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator.git
cd WindowsAndroidEmulator

# Install Python dependencies
pip install -r requirements.txt

# Run setup script
python scripts/setup.py
```

**Expected Output:**
```
✓ Visual Studio C++ compiler found
✓ CMake found
✓ Python found
✓ Git found
✓ Python dependencies installed
✓ Directory structure created
Setup completed successfully!
```

### Step 2: Configure Build System

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake (Visual Studio 2022, 64-bit)
cmake -G "Visual Studio 17 2022" -A x64 ..
```

**Expected Output**:
```
-- Configuring done
-- Generating done
-- Build files have been written to: C:\...\build
```

### Step 3: Compile

```bash
# Build Release (Optimized)
cmake --build . --config Release

# OR Debug build (with debugging symbols)
cmake --build . --config Debug
```

**Expected Output**:
```
[1/5] Building CXX object src/core/CMakeFiles/core.dir/emulator.cpp.obj
[2/5] Building CXX object src/ui/CMakeFiles/ui.dir/window.cpp.obj
[3/5] Building CXX object src/system/CMakeFiles/system.dir/android_system.cpp.obj
[4/5] Building CXX object src/graphics/CMakeFiles/graphics.dir/graphics.cpp.obj
[5/5] Building CXX object src/utils/CMakeFiles/utils.dir/utils.cpp.obj
[6/6] Linking CXX executable bin\Release\WindowsAndroidEmulator.exe

Build succeeded.
```

### Step 4: Run Emulator

```bash
# From build directory
bin\Release\WindowsAndroidEmulator.exe
```

**OR from project root:**
```bash
scripts\run.bat
```

**First Launch Output:**
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

## ⚙️ Configuration (Optional)

Edit `config/emulator.cfg` to customize:

```ini
# Allocate more RAM
ram=4096

# Use more CPU cores
cpu_cores=4

# Increase display resolution
resolution_width=1920
resolution_height=1080

# Cap at 120 FPS
target_fps=120

# Enable GPU acceleration
enable_gpu_acceleration=true
```

---

## 🔧 Troubleshooting

| Issue | Solution |
|-------|----------|
| **CMake not found** | Add CMake to PATH or reinstall from https://cmake.org/ |
| **VS compiler not found** | Install Visual Studio 2022 with C++ tools |
| **Python not found** | Install Python 3.9+ from https://www.python.org/ |
| **Build fails** | Delete `build` folder and start from Step 2 |
| **Low FPS** | Reduce resolution or fps in config/emulator.cfg |
| **Window won't open** | Update GPU drivers |

---

## 📁 File Locations After Build

```
WindowsAndroidEmulator/
├── build/
│   ├── bin/Release/
│   │   └── WindowsAndroidEmulator.exe  ← YOUR EXECUTABLE
│   ├── CMakeCache.txt
│   └── ...
├── config/
│   └── emulator.cfg                    ← EDIT SETTINGS HERE
├── scripts/
│   ├── build.bat                       ← AUTOMATED BUILD
│   └── run.bat                         ← QUICK RUN
└── src/
    └── ... (source code)
```

---

## ✅ Verification

After build, verify executable exists:

```bash
dir build\bin\Release\WindowsAndroidEmulator.exe
```

Should output file size (e.g., 2,850 KB)

---

## 🚀 Future Launches

After first build, just run:

```bash
# From project root
scripts\run.bat

# OR directly
build\bin\Release\WindowsAndroidEmulator.exe
```

---

## 📱 Next Steps

1. ✅ **Build Complete** → Emulator is running
2. 📦 **Install APK** → Copy .apk files to `android_data/`
3. 🎮 **Use Play Store** → Login with Google account
4. ⚙️ **Customize** → Edit `config/emulator.cfg`
5. 🐛 **Debug** → Check `logs/` directory

---

## 💡 Tips

- **Rebuild faster**: Only modified files are recompiled
- **Release vs Debug**: Release is ~5x faster but harder to debug
- **Full clean rebuild**: Delete `build/` folder and start over
- **Multiple cores**: Use `cmake --build . --config Release -j 4` for parallel build

---

## 📞 Support

- 🐛 Issues: https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator/issues
- 📖 Docs: See `BUILD_GUIDE.md` and `DEVELOPMENT.md`
- 💬 Discussions: https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator/discussions

---

**Happy Emulating! 🎉**
