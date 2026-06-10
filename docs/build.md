# Build Guide

## Host Requirements

- Ubuntu 24.04
- CMake 3.21 or newer
- GCC/G++ 13
- Python 3.11+ for package and script tooling

## Configure

```bash
cmake -B build -S .
```

## Build

```bash
cmake --build build
```

## Test

```bash
ctest --test-dir build --output-on-failure
```

## Optional Flags

- `-DARMFORGE_BUILD_TESTS=ON|OFF`
- `-DARMFORGE_BUILD_BENCHMARKS=ON|OFF`
- `-DARMFORGE_ENABLE_LTO=ON|OFF`
- `-DARMFORGE_WARNINGS_AS_ERRORS=ON|OFF`

