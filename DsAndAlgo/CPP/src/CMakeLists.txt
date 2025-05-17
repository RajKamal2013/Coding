add_executable (main 
                main.cpp)

# Add compiler-specific options
if(MSVC)
    target_compile_options(main PRIVATE /W4)
else()
    target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_subdirectory(DP)
add_subdirectory(Tree)
add_subdirectory(Practice)