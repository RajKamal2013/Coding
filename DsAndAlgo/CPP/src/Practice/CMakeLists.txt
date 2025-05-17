# Main library
add_library(Practice
        MaximumProduct.cpp
        ${CMAKE_SOURCE_DIR}/include/practice/MaximumProduct.h
)

add_executable(maximum_product_test
        main.cpp
        MaximumProduct.cpp
        ${CMAKE_SOURCE_DIR}/include/practice/MaximumProduct.h)


# Link with headers interface library
target_link_libraries(Practice PUBLIC project_headers)
#target_link_libraries(maximum_product PUBLIC project_headers)

# Set include directories for this specific library
target_include_directories(Practice
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(MSVC)
    target_compile_options(Practice PRIVATE /W4)
else()
    target_compile_options(Practice PRIVATE -Wall -Wextra -Wpedantic)
endif()



# Install rules
install(TARGETS Practice
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
