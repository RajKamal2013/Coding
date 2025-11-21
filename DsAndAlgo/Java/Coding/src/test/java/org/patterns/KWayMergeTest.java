package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.patterns.KWayMerge.printMatrixElementsInSortedOrder;

public class KWayMergeTest {

    @Test
    @DisplayName("Print n*n Matrix is sorted order")
    public void testPrintMatrixInSortedOrder() {
        int [][] matrix = {
                    {2, 6, 8},
                    {3, 6, 10},
                    {5, 8, 11}
            };

        int matrixSize = matrix.length * matrix.length;
        List<Integer> sortedMatrixElements = printMatrixElementsInSortedOrder(matrix);
        Assertions.assertEquals(matrixSize, sortedMatrixElements.size());
        System.out.println(sortedMatrixElements.toString());

    }

    @Test
    @DisplayName("Test kth smallest element in n*n matrix ")
    public void testKthSmallestElementInMatrix() {
        int [][] matrix = {
                {2, 6, 8},
                {3, 6, 10},
                {5, 8, 11}
        };
        int k = 5;
        List<Integer> sortedMatrixElements = printMatrixElementsInSortedOrder(matrix);
        System.out.println(sortedMatrixElements);
        int expected = sortedMatrixElements.get(k-1);
        int kthSmallestElement = KWayMerge.kthSmallestElementInMatrix(matrix, k);
        Assertions.assertEquals(expected, kthSmallestElement);
    }
}
