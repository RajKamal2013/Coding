package io.datajek.spring.unitTesting;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class RecommenderImplementationUnitTest {

    @Test
    void testRecommendMovies_withColloborativeFilter() {
        RecommenderImplementation recommenderImpl = new RecommenderImplementation(new CollaborativeFilter());
        assertArrayEquals(new String[] {"CollaborativeFilter", "Finding Nemo", "Ice Age", "Toy Story"},
                recommenderImpl.recommendMovies("Finding Dory"));
    }

    @Test
    void testRecommendMovies_withContentbasedFilter() {
        RecommenderImplementation recommenderImpl = new RecommenderImplementation(new ContentBasedFilter());
        assertArrayEquals(new String[]{"ContentBasedFilter", "Happy Feet", "Ice Age", "Shark Tale"}, recommenderImpl.recommendMovies("Finding Dory"));
    }
}
