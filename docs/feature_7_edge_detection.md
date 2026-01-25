# Feature 7: Edge Detection Module

**Status**: PENDING  
**Effort**: 1.5-2 hours  
**Phase**: Core Image Processing (Phase 2 of 3)

## Description

Implement Sobel edge detection at single and multiple scales. Include gradient magnitude and direction calculation. This provides basic feature extraction capability.

## Input Requirements

- Grayscale images or pyramid levels (Feature 5, 6)
- Single-channel images

## Output Requirements

- Edge maps (gradient magnitude images)
- Optional: gradient direction maps
- Thresholded binary edge maps

## Learning Objectives

- Function objects and functors
- `std::function` and callable wrappers
- Template specialization for different kernel types
- `std::tuple` for returning multiple values
- Border handling strategies (enum class)

## Prerequisites

- Features 1-6 complete
- Understanding of convolution operations
- Gradient computation concepts

## Assumptions

- 3x3 Sobel operators (Gx and Gy)
- Grayscale input images
- Simple thresholding for binary edge maps
- L2 norm for gradient magnitude: sqrt(Gx² + Gy²)

## Definition of Done

- [ ] Sobel gradient computation (X and Y directions)
- [ ] Gradient magnitude calculation
- [ ] Gradient direction calculation (optional, in radians or degrees)
- [ ] Applies to single images and pyramid levels
- [ ] Configurable threshold values for binary edges
- [ ] Benchmarked edge detection performance
- [ ] Visual comparison with test images
- [ ] Border handling implemented (replicate or reflect)
- [ ] Non-maximum suppression (optional, advanced)

## Expected Deliverables

1. EdgeDetection module (include/EdgeDetection.h, src/EdgeDetection.cpp)
2. Sobel operator implementation
3. Gradient magnitude/direction functions
4. Thresholding utilities
5. Example code on test images and pyramids
6. Benchmark results
7. Visual outputs showing edge maps

## Implementation Hints

- Consider generic convolution function (reusable)
- Use templates or function objects for different kernels
- Think about integer overflow (use larger type for intermediate values)
- Optimize hot loops (separable Sobel is possible)
- Return multiple outputs via std::tuple or custom struct

## Sobel Kernels (3x3)

**Horizontal (Gx)**:
```
[-1  0  1]
[-2  0  2]
[-1  0  1]
```

**Vertical (Gy)**:
```
[-1 -2 -1]
[ 0  0  0]
[ 1  2  1]
```

## Gradient Calculation

```
Gradient magnitude: G = sqrt(Gx² + Gy²)
Gradient direction: θ = atan2(Gy, Gx)
```

## Border Handling Options

```cpp
enum class BorderMode {
    Replicate,  // Repeat edge pixels
    Reflect,    // Mirror at boundary
    Zero        // Pad with zeros
};
```

## Usage Example

```cpp
Image gray = convertToGrayscale(input);

// Compute gradients
auto [gx, gy] = computeSobelGradients(gray, BorderMode::Replicate);

// Compute magnitude
Image magnitude = computeGradientMagnitude(gx, gy);

// Threshold for binary edges
Image edges = threshold(magnitude, 50.0);

// Optional: gradient direction
Image direction = computeGradientDirection(gx, gy);

// Apply to pyramid
ImagePyramid pyramid(gray, 5);
std::vector<Image> edgePyramid;
for (const auto& level : pyramid) {
    edgePyramid.push_back(detectEdges(level));
}
```

## Next Feature

Feature 8: Multi-Scale Feature Detection
