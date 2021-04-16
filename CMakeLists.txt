# CMakeList.txt : CMake project for Intent_Identifier_CMake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION "3.20.1")

project("Intent_Identifier")
# Add source to this project's executable
add_executable ("${PROJECT_NAME}" "main.cpp" "LUT.cpp" "LUT.h" "std_includes.h")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" "LUT.cpp" DESTINATION src)
install(FILES "LUT.h" "std_includes.h" DESTINATION header)

