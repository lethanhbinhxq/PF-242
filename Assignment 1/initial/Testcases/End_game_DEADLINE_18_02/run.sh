#!/bin/bash

# Kiểm tra xem người dùng có truyền tham số không
if [ -z "$1" ]; then
    echo "Usage: ./run.sh TASK_NAME"
    echo "Example: ./run.sh TASK1"
    exit 1
fi

TASK_NAME=$1

# Xác định giá trị của `-DTEST_xxx` dựa vào tham số người dùng truyền vào
BUILD_CMD="g++ -std=c++17 -o main -Iinclude -Itest main.cpp src/tay_nguyen_campaign.cpp test/unit_test.cpp"

case $TASK_NAME in
    end_game)
        BUILD_CMD+=" test/unit_test_end_game/unit_test_end_game.cpp test/unit_test_end_game/test_case/*.cpp -DTEST_end_game"
        ;;
    TASK1)
        BUILD_CMD+=" test/unit_test_TASK1/unit_test_TASK1.cpp test/unit_test_TASK1/test_case/*.cpp -DTEST_TASK1"
        ;;
    TASK2)
        BUILD_CMD+=" test/unit_test_TASK2/unit_test_TASK2.cpp test/unit_test_TASK2/test_case/*.cpp -DTEST_TASK2"
        ;;
    TASK3)
        BUILD_CMD+=" test/unit_test_TASK3/unit_test_TASK3.cpp test/unit_test_TASK3/test_case/*.cpp -DTEST_TASK3"
        ;;
    TASK4)
        BUILD_CMD+=" test/unit_test_TASK4/unit_test_TASK4.cpp test/unit_test_TASK4/test_case/*.cpp -DTEST_TASK4"
        ;;
    TASK5)
        BUILD_CMD+=" test/unit_test_TASK5/unit_test_TASK5.cpp test/unit_test_TASK5/test_case/*.cpp -DTEST_TASK5"
        ;;
    *)
        echo "Invalid task name: $TASK_NAME"
        echo "Available tasks: end_game, TASK1, TASK2, TASK3, TASK4, TASK5"
        exit 1
        ;;
esac

# Hiển thị câu lệnh build
echo "Building project for $TASK_NAME with command:"
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
