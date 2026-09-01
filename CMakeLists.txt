cmake_minimum_required(VERSION 3.28)
project(xtb C)

set(CMAKE_C_STANDARD 11)

add_library(xtb STATIC
        include/XTB/xtb.c
        include/XTB/xtb.h
        include/XTB/closeWindow.h
        include/XTB/getAllWIDs.h
        include/XTB/getColorAt.h
        include/XTB/getFocusedWindowID.h
        include/XTB/getWindowSize.h
        include/XTB/getWindowTitle.h
        include/XTB/isWindow.h
        include/XTB/minimizeWindow.h
        include/XTB/moveWindow.h
        include/XTB/resizeWindow.h
        include/XTB/unMinimizeWindow.h
        include/XTB/closeWindow.c
        include/XTB/getAllWIDs.c
        include/XTB/getColorAt.c
        include/XTB/getFocusedWindowID.c
        include/XTB/getWindowSize.c
        include/XTB/getWindowTitle.c
        include/XTB/isWindow.c
        include/XTB/minimizeWindow.c
        include/XTB/moveWindow.c
        include/XTB/resizeWindow.c
        include/XTB/unMinimizeWindow.c
        include/XTB/misc.h
)

target_include_directories(xtb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(DIRECTORY include/ DESTINATION include)
install(TARGETS xtb DESTINATION lib)
target_link_libraries(xtb PUBLIC X11)

add_executable(demo src/main.c)
target_include_directories(demo PRIVATE /usr/local/include)
target_link_directories(demo PRIVATE /usr/local/lib)
target_link_libraries(demo PRIVATE xtb X11)