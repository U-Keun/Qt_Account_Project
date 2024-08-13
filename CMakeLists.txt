cmake_minimum_required(VERSION 3.28)
project(Qt_account_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ui 폴더에 있는 ui 파일을 읽을 수 있도록 설정
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

# 프로젝트 루트 디렉토리의 include 폴더를 포함 경로에 추가
include_directories(${CMAKE_SOURCE_DIR}/header)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Qt_account_project main.cpp
        header/windowmanager.h src/windowmanager.cpp
        header/startscene.h src/startscene.cpp ui/startscene.ui
        header/loginscene.h src/loginscene.cpp ui/loginscene.ui
        header/signupscene.h src/signupscene.cpp ui/signupscene.ui
        header/mainmenuscene.h src/mainmenuscene.cpp ui/mainmenuscene.ui
)

target_link_libraries(Qt_account_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

