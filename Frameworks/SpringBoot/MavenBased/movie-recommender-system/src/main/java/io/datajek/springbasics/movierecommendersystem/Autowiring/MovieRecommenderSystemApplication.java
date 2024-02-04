package io.datajek.springbasics.movierecommendersystem.Autowiring;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import java.util.Arrays;

@SpringBootApplication
public class MovieRecommenderSystemApplication {

	public static void main(String[] args) {
		//SpringApplication.run(MovieRecommenderSystemApplication.class, args);

		/*
		 * Simple Implementation

			RecommenderImplementation recommender = new RecommenderImplementation();
		*/

		/*
		 * Implementation using Interface (Docoupled code)
			RecommenderImplementation recommender = new RecommenderImplementation(new ContentBasedFilter());
			RecommenderImplementation recommender = new RecommenderImplementation(new CollaborativeFilter());
			String result[] = recommender.recommendMovies("Finding Dory");
		 */

		/*
		 * Implementation using Spring Boot
		 */
		ApplicationContext appContext = SpringApplication.run(MovieRecommenderSystemApplication.class, args);
		System.out.println("--------------------------------------------------------------");


		// Understanding Autowiring
		System.out.println("\n*************************************************");
		System.out.println("Calling getBean() on RecommenderImplementation");
		RecommenderImplementation recommender = appContext.getBean(RecommenderImplementation.class);
		String[] result = recommender.recommendMovies("Finding Dory");
		System.out.println(Arrays.toString(result));

		//RecommenderImplementation injects dependency using constructor
		System.out.println("\n*************************************************");
		System.out.println("Calling getBean() on RecommenderImplementation2");
		RecommenderImplementation2 recommender2 = appContext.getBean(RecommenderImplementation2.class);
		result = recommender2.recommendMovies("Finding Dory");
		System.out.println(Arrays.toString(result));

		//RecommenderImplementation2 injects dependency using setter method
		System.out.println("\n*************************************************");
		System.out.println("Calling getBean() on RecommenderImplementation3");
		RecommenderImplementation3 recommender3 = appContext.getBean(RecommenderImplementation3.class);
		result = recommender3.recommendMovies("Finding Dory");
		System.out.println(Arrays.toString(result));
		System.out.println("--------------------------------------------------------------");

	}

}
