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

# 헤더 파일 리스트
set(HEADER_FILES
        header/windowmanager.h
        header/startscene.h
        header/loginscene.h
        header/signupscene.h
        header/mainmenuscene.h
        header/inquiryscene.h
        header/registerscene.h
        header/depositaccount.h
        header/withdrawaccount.h
        header/deposit.h
        header/withdraw.h
        header/member.h
        header/account.h
        header/date.h
        header/membermanager.h
)

# 소스 파일 리스트
set(SRC_FILES
        main.cpp
        src/windowmanager.cpp
        src/scene/startscene.cpp
        src/scene/loginscene.cpp
        src/scene/signupscene.cpp
        src/scene/mainmenuscene.cpp
        src/scene/inquiryscene.cpp
        src/scene/registerscene.cpp
        src/scene/depositaccount.cpp
        src/scene/withdrawaccount.cpp
        src/scene/deposit.cpp
        src/scene/withdraw.cpp
        src/model/member.cpp
        src/model/account.cpp
        src/model/date.cpp
        src/membermanager.cpp
)

# UI 파일 리스트
set(UI_FILES
        ui/startscene.ui
        ui/loginscene.ui
        ui/signupscene.ui
        ui/mainmenuscene.ui
        ui/inquiryscene.ui
        ui/registerscene.ui
        ui/depositaccount.ui
        ui/withdrawaccount.ui
        ui/deposit.ui
        ui/withdraw.ui
)

add_executable(Qt_account_project main.cpp
        ${HEADER_FILES}
        ${SRC_FILES}
        ${UI_FILES}
)

target_link_libraries(Qt_account_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

