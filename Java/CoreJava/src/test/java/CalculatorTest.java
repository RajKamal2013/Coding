import coding.unitTest.Calculator;
import org.junit.jupiter.api.*;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.EnumSource;
import org.junit.jupiter.params.provider.MethodSource;
import org.junit.jupiter.params.provider.ValueSource;

import java.util.EnumSet;
import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.assertEquals;

//@TestInstance(TestInstance.Lifecycle.PER_METHOD)
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class CalculatorTest {

    private Calculator calculator;
    private int counter;
    @BeforeAll
    public void setupAll() {
        System.out.println("Setup All - Initializing the Test class");
        System.out.println("Counter Value is - " + counter);
    }

    @BeforeEach
    public void setup() {
        System.out.println("Setup Test - Initializing the Calculator object");
        calculator = new Calculator();

        counter++;
    }


    @Test
    @DisplayName("Test Addition of 2 integers")
    void shouldTestIntegerAddition() {

        Assumptions.assumeTrue(System.getProperty("os.name").equals("Mac OS X"), () -> "Test should run only on MAC OS Operating System");
       // Assumptions.assumeFalse(System.getProperty("ENV").equals(null), () -> "Test should not run on Development Environment");

        // Arrange
        Calculator calculator = new Calculator();

        // Act
        int result = calculator.add(1, 2);

        // Assert
        assertEquals(3, result);
    }

    @Test
    @DisplayName("Test Division of 2 integers")
    void shouldTestIntegerDivision() {
        // Arrange
        Calculator calculator = new Calculator();

        // Act
        int result = calculator.divide(10, 2);

        // Assert
        Assertions.assertEquals(5, result);
        Assumptions.assumingThat(() -> System.getProperty("os.name").equals("Mac OS X"),
                () -> Assertions.assertEquals(5, result));
    }

    @Test
    @DisplayName("Test Division by 0 - Should Result in an Exception")
    void shouldThrowExceptionWhenDivisibleBy0() {
        // Arrange
        Calculator calculator = new Calculator();

        // Act
        // Assert
        Assertions.assertThrows(ArithmeticException.class, () -> calculator.divide(10, 0), "Division by 0 is not allowed");
    }

    @AfterEach
    public void cleanup() {
        System.out.println("Cleaning up resources after each test");
    }

    @AfterAll
    public void cleanupAll() {
        System.out.println("Cleaning up resources after test class execution");

        System.out.println("Counter Value is - " + counter);
    }

    @RepeatedTest(value = 5, name = "{displayName} - repetition {currentRepetition}/{totalRepetitions}")
    @DisplayName("Repeated Addition 7 Times")
    void shouldTestAddition5Times() {
        System.out.println("Repeated Test");
    }

    @ParameterizedTest
    @DisplayName("Test Even Numbers")
    @ValueSource(ints = {2, 4, 6, 8, 1024})
    void shouldTestEvenNumbers(int input) {
        // Act
        boolean result = calculator.isEven(input);

        // Assert
        Assertions.assertTrue(result);
    }

    @ParameterizedTest
    @DisplayName("Should Test using EnumSource annotation")
    @EnumSource(Calculator.Operation.class)
    void shouldTestUsingEnumSource(Calculator.Operation operation) {
        Assertions.assertTrue(EnumSet.of(Calculator.Operation.ADDITION,
                Calculator.Operation.MULTIPLICATION,
                Calculator.Operation.SUBTRACTION,
                Calculator.Operation.DIVISION).contains(operation));
    }

    @ParameterizedTest
    @DisplayName("Test Even Numbers using MethodSource")
    @MethodSource("getNumbers")
    void shouldTestEvenNumbersUsingMethodSource(int input) {
        // Act
        boolean result = calculator.isEven(input);

        // Assert
        Assertions.assertTrue(result);
    }

    @Test
    @DisplayName("Simple Test")
    @Disabled
    void disabledTest() {
        System.out.println("This test is disabled");
    }

    static Stream<Integer> getNumbers() {
        return Stream.of(2, 4, 6, 8, 1024);
    }

}
