package io.datajek.spring.unitTesting;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

@SpringBootTest
class MovieRecommenderApplicationSpringBootTest {

	@Autowired
	private RecommenderImplementation recommenderImpl;

	@Test
	void testRecommendMovies() {
    	System.out.println("Testing Movie Recommendations with SpringBoot Test");
		assertArrayEquals(new String[] {"CollaborativeFilter", "Finding Nemo", "Ice Age", "Toy Story"},
				recommenderImpl.recommendMovies("Finding Dory"));
	}

}