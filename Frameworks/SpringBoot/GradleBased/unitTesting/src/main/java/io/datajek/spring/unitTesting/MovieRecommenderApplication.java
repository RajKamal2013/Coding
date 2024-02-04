package io.datajek.spring.unitTesting;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import java.util.Arrays;

@SpringBootApplication
public class MovieRecommenderApplication {

	public static void main(String[] args) {

		ApplicationContext appContext = SpringApplication.run(MovieRecommenderApplication.class, args);
		RecommenderImplementation recommender = appContext.getBean(RecommenderImplementation.class);
		String[] result = recommender.recommendMovies("Finding Dory");
    	System.out.println(Arrays.toString(result));
	}
}
