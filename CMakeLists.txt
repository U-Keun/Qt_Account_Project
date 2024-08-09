cmake_minimum_required(VERSION 3.28)
project(Qt_account_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Qt_account_project main.cpp
    deposit.h deposit.cpp deposit.ui
    withdraw.h withdraw.cpp withdraw.ui
    depositaccount.h depositaccount.cpp depositaccount.ui
    withdrawaccount.h withdrawaccount.cpp withdrawaccount.ui)
target_link_libraries(Qt_account_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

