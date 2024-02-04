package io.datajek.spring.unitTesting;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

@ExtendWith(SpringExtension.class)
@ContextConfiguration(classes = MovieRecommenderApplication.class)
class RecommenderImplementationSpringTest {

  @Autowired private RecommenderImplementation recommenderImpl;

  @Test
  void testRecommendMovies() {
    System.out.println("Testing Movie Recommendations with Spring Test");
    assertArrayEquals(
        new String[] {"CollaborativeFilter", "Finding Nemo", "Ice Age", "Toy Story"},
        recommenderImpl.recommendMovies("Finding Dory"));
  }
}


