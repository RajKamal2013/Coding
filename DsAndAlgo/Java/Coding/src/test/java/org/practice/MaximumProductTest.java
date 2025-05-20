package org.practice;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;
import org.junit.jupiter.params.provider.ValueSource;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit test class for the MaximumProduct implementation.
 * Contains multiple tests to verify correctness and edge cases for the
 * methods in the MaximumProduct class.
 */
class MaximumProductTest {

    private MaximumProduct maximumProduct;

    @BeforeEach
    void setUp() {
        maximumProduct = new MaximumProduct();
    }

    @Test
    void splitNumberInDigits_NegativeNumber_ThrowsIllegalArgumentException() {
        assertThrows(IllegalArgumentException.class, 
            () -> maximumProduct.splitNumberInDigits(-123));
    }

    @Test
    void splitNumberInDigits_Zero_ReturnsListWithZero() {
        List<Integer> result = maximumProduct.splitNumberInDigits(0);
        assertEquals(List.of(0), result);
    }

    @Test
    void splitNumberInDigits_SingleDigit_ReturnsListWithOneElement() {
        List<Integer> result = maximumProduct.splitNumberInDigits(5);
        assertEquals(List.of(5), result);
    }

    @Test
    void splitNumberInDigits_MultipleDigits_ReturnsCorrectList() {
        List<Integer> result = maximumProduct.splitNumberInDigits(123);
        List<Integer> expected = new ArrayList<>(List.of(1, 2, 3));
        Collections.reverse(expected);
        assertEquals(expected, result);
    }

    // Parameterized test for maximum product calculation
    @ParameterizedTest
    @MethodSource("provideTestCasesForMaxProduct")
    void calculateMaxProduct_ValidInput_ReturnsExpectedResult(int input, int expected) {
        assertEquals(expected, maximumProduct.maxProduct(input));
    }

    // Parameterized test for maximum product calculation
    @ParameterizedTest
    @MethodSource("provideTestCasesForMaxProduct")
    void calculateMaxProductOptimal_ValidInput_ReturnsExpectedResult(int input, int expected) {
        assertEquals(expected, maximumProduct.maxProduct2(input));
    }

    // Test data provider for maximum product calculations
    private static Stream<Arguments> provideTestCasesForMaxProduct() {
        return Stream.of(
            Arguments.of(31, 3),     // 3 * 1 = 3
            Arguments.of(124, 8),    // 2 * 4 = 8
            Arguments.of(999, 81),   // 9 * 9 = 81
            Arguments.of(1234, 12),  // 3 * 4 = 12
            Arguments.of(10, 0),     // 1 * 0 = 0
            Arguments.of(5, 0)       // single digit should return 0
        );
    }

    @Test
    void calculateMaxProduct_NegativeInput_ThrowsIllegalArgumentException() {
        assertThrows(IllegalArgumentException.class, 
            () -> maximumProduct.maxProduct(-123));
    }


    @ParameterizedTest
    @ValueSource(ints = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
    void calculateMaxProduct_SingleDigit_ReturnsZero(int digit) {
        assertEquals(0, maximumProduct.maxProduct(digit));
    }

    @Test
    void calculateMaxProduct_LargeNumber_HandlesCorrectly() {
        assertEquals(72, maximumProduct.maxProduct(987654321));
    }
}