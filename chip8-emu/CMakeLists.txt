# CMakeList.txt : CMake project for chip8-emu, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (chip8-emu "chip8-emu.cpp" "chip8-emu.h")
target_link_libraries(chip8-emu "lib/SDL2")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET chip8-emu PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
