package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.patterns.ModifiedBinarySearch.*;

public class ModifiedBinarySearchTest {

    @Test
    @DisplayName("Test single element in duplicates")
    public void testSingleNonDuplicate() {
        int[] nums = {1, 1, 2, 3, 3, 4, 4};
        int single = singleNonDuplicate(nums);
        int expected = 2;
        Assertions.assertEquals(expected, single);

        nums = new int[]{4, 6, 6, 7, 7};
        single = singleNonDuplicate(nums);
        expected = 4;
        Assertions.assertEquals(expected, single);

        nums = new int[]{6, 6, 7, 7, 8};
        single = singleNonDuplicate(nums);
        expected = 8;
        Assertions.assertEquals(expected, single);

        nums = new int[]{4, 4, 6, 7, 7};
        single = singleNonDuplicate(nums);
        expected = 6;
        Assertions.assertEquals(expected, single);
    }

    @Test
    @DisplayName("TestClosetKElementsWrtTargetInSortedArray")
    public void testFindClosestElements() {
        int[] nums = {1, 4, 8, 10, 15, 20};
        int k = 2;
        int target = 7;

        List<Integer> expected = Arrays.asList(4, 8);
        List<Integer> computed = findClosestElements(nums, k, target);

        System.out.println("Expected: " +  expected.toString());
        System.out.println("Computed: " +  computed.toString());

        Assertions.assertEquals(expected.size(), computed.size());

        Set<Integer> expectedSet = new HashSet<>(expected);
        Set<Integer> computedSet = new HashSet<>(computed);

        Assertions.assertEquals(expectedSet, computedSet);

        nums = new int[] {-9984,-9863,-9855,-9736,-9728,-9656,-9621,-9558,-9518,-9476,-9444,-9261,-9240,-9157,-9138,-9030,-8992,-8823,-8808,-8776,-8744,-8665,-8656,-8638,-8636,-8634,-8613,-8589,-8577,-8548,-8525,-8489,-8363,-8332,-8318,-8296,-8288,-8277,-8150,-8112,-8062,-8005,-7974,-7793,-7754,-7727,-7688,-7590,-7560,-7545,-7490,-7458,-7432,-7409,-7396,-7195,-7134,-7102,-7025,-6985,-6868,-6776,-6763,-6748,-6653,-6645,-6620,-6599,-6566,-6525,-6468,-6450,-6448,-6345,-6337,-6323,-6304,-6193,-6189,-5923,-5862,-5842,-5775,-5759,-5733,-5684,-5653,-5647,-5635,-5599,-5570,-5554,-5505,-5472,-5355,-5350,-5344,-5334,-5295,-5229,-5218,-5188,-5167,-5136,-5053,-5023,-5020,-4953,-4863,-4741,-4730,-4726,-4632,-4607,-4593,-4586,-4446,-4441,-4357,-4336,-4287,-4215,-4187,-4079,-4033,-4007,-3955,-3909,-3768,-3686,-3427,-3396,-3303,-3232,-3229,-3225,-3200,-3166,-2960,-2916,-2827,-2703,-2700,-2561,-2442,-2372,-2352,-2350,-2314,-2310,-2274,-2225,-2101,-2080,-2017,-1958,-1948,-1942,-1942,-1931,-1915,-1886,-1829,-1786,-1764,-1628,-1615,-1548,-1522,-1415,-1307,-1197,-1194,-1156,-1153,-1059,-1031,-1026,-1019,-1005,-963,-925,-844,-831,-813,-810,-779,-770,-655,-649,-553,-527,-499,-490,-464,-412,-363,-310,-301,-290,-270,-115,-36,-27,38,40,105,146,294,309,343,402,479,503,600,619,811,820,843,912,936,959,971,977,1156,1163,1172,1174,1190,1204,1207,1282,1333,1368,1421,1595,1666,1687,1725,1743,1774,1866,1882,1915,1950,2013,2032,2045,2047,2166,2288,2311,2313,2331,2335,2384,2450,2500,2537,2630,2650,2656,2686,2705,2803,2879,2918,2983,2988,3060,3094,3267,3279,3296,3313,3413,3459,3475,3642,3681,3719,3763,3835,3909,3928,3972,4042,4061,4087,4177,4272,4338,4343,4358,4372,4434,4461,4468,4471,4526,4619,4640,4650,4663,4665,4676,4738,4798,4812,4828,4885,4963,5039,5071,5095,5112,5207,5227,5252,5267,5268,5302,5303,5345,5369,5398,5429,5433,5464,5472,5540,5548,5552,5596,5608,5714,5862,5865,5931,5957,6023,6076,6220,6233,6255,6368,6412,6424,6462,6525,6580,6615,6652,6697,6736,6782,6785,6835,6847,6852,6895,6931,6938,6996,7012,7091,7094,7186,7279,7305,7377,7401,7513,7538,7546,7585,7597,7663,7738,7774,7780,7868,7868,7900,7905,7913,8082,8109,8137,8198,8279,8300,8332,8352,8389,8443,8444,8556,8564,8615,8688,8742,8760,8805,8887,8916,8944,8987,9034,9108,9125,9164,9279,9287,9362,9407,9421,9422,9467,9507,9520,9646,9648,9672,9784,9840};
        k = 1;
        target = -504;

    }

    @Test
    @DisplayName("BinarySearchInRotatedSortedArray")
    public void testBinarySearchRotated() {
        int[] nums = {7, 8, 9, 10, 12, 5};
        int target = 10;
        int expected = 3;
        int computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        nums = new int[]{12, 5, 7, 8, 9, 10};
        target = 10;
        expected = 5;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        nums = new int[]{6, 7, 1, 2, 3, 4, 5};
        target = 3;
        expected = 4;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        nums = new int[]{6, 7, 1, 2, 3, 4, 5};
        target = 1;
        expected = 2;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        nums = new int[]{4, 5, 6, 1, 2, 3};
        target = 3;
        expected = 5;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        nums = new int[]{4, 5, 6, 1, 2, 3};
        target = 6;
        expected = 2;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        nums = new int[]{4};
        target = 1;
        expected = -1;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

        System.out.println("Completed here");
        nums = new int[]{4, 5, 6, 1, 2, 3};
        target = 8;
        expected = -1;
        computed = binarySearchRotated(nums, target);
        Assertions.assertEquals(expected, computed);

    }
}
