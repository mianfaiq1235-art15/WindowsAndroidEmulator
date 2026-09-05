# Contributing to Windows Android Emulator

## Code of Conduct

- Be respectful and inclusive
- Provide constructive feedback
- Share knowledge openly
- Follow coding standards

## Getting Started

### Fork & Clone

```bash
# 1. Fork on GitHub
# 2. Clone your fork
git clone https://github.com/YOUR_USERNAME/WindowsAndroidEmulator.git
cd WindowsAndroidEmulator

# 3. Add upstream remote
git remote add upstream https://github.com/mianfaiq1235-art15/WindowsAndroidEmulator.git
```

### Create Feature Branch

```bash
git checkout -b feature/your-feature-name
# OR for bug fixes:
git checkout -b fix/bug-description
```

## Development Workflow

### 1. Make Changes

```bash
# Edit files in src/ directory
# Follow C++17 standards
# Use meaningful variable names
```

### 2. Build & Test

```bash
cd build
cmake --build . --config Debug
# Run and test emulator
bin\Debug\WindowsAndroidEmulator.exe
```

### 3. Commit Changes

```bash
git add .
git commit -m "Feature: Brief description of changes"
```

**Commit Message Format**:
- `Feature: Add new functionality`
- `Fix: Resolve bug #123`
- `Docs: Update documentation`
- `Refactor: Improve code structure`
- `Test: Add/update tests`

### 4. Push & Create Pull Request

```bash
git push origin feature/your-feature-name
```

Then create PR on GitHub with:
- Clear title
- Description of changes
- Related issues
- Testing details

## Coding Standards

### C++ Guidelines

```cpp
// Use meaningful names
class AndroidSystem {};
uint32_t allocated_ram_;

// Follow braces style
if (condition)
{
    // code
}

// Comments for complex logic
// Simple statements don't need comments
uint32_t CalculateMemory(uint32_t base)
{
    // Add overhead for system
    return base + (base * 0.15);
}
```

### File Organization

```cpp
// Order:
// 1. Includes
#include "header.h"
#include <windows.h>

// 2. Namespaces (if applicable)
namespace Utils { }

// 3. Class definition
class MyClass { };

// 4. Function implementations
MyClass::MyClass() { }
```

## Testing

### Unit Tests

```bash
# Create tests in tests/ directory
# Use C++ testing framework

# Run tests
cmake --build . --target RUN_TESTS
```

### Manual Testing

1. Build project in Debug mode
2. Test each component:
   - Window creation
   - APK installation
   - Configuration loading
   - Graphics rendering

## Documentation

### Update README.md

- Add feature descriptions
- Include usage examples
- Update system requirements if changed

### Update DEVELOPMENT.md

- Document new build dependencies
- Explain new components
- Add troubleshooting tips

### Code Comments

```cpp
// Use for complex algorithms
// Avoid obvious comments

/// Use for public API documentation
/// @param name Description
/// @return Description
bool LoadAPK(const char* name);
```

## Pull Request Checklist

- [ ] Code builds without errors
- [ ] All warnings resolved
- [ ] Tested on Windows 10/11
- [ ] Documentation updated
- [ ] Commit messages are clear
- [ ] No unrelated changes included
- [ ] PR description is detailed

## Issue Guidelines

### Report Bugs

**Title**: `[BUG] Short description`

**Include**:
- Windows version
- System specs (RAM, CPU, GPU)
- Exact error message
- Steps to reproduce
- Expected vs actual behavior

### Request Features

**Title**: `[FEATURE] Short description`

**Include**:
- Use case and benefits
- Proposed implementation (optional)
- Related features or issues

## Component Architecture

### Adding New Feature

1. **Identify target component** (core, ui, system, graphics, utils)
2. **Add header** in component directory
3. **Implement** in .cpp file
4. **Update CMakeLists.txt** if new files
5. **Link** in main CMakeLists.txt if new component
6. **Test** thoroughly
7. **Document** changes
8. **Submit PR**

### Example: Add Audio Component

```
1. Create src/audio/audio.h
2. Create src/audio/audio.cpp
3. Create src/audio/CMakeLists.txt
4. Add to main CMakeLists.txt:
   add_subdirectory(src/audio)
5. Link in main executable
6. Test and document
```

## Build System Changes

If modifying CMakeLists.txt:

1. Test build locally
2. Test on clean clone
3. Document changes in DEVELOPMENT.md
4. Include in PR description

## Performance Optimization

Before optimizing:

1. Profile the code
2. Identify bottleneck
3. Implement change
4. Measure improvement
5. Document results

## Maintaining Compatibility

- Keep Windows 10/11 support
- Maintain backward compatibility (when possible)
- Document breaking changes
- Plan deprecation path

## Review Process

### Automated Checks

- Code compiles without warnings
- No unused code
- Proper naming conventions

### Manual Review

- Code functionality
- Architecture alignment
- Performance impact
- Documentation quality

## Community

- Ask questions in Discussions
- Help others with issues
- Share improvements
- Provide feedback

## License

By contributing, you agree to license your work under the MIT License.

## Questions?

- Open a Discussion on GitHub
- Create an issue for clarification
- Review existing documentation

---

**Thank you for contributing! Your help makes this project better. 🙏**
