#!/bin/bash

# Câu lệnh build
BUILD_CMD="g++ -std=c++17 -o main -Iinclude -Itest -g main.cpp \
test/unit_test_TASK2/unit_test_TASK2.cpp test/unit_test.cpp \
src/TASK2.cpp test/unit_test_TASK2/test_case/*.cpp \
-DTEST_TASK2"

# Hiển thị câu lệnh build
echo "Building project with command:"
echo "$BUILD_CMD"
echo "----------------------------------------"

# Thực thi lệnh build
eval $BUILD_CMD

# Kiểm tra xem build có thành công không
if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "----------------------------------------"
    echo "To run tests, use one of the following commands:"
    echo "1. Run all tests: ./main test_unit"
    echo "2. Run a specific test: ./main test_unit nameFunctionUnitTest"
else
    echo "Build failed!"
    exit 1
fi