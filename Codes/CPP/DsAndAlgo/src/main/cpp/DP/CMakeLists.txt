
include_directories(../../headers/)

add_executable (DPMain 
                ../main.cpp)
                
add_executable(DPMaxSubSequenceSumNonAdjacent
               MaxSubSequenceNonAdjacentTest.cpp
               ../main.cpp)

add_executable(CoinDenominations
               CoinDenominationsTest.cpp
               ../main.cpp)

add_executable(LevenshteinDistance
               LDTest.cpp
               ../main.cpp
              )     
add_executable(NumberOfWaysToTraverseGrid
               NumberOfWaysToTraverseTest.cpp
               ../main.cpp
               )  

add_executable(MaximumIncreasingSubSequence 
               MaxIncreasingSubsequenceTest.cpp 
               ../main.cpp
              )   
add_executable(LCS
               LCSTest.cpp
               ../main.cpp
               )
add_executable(MinNumberOfJumps 
               MinNumberOfJumpsTest.cpp 
               ../main.cpp
               )
add_executable(MaxWaterArea
               MaxWaterAreaTest.cpp
               ../main.cpp
              )   
