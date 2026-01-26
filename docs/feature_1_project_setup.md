# Feature 1: Project Setup & Build System

**Status**: COMPLETE (2026-01-26)
**Effort**: 1-1.5 hours
**Phase**: Infrastructure (Phase 1 of 3)

## Description

Establish CMake-based build system with VSCode integration. Create directory structure, configure compiler settings for C++20, and set up debug/release configurations.

## Input Requirements

- None (initial setup)

## Output Requirements

- Compilable "Hello World" application
- Working VSCode tasks.json and launch.json
- CMake configuration supporting C++20

## Learning Objectives

- Modern CMake practices (target-based configuration)
- C++20 compiler flags and feature detection
- VSCode C++ toolchain integration

## Prerequisites

- g++ 13.3.0 installed
- CMake 3.20+ installed
- VSCode with C++ extensions

## Assumptions

- Ubuntu 22.04 development environment
- Standard CMake project structure
- Single executable target initially

## Definition of Done

- [x] Project compiles with `-std=c++20`
- [x] Can build from VSCode (Ctrl+Shift+B)
- [x] Can debug from VSCode (F5)
- [x] Directory structure matches specification:
  ```
  project_root/
  ├── src/
  ├── include/
  ├── data/
  │   ├── test_images/
  │   │   ├── standard/
  │   │   ├── thermal/
  │   │   └── high_contrast/
  │   └── results/
  ├── tests/
  ├── CMakeLists.txt
  └── README.md
  ```
- [x] README documents build instructions
- [x] Debug and Release configurations working

## Expected Deliverables

1. CMakeLists.txt with C++20 support
2. .vscode/tasks.json for build tasks
3. .vscode/launch.json for debugging
4. Simple main.cpp that compiles and runs
5. README.md with build instructions

## Next Feature

Feature 2: Image I/O Framework
