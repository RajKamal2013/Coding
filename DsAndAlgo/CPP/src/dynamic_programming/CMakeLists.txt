#file(GLOB DP_HEADER_LIST ${PROJECT_SOURCE_DIR}/src/dynamic_programming/*.h)
#file(GLOB DP_SRCS ${PROJECT_SOURCE_DIR}/src/dynamic_programming/*.cpp)

set(DP_HEADER_LIST
    ${PROJECT_SOURCE_DIR}/src/dynamic_programming/coins_change.h
    )
    
set(DP_SRCS 
    ${PROJECT_SOURCE_DIR}/src/dynamic_programming/coins_change.cc
    )

add_library(dp_library SHARED ${DP_HEADER_LIST} ${DP_SRCS})

add_executable (CoinChange 
                coins_change.h
                coins_change.cc)