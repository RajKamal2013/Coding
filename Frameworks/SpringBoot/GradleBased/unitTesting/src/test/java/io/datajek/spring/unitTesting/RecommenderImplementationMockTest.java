package io.datajek.spring.unitTesting;


import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.mockito.Mockito.when;

@ExtendWith(MockitoExtension.class)
class RecommenderImplementationMockTest {

    @InjectMocks
    private RecommenderImplementation recommenderImpl;

    @Mock
    private Filter mockFilter;

    @Test
    void testRecommendMovies_noRecommendationsFound() {
        when(mockFilter.getRecommendataions("Finding Dory")).thenReturn(new String[] {});
        assertArrayEquals(new String[] {}, recommenderImpl.recommendMovies("Finding Dory"));
    }
}