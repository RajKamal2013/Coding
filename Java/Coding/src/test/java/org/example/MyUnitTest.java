package org.example;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.example.MyUnit;

import org.junit.jupiter.api.Test;

public class MyUnitTest {
    @Test
    public void testConcatenate() {
        MyUnit myUnit = new MyUnit();

        String result = myUnit.concatenate("one", "two");

        assertEquals("onetwo", result);

    }
}
