add_executable (DPMain 
                main.cpp)

add_executable(DPMaxSubSequenceSumNonAdjacent
               MaxSubSequenceNonAdjacent.h 
               MaxSubSequenceNonAdjacentTest.cpp)

add_executable(CoinDenominations
               CoinDenominations.h 
               CoinDenominationsTest.cpp)

add_executable(LevenshteinDistance
               LD.h 
               LDTest.cpp
              )     
add_executable(NumberOfWaysToTraverseGrid
               NumberOfWaysToTraverse.h 
               NumberOfWaysToTraverseTest.cpp
               )  
               
add_executable(MaximumIncreasingSubSequence
               MaxIncreasingSubsequence.h 
               MaxIncreasingSubsequenceTest.cpp 
              )                            