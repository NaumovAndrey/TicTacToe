cmake_minimum_required(VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project(TicTacToe)

# Настройка информации отладки для MSVC
if (MSVC)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue,ProgramDatabase>")
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Добавление исполняемого файла проекта
add_executable(TicTacToe main.cpp GameWindow.cpp GameLogic.cpp)

# Установка стандарта C++
set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)

# Линковка с Qt Widgets
target_link_libraries(TicTacToe Qt5::Widgets)