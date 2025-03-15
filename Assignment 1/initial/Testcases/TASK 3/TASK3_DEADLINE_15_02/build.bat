@echo off
setlocal enabledelayedexpansion

rem Biến chứa danh sách file .cpp
set SRC_FILES=main.cpp test/unit_test_TASK3/unit_test_TASK3.cpp test/unit_test.cpp src/TASK3.cpp

rem Lặp qua tất cả các file trong test/unit_test_TASK3/test_case/
for %%f in (test/unit_test_TASK3/test_case/*.cpp) do (
    set SRC_FILES=!SRC_FILES! test/unit_test_TASK3/test_case/%%f
)

rem Lệnh compile
g++ -std=c++17 -o main -Iinclude -Itest %SRC_FILES% -DTEST_TASK3

rem Kiểm tra lỗi
if %ERRORLEVEL% neq 0 (
    echo Build failed!
    exit /b %ERRORLEVEL%
) else (
    echo Build successful!
    echo To run tests, use:
    echo   1. Run all tests: main.exe test_unit
    echo   2. Run a specific test: main.exe test_unit nameFunctionUnitTest
)