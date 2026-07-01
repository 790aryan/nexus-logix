cmake_minimum_required(VERSION 3.20)

project(OptiFlowEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

# This will automatically include all .cpp files in src/ and its subdirectories
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

# If src/testing/GraphTestBuilder.cpp is inside src/, 
# GLOB_RECURSE will already pick it up. 
# If you want to explicitly add it to ensure it's included:
list(APPEND SOURCES "src/testing/GraphTestBuilder.cpp")
list(APPEND SOURCES "src/algorithms/trees/SegmentTree.cpp")
list(APPEND SOURCES "src/engine/InventoryAnalyticsEngine.cpp")
list(APPEND SOURCES "src/engine/RouteOptimizationEngine.cpp")
add_executable(optiflow-engine ${SOURCES})