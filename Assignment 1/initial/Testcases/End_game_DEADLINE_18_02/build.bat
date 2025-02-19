@echo off
setlocal enabledelayedexpansion

rem Kiểm tra tham số đầu vào
if "%~1"=="" (
    echo Usage: build.bat TASK_NAME
    echo Example: build.bat TASK1
    exit /b 1
)

set TASK_NAME=%1

rem Lệnh build mặc định
set BUILD_CMD=g++ -std=c++17 -o main.exe -Iinclude -Itest main.cpp src\tay_nguyen_campaign.cpp test\unit_test.cpp

rem Xác định thư mục chứa unit test và gán biến TEST_DIR
if /I "%TASK_NAME%"=="end_game" (
    set TEST_DIR=test\unit_test_end_game
    set BUILD_CMD=!BUILD_CMD! !TEST_DIR!\unit_test_end_game.cpp
) else if /I "%TASK_NAME%"=="TASK1" (
    set TEST_DIR=test\unit_test_TASK1
    set BUILD_CMD=!BUILD_CMD! !TEST_DIR!\unit_test_TASK1.cpp
) else if /I "%TASK_NAME%"=="TASK2" (
    set TEST_DIR=test\unit_test_TASK2
    set BUILD_CMD=!BUILD_CMD! !TEST_DIR!\unit_test_TASK2.cpp
) else if /I "%TASK_NAME%"=="TASK3" (
    set TEST_DIR=test\unit_test_TASK3
    set BUILD_CMD=!BUILD_CMD! !TEST_DIR!\unit_test_TASK3.cpp
) else if /I "%TASK_NAME%"=="TASK4" (
    set TEST_DIR=test\unit_test_TASK4
    set BUILD_CMD=!BUILD_CMD! !TEST_DIR!\unit_test_TASK4.cpp
) else if /I "%TASK_NAME%"=="TASK5" (
    set TEST_DIR=test\unit_test_TASK5
    set BUILD_CMD=!BUILD_CMD! !TEST_DIR!\unit_test_TASK5.cpp
) else (
    echo Invalid task name: %TASK_NAME%
    echo Available tasks: end_game, TASK1, TASK2, TASK3, TASK4, TASK5
    exit /b 1
)

rem Thêm tất cả file .cpp trong thư mục test_case vào BUILD_CMD
for %%f in (%TEST_DIR%\test_case\*.cpp) do (
    set BUILD_CMD=!BUILD_CMD! %%f
)

rem Thêm cờ -DTEST_xxx
set BUILD_CMD=!BUILD_CMD! -DTEST_%TASK_NAME%

rem Hiển thị lệnh build
echo Building project for %TASK_NAME% with command:
echo !BUILD_CMD!
echo ----------------------------------------

rem Thực thi lệnh build
!BUILD_CMD!

rem Kiểm tra kết quả build
if %ERRORLEVEL% neq 0 (
    echo Build failed!
    exit /b %ERRORLEVEL%
) else (
    echo Build successful!
    echo ----------------------------------------
    echo To run tests, use one of the following commands:
    echo   1. Run all tests: main.exe test_unit
    echo   2. Run a specific test: main.exe test_unit nameFunctionUnitTest
)
