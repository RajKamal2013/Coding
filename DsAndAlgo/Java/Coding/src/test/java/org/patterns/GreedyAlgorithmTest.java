package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.patterns.GreedyAlgorithm.gasStationJourney;
import static org.patterns.GreedyAlgorithm.jumpGame;

public class GreedyAlgorithmTest {

    @Test
    @DisplayName("test jump games")
    public void testJumpGame() {
        int[] nums = new int[]{2, 3, 1, 1, 4};
        boolean ret = jumpGame(nums);
        Assertions.assertTrue(ret);


        nums = new int[]{2, 3, 1, 1, 9};
        ret = jumpGame(nums);
        Assertions.assertTrue(ret);

        nums = new int[]{3, 2, 1, 0, 4};
        ret = jumpGame(nums);
        Assertions.assertFalse(ret);


        nums = new int[]{4, 0, 0, 0, 4};
        ret = jumpGame(nums);
        Assertions.assertTrue(ret);

    }

    @Test
    public void testGasStation() {
        int[] gas = new int[]{196,857,531,1,398,923,382,987,201,682,352,98,852,583,56,575,402,60,864,59,586,543,684,646,653,312,430,35,510,80,730,811,997,416,911,162,435,644,539,533,516,94,523,345,849,508,592,713,391,138,899,987,585,781,137,3,32,347,16,575,825,518,74,36,641,852,459,737,840,576,28,853,818,205,610,748,204,948,220,688,185,435,187,693,423,393,87,658,507,787,144,640,544,105,993,510,46,970,473,235,636,865,559,362,575,24,960,407,388,406,489,805,645,494,716,441,868,511,470,944,337,59,408,661,822,838,239,953,221,150,166,831,451,243,615,77,859,223,734,212,363,736,375,278,743,962,438,251,994,308,407,752,842,295,784,153,374,741,156,499,946,127,223};
        int[] cost = new int[]{211,891,210,465,179,817,928,617,527,172,743,790,982,534,139,662,365,324,519,150,99,494,983,517,197,655,317,43,76,51,488,951,153,254,599,209,368,300,511,693,42,481,284,416,866,155,357,994,251,154,161,572,195,227,62,81,970,173,764,896,773,121,52,172,900,898,773,321,396,626,410,222,323,938,795,978,473,815,605,993,153,458,551,24,645,199,600,325,161,489,37,704,948,584,892,776,809,452,579,557,208,910,569,228,557,528,583,616,798,491,349,967,536,748,985,702,723,472,398,299,62,537,729,673,218,103,618,896,951,245,122,476,785,280,29,58,929,847,777,184,244,795,397,99,481,619,667,494,964,27,920,323,411,815,435,969,298,108,276,308,655,624,958};
        int computedStartIdx = gasStationJourney(gas, cost);
        int expectedStartIdx = 18;
        //Assertions.assertEquals(expectedStartIdx, computedStartIdx);

        gas = new int[]{1,1,1,1,10};
        cost= new int[]{2,2,1,3,1};
        computedStartIdx = gasStationJourney(gas, cost);
        expectedStartIdx = 4;
        Assertions.assertEquals(expectedStartIdx, computedStartIdx);


        gas = new int[]{1, 2, 3, 4, 5};
        cost = new int[]{3,4,5,1,2};
        expectedStartIdx = 3;
        computedStartIdx = gasStationJourney(gas, cost);
        Assertions.assertEquals(expectedStartIdx, computedStartIdx);


        gas = new int[]{2, 3, 4};
        cost = new int[]{3,4,3};
        expectedStartIdx = -1;
        computedStartIdx = gasStationJourney(gas, cost);
        Assertions.assertEquals(expectedStartIdx, computedStartIdx);

        gas = new int[]{1};
        cost = new int[]{1};
        expectedStartIdx = 0;
        computedStartIdx = gasStationJourney(gas, cost);
        Assertions.assertEquals(expectedStartIdx, computedStartIdx);

        gas = new int[]{1,1,1,1,1};
        cost = new int[]{1,2,3,4,5};
        expectedStartIdx = -1;
        computedStartIdx = gasStationJourney(gas, cost);
        Assertions.assertEquals(expectedStartIdx, computedStartIdx);
    }
}
