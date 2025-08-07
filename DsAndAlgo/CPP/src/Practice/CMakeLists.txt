
# Create an interface library for headers
add_library(project_headers INTERFACE
        ../../include/practice/TreeNode.h
        ../../include/practice/TreeUtils.h
        ../../include/practice/ListNode.h
        ../../include/practice/ListUtils.h
        ../../include/practice/MaximumProduct.h)

# Set include directories for the interface library
target_include_directories(project_headers
        INTERFACE
        ${CMAKE_SOURCE_DIR}/include
)


# Main library
add_library(Practice
#        ../../include/practice/TreeNode.h
#        ../../include/practice/TreeUtils.h
#        ../../include/practice/ListNode.h
#        ../../include/practice/ListUtils.h
#        ../../include/practice/MaximumProduct.h
        MaximumProduct.cpp
        PrintTree.h
        LinkedListInBinaryTree.h
)


add_executable(Main
        main.cpp
       )

# Link with headers interface library
target_link_libraries(Practice PUBLIC project_headers)
#target_link_libraries(maximum_product PUBLIC project_headers)

target_link_libraries(Main PUBLIC Practice project_headers)

# Set include directories for this specific library
target_include_directories(Practice
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(Main
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


if(MSVC)
    target_compile_options(Practice PRIVATE /W4)
else()
    target_compile_options(Practice PRIVATE -Wall -Wextra -Wpedantic)
endif()



# Install rules
#install(TARGETS Practice
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        RUNTIME DESTINATION bin
#)