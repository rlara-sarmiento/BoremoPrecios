cmake_minimum_required(VERSION 2.6)
project(boremoprecios)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(BoremoPrecios_SRCS BoremoPrecios.cpp main.cpp)

qt4_automoc(${BoremoPrecios_SRCS})
add_executable(boremoprecios ${BoremoPrecios_SRCS})
target_link_libraries(boremoprecios ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS boremoprecios RUNTIME DESTINATION bin)
