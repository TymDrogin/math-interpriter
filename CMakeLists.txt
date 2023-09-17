# CMakeList.txt : CMake project for math_interpreter, include source and define
# project-specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("math_interpreter")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(math_interpreter ${SOURCES}) # Corrected target name here

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET math_interpreter PROPERTY CXX_STANDARD 20)
endif()