package org.patterns;


import java.util.*;
import java.util.stream.Collectors;

/* Pattern: K top Element */
public class KTopElement {
    /**
     * Given an array and integer k, return top k frequent elements from the array.
     * Example -> arr = {1, 3, 5, 14, 18, 14, 5}, K = 2
     *          Solution -> {5, 14}
     */
    public static List<Integer> topKFrequent(int[] arr, int k) {

        if (arr == null || arr.length == 0) {
            return new ArrayList<Integer>();
        }

        Map<Integer, Integer> frequencyCount = new HashMap<>();
        for (int n: arr) {
           frequencyCount.put(n, frequencyCount.getOrDefault(n, 0) + 1);
        }


        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>(
                (e1, e2) -> e1.getValue() - e2.getValue()
        );
        for (Map.Entry<Integer, Integer> entry: frequencyCount.entrySet()) {
           minHeap.offer(entry);
           if (minHeap.size() > k) {
               minHeap.poll();
           }
        }

        List<Integer> topKElementList = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            topKElementList.add(minHeap.poll().getKey());
        }
        Collections.sort(topKElementList);
        return topKElementList;
        //return minHeap.stream().map(Map.Entry::getKey).collect(Collectors.toCollection(ArrayList::new));
    }


    public static int findKthLargest(int[] nums, int k) {


        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num: nums) {
            minHeap.offer(num);
            if (minHeap.size() > k){
                minHeap.poll();
            }
        }
        if (minHeap.isEmpty()) {
            return -1;
        }
        return minHeap.peek();
    }

    public static class FrequencyPair {
        Character ch;
        int frequency;

        public FrequencyPair(Character ch, int frequency) {
            this.ch = ch;
            this.frequency = frequency;
        }
    }

    public static String reorganizeString(String string1) {
        if (string1 == null || string1.isEmpty()) {
            return "";
        }

        // Create frequency map of the characters
        Map<Character, Integer> frequencyMap = new HashMap<>();

        for (int i = 0; i < string1.length(); i++) {
            frequencyMap.put(string1.charAt(i), frequencyMap.getOrDefault(string1.charAt(i), 0) + 1);
        }

        PriorityQueue<FrequencyPair> maxHeap =
                new PriorityQueue<>((a, b) -> Integer.compare(b.frequency, a.frequency));
        StringBuilder stringBuilder = new StringBuilder();
        for (Map.Entry<Character, Integer> entry: frequencyMap.entrySet()) {
            maxHeap.offer(new FrequencyPair(entry.getKey(), entry.getValue()));
        }

        while (!maxHeap.isEmpty()) {
            FrequencyPair  maxFrequencyCharacter, nextMaxFrequencyCharacter;
            nextMaxFrequencyCharacter = null;
            maxFrequencyCharacter = maxHeap.poll();
            maxFrequencyCharacter.frequency = maxFrequencyCharacter.frequency - 1;
            if (!maxHeap.isEmpty()) {
                nextMaxFrequencyCharacter = maxHeap.poll();
                nextMaxFrequencyCharacter.frequency = nextMaxFrequencyCharacter.frequency - 1;

                if (stringBuilder.length() > 1 &&
                        stringBuilder.charAt(stringBuilder.length() - 1) == maxFrequencyCharacter.ch) {
                    stringBuilder.append(nextMaxFrequencyCharacter.ch);
                    stringBuilder.append(maxFrequencyCharacter.ch);
                } else {
                    stringBuilder.append(maxFrequencyCharacter.ch);
                    stringBuilder.append(nextMaxFrequencyCharacter.ch);
                }
                if (maxFrequencyCharacter.frequency > 0) {
                    maxHeap.offer(maxFrequencyCharacter);
                }
                if (nextMaxFrequencyCharacter.frequency > 0) {
                    maxHeap.offer(nextMaxFrequencyCharacter);
                }
            } else {
                if (stringBuilder.length() > 1 &&
                        stringBuilder.charAt(stringBuilder.length() - 1) == maxFrequencyCharacter.ch) {
                    stringBuilder.setLength(0);
                    break;
                } else {
                    stringBuilder.append(maxFrequencyCharacter.ch);
                    if (maxFrequencyCharacter.frequency  > 0) {
                        stringBuilder.setLength(0);
                        break;
                    }
                }
            }
        }

        return stringBuilder.toString();
    }

}
