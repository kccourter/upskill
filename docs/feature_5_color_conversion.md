# Feature 5: Color Space Conversion Pipeline

**Status**: PENDING  
**Effort**: 1.5-2 hours  
**Phase**: Core Image Processing (Phase 2 of 3)

## Description

Implement conversions between RGB, grayscale, and simulated thermal color spaces. Use templates for generic pixel operations and ranges/algorithms for pixel iteration.

## Input Requirements

- Loaded RGB images (Feature 2)
- Test images from data/test_images/

## Output Requirements

- Converted images in different color spaces
- Saved examples showing conversions
- Reusable conversion functions/pipeline

## Learning Objectives

- Template functions for generic pixel types
- `std::ranges` and range adaptors
- `std::transform` with lambdas
- Concepts (C++20) for pixel type constraints
- Parallel algorithms (`std::execution::par`)

## Prerequisites

- Features 1-4 complete
- Test images loaded and accessible
- Image class supports different pixel formats or color spaces

## Assumptions

- Standard color space formulas (ITU-R BT.601 for grayscale)
- Thermal simulation uses false-color mapping (e.g., iron/jet colormap)
- Input is 8-bit RGB
- Output can be 8-bit grayscale or RGB

## Definition of Done

- [ ] RGB to grayscale conversion implemented
- [ ] RGB to simulated thermal (false color) implemented
- [ ] Template-based pixel operation framework
- [ ] Uses `std::ranges` or range-v3 for pixel iteration
- [ ] Benchmarked conversion times for all conversions
- [ ] Visual verification of outputs (saved to results/)
- [ ] Support for in-place or out-of-place conversion
- [ ] Parallel execution option tested (if beneficial)

## Expected Deliverables

1. ColorConversion module (include/ColorConversion.h, src/ColorConversion.cpp)
2. Template functions for generic pixel operations
3. Grayscale conversion implementation
4. Thermal/false-color conversion implementation
5. Example code demonstrating conversions
6. Benchmark results for conversions
7. Visual output samples

## Implementation Hints

- Consider template function for generic color conversions
- Use concepts to constrain pixel types
- Think about SIMD opportunities (future optimization)
- Leverage std::transform with execution policies
- Colormap for thermal could be a lookup table

## Color Space Formulas

**Grayscale (ITU-R BT.601)**:
```
Y = 0.299*R + 0.587*G + 0.114*B
```

**Thermal Simulation**:
- Map grayscale value to false color (e.g., blue=cold, red=hot)
- Use iron, jet, or hot colormap
- Lookup table approach recommended

## Usage Example

```cpp
Image rgb = loadImage("test.png");

// Convert to grayscale
Image gray = convertToGrayscale(rgb);

// Convert to simulated thermal
Image thermal = convertToThermal(rgb);

// Generic conversion pipeline
Image result = convertColorSpace<ColorSpace::Thermal>(rgb);
```

## Next Feature

Feature 6: Image Pyramid Generation
