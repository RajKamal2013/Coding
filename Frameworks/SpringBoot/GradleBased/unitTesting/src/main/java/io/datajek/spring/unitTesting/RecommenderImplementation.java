package io.datajek.spring.unitTesting;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class RecommenderImplementation {
    @Autowired
    private Filter filter;

    public RecommenderImplementation(Filter filter) {
        super();
        this.filter = filter;
    }

    public String[] recommendMovies(String movie) {
        System.out.println("\nName of the filter in use: " + filter + "\n");
        String[] results = filter.getRecommendataions("Finding Dory");
        return results;
  }
}
