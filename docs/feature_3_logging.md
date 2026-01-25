# Feature 3: Logging System

**Status**: PENDING  
**Effort**: 1 hour  
**Phase**: Infrastructure (Phase 1 of 3)

## Description

Integrate lightweight logging library (spdlog recommended) with configurable log levels. Create logging macros/functions for different severity levels throughout the application.

## Input Requirements

- None

## Output Requirements

- Console and file logging capability
- Configurable log levels (DEBUG, INFO, WARN, ERROR)
- Timestamped log entries
- Easy-to-use logging macros

## Learning Objectives

- Modern library integration with CMake
- `constexpr` for compile-time log level filtering
- String formatting with `std::format` (C++20)
- Template specialization for custom type logging
- Macro definition patterns

## Prerequisites

- Feature 1 complete
- spdlog or similar library available (can be fetched via CMake)

## Assumptions

- Single-threaded logging initially (can extend later)
- Log files rotate or are manageable size
- Console output acceptable during development
- UTC or local timestamps acceptable

## Definition of Done

- [ ] spdlog (or equivalent) integrated via CMake
- [ ] LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR macros defined
- [ ] Logs include timestamp, level, and message
- [ ] Can configure log level at runtime (e.g., via environment variable or config)
- [ ] Example usage in existing code (main.cpp, Image class)
- [ ] Log file written to appropriate location (logs/ directory)
- [ ] Documentation of logging API

## Expected Deliverables

1. Logging wrapper class or namespace (include/Logger.h)
2. CMake integration for spdlog
3. Logging macros defined
4. Configuration mechanism for log levels
5. Example usage in existing code
6. logs/ directory created in project structure

## Implementation Hints

- Consider singleton pattern for logger instance
- Provide both stream-style and format-style logging
- Think about performance (is logging expensive in tight loops?)
- Plan for conditional compilation (disable debug logs in release?)

## Usage Example

```cpp
LOG_INFO("Loading image: {}", filename);
LOG_DEBUG("Image dimensions: {}x{}", width, height);
LOG_WARN("Image size exceeds recommended limit");
LOG_ERROR("Failed to load image: {}", error_msg);
```

## Next Feature

Feature 4: Performance Benchmarking Framework
