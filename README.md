# Modern C++ upskill project v3 - PROJECT STATUS CHECKPOINT

**Last Updated**: 2026-01-25
**Status**: Goal #3 COMPLETE - Dataset acquired and ready for implementation

---

## ROLE

You are a coach and tutor. You will not write code for me unless I ask explicitly for a solution to be written. Your job is to help guide me through an exercise as described below and incrementally present tasks that work toward the end solution. For each incremental step, we will work through possible solutions and approaches, then I will attempt to code the solutions. You will grade/review the solutions and we will rework as needed to arrive at correct, complete implementations.

---

## EXERCISE GENERAL DESCRIPTION

I'm prepping for roles with battlespace awareness group (radar) and Perception/Image processing group (primarily infrared).

I am an experienced C++ coder but am most familiar with "old school" C++ (98/03). I have been reading and doing a limited amount of practice with Modern C++ (11 and newer) but need more time spent implementing code of reasonable complexity in the context of a project to feel more comfortable with some of most important modern C++ changes.

I want to select a coding exercise that will take several hours of work to implement and test. Image processing is an area of interest. A test set with a handful of reasonably sized RGB images should be included as a baseline data set.

---

## SELECTED PROJECT: Multi-Scale Image Feature Detector

**Domain Relevance**: Direct application to both radar (target detection) and IR perception (hotspot identification)

**Core Functionality**:
- Load images and convert between color spaces (RGB, grayscale, thermal-simulated)
- Apply multi-scale pyramid decomposition
- Detect features at different scales (edges, corners, blobs)
- Visualize detection results with bounding boxes/markers
- Performance profiling across different algorithms

**Modern C++ Learning Opportunities**: Smart pointers for image data, move semantics for large data transfers, templates for generic algorithms, ranges for pixel operations, std::variant for multi-format support

**Estimated Effort**: 12-15 hours across 9 features

---

## PROJECT SCOPE AND APPROACH

**Scope**: 12-15 hour total effort divided into 9 features organized in 3 phases, with each feature taking 1-2.5 hours.

**Chunking Strategy**:
Each chunk provides:
- Clear entry/exit points
- Tangible deliverable
- Natural checkpoint for review/feedback
- Easy course adjustment if needed

**Session Rhythm**:
1. Assignment kickoff (5-10 min) - Review what and why
2. Implementation (1-2 hours) - Code the solution
3. Review session (15-30 min) - Discuss, refine, identify improvements
4. Checkpoint (5 min) - Save approved version, document learnings

---

## DEVELOPMENT ENVIRONMENT

**Operating System**: Ubuntu 22.04

**C++ Standard**: C++20

**Build System**: CMake

**IDE**: VSCode
- Full project setup for build/edit/run/debug within VSCode
- Appropriate configurations and launch.json/tasks.json setup required

**Compiler**: g++ 13.3.0

---

## DATASET REQUIREMENTS

### Image Set Composition (10-12 images total)
- 4-5 standard test images (varied content: textures, edges, geometric shapes)
- 3-4 synthetic "thermal-like" images (simulating IR sensor output)
- 2-3 high-contrast images (good for initial testing)
- Mix of sizes: some 512x512, some 1024x1024, maybe one larger

### Image Format
- Prefer common formats (PNG, JPG)
- **Preference for lossless formats when available** 

### Dataset Source
- Real-world FLIR imagery can be found on local machine at /home/kc/data/FLIR_ADAS_v2
  - Dataset: FLIR ADAS v2 - Thermal imagery for autonomous driving research
  - Source: https://adas-dataset-v2.flirconservator.com/
  - Approach: copy from a representative subset of data from local dataset in ~/data into the working structure within this current directory, do not work on the downloaded dataset in place 

- Standard and high_contrast images
  - Task: identify public sources for data and describe them. I will take a look and when I approve, you will copy data from public sets into local working structure before proceeding to next tasks. 

### Storage Organization
```
project_root/
├── data/
│   ├── test_images/
│   │   ├── standard/
│   │   ├── thermal/
│   │   └── high_contrast/
│   └── results/
│       └── [output images go here]
```

---

## GOAL #1 - Select and identify an example project ✅

**STATUS**: COMPLETE (2026-01-25)

**Accomplishments**:
- ✅ Project selected: Multi-Scale Image Feature Detector
- ✅ General data requirements understood
- ✅ Dataset requirements defined (pending final dataset selection)
- ✅ Development environment specified

---

## GOAL #2 - Propose milestones / features to assign for the selected project ✅

**STATUS**: COMPLETE (2026-01-25)

**Accomplishments**:
- ✅ Defined 9 features across 3 phases
- ✅ Created assignment definition for each feature including:
  - Size/complexity of effort
  - Data input and output requirements
  - Desired outcomes
  - Prerequisites and assumptions
  - Definition of done
  - Implementation hints
  - Modern C++ learning objectives
- ✅ Checkpointed all feature definitions to markdown files
- ✅ Created feature index document

**Feature Files Created**:
- `feature_index.md` - Complete overview and tracking
- `feature_1_project_setup.md` - Project Setup & Build System (1-1.5 hrs)
- `feature_2_image_io.md` - Image I/O Framework (1.5-2 hrs)
- `feature_3_logging.md` - Logging System (1 hr)
- `feature_4_benchmarking.md` - Performance Benchmarking Framework (1-1.5 hrs)
- `feature_5_color_conversion.md` - Color Space Conversion Pipeline (1.5-2 hrs)
- `feature_6_pyramid.md` - Image Pyramid Generation (1.5-2 hrs)
- `feature_7_edge_detection.md` - Edge Detection Module (1.5-2 hrs)
- `feature_8_multi_scale_detection.md` - Multi-Scale Feature Detection (2-2.5 hrs)
- `feature_9_visualization.md` - Visualization & Results Output (1.5-2 hrs)

### Feature Breakdown Summary

#### Phase 1: Infrastructure (4-5 hours)
1. **Project Setup & Build System** - CMake, VSCode, directory structure
2. **Image I/O Framework** - RAII, smart pointers, move semantics
3. **Logging System** - spdlog integration, std::format
4. **Performance Benchmarking** - std::chrono, RAII timers, reporting

#### Phase 2: Core Image Processing (5-6 hours)
5. **Color Space Conversion** - Templates, ranges, parallel algorithms
6. **Image Pyramid Generation** - Gaussian pyramids, separable filters
7. **Edge Detection Module** - Sobel operators, gradient computation

#### Phase 3: Advanced Features (3-4 hours)
8. **Multi-Scale Feature Detection** - Harris/DoG, std::variant, NMS
9. **Visualization & Results** - std::filesystem, JSON output, drawing

### Modern C++ Patterns Coverage

**Smart Pointers & RAII**: Features 2, 3, 4, 6  
**Move Semantics & Perfect Forwarding**: Features 2, 6, 8  
**Templates & Concepts**: Features 5, 7, 8  
**Ranges & Algorithms**: Features 5, 7, 8, 9  
**std::chrono**: Feature 4  
**std::variant, std::optional**: Feature 8  
**std::filesystem, std::format**: Features 3, 9  
**Parallel Execution**: Feature 5

---

## GOAL #3 - Dataset Acquisition ✅

**STATUS**: COMPLETE (2026-01-25)

**Accomplishments**:
- ✅ Identified public sources (OpenCV samples, USC-SIPI database)
- ✅ Sources approved
- ✅ Copied 4 FLIR thermal images from /home/kc/data/FLIR_ADAS_v2
- ✅ Downloaded 4 standard images from OpenCV samples
- ✅ Downloaded 2 high-contrast images from OpenCV samples
- ✅ Generated 1 synthetic checkerboard pattern (1024x1024)
- ✅ Verified dataset completeness (11 images total)

**Final Dataset**:
| Category | Files | Dimensions | Format |
|----------|-------|------------|--------|
| standard/ | baboon.jpg | 512x512 | RGB |
| | building.jpg | 868x600 | RGB |
| | butterfly.jpg | 493x356 | RGB |
| | fruits.jpg | 512x480 | RGB |
| thermal/ | thermal_01.jpg | 640x512 | Grayscale |
| | thermal_02.jpg | 640x512 | Grayscale |
| | thermal_03.jpg | 640x512 | Grayscale |
| | thermal_04.jpg | 640x512 | Grayscale |
| high_contrast/ | chessboard.png | 1754x1240 | RGBA |
| | box_in_scene.png | 512x384 | Grayscale |
| | checkerboard_1024.png | 1024x1024 | 1-bit |

**Sources**:
- Thermal: FLIR ADAS v2 (local)
- Standard/High-contrast: [OpenCV samples](https://github.com/opencv/opencv/tree/master/samples/data)
- Synthetic: ImageMagick generated

---

## GOAL #4 - Feature Implementation

**STATUS**: NOT STARTED

**Approach**: Work through features 1-9 sequentially, following the session rhythm:
1. Review feature assignment
2. Discuss implementation approach
3. Code the solution
4. Review and refine
5. Mark feature complete and checkpoint
6. Move to next feature

---

## PROGRESS TRACKING

### Completed Goals
- ✅ Goal #1: Project selection (2026-01-25)
- ✅ Goal #2: Feature definitions (2026-01-25)
- ✅ Goal #3: Dataset acquisition (2026-01-25)

### Active Goals
- ⏳ Goal #4: Feature implementation (NEXT - start with Feature 1)

### Pending Goals
- None

### Completed Features
- None yet (awaiting dataset and Feature 1 start)

### Modern C++ Patterns Practiced
- None yet (will be tracked as features are completed)

### Performance Baselines
- None yet (will be established in Feature 4 and beyond)

---

## NEXT STEPS

**Immediate Next Actions**:
1. **Begin Feature 1**:
   - Project setup and build system
   - Establish CMake configuration
   - Configure VSCode integration

2. **Continue Sequential Implementation**:
   - Work through Features 2-9 in order
   - Document learnings after each feature
   - Update this checkpoint document with progress

---

## DOCUMENT HISTORY

- **v1**: Initial project specification
- **v2**: Added Goal #1 completion, refined dataset requirements
- **v3** (2026-01-25): Goal #2 complete, all feature definitions checkpointed
- **v4** (2026-01-25): Goal #3 complete, dataset acquired (11 images), ready for Feature 1

---

## SUPPORTING DOCUMENTS

All feature definitions are available in individual markdown files:
- `feature_index.md` - Master feature list and tracking
- `feature_1_project_setup.md` through `feature_9_visualization.md` - Individual feature assignments
