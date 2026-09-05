# Development Guide

## Building the Windows Android Emulator

### Prerequisites

- Visual Studio 2022 or later (with C++ development tools)
- Windows SDK 10.0+
- CMake 3.20+
- Python 3.9+
- Git

### Installation Steps

#### 1. Clone the Repository
```bash
git clone https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator.git
cd WindowsAndroidEmulator
```

#### 2. Install Build Dependencies
```bash
# Install Python dependencies
pip install -r requirements.txt

# Run setup script
python scripts/setup.py
```

#### 3. Build the Project
```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake -G "Visual Studio 17 2022" -A x64 ..

# Build
cmake --build . --config Release
```

#### 4. Run the Emulator
```bash
cd Release
WindowsAndroidEmulator.exe
```

### Development Workflow

1. **Code Changes**: Edit files in `src/` directory
2. **Rebuild**: Run `cmake --build . --config Debug` for debug builds
3. **Testing**: Run test suite with `pytest tests/`
4. **Packaging**: Use `cmake --build . --config Release` for distribution

### Project Structure Details

- **src/core/**: Main emulator engine
- **src/ui/**: WinUI 3 Windows interface
- **src/system/**: Android system layer
- **src/graphics/**: DirectX 11 rendering pipeline
- **src/utils/**: Helper functions and utilities

### Configuration Files

Edit `config/emulator.cfg` to customize:
- RAM allocation (512MB - 8GB)
- CPU cores (1-8)
- Display resolution (800x600 - 2560x1440)
- FPS cap (30-120)

### Troubleshooting

**Issue**: Build fails with compiler errors
- Solution: Ensure Visual Studio 2022 with latest updates is installed

**Issue**: Low FPS or stuttering
- Solution: Check GPU drivers, reduce resolution, lower core count

**Issue**: Out of memory errors
- Solution: Reduce allocated RAM in config, close other applications

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

For detailed guidelines, see CONTRIBUTING.md
