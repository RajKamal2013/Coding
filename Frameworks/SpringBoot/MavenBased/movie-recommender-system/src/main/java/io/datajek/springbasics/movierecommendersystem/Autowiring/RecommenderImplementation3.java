package io.datajek.springbasics.movierecommendersystem;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

/**
 * Setter based injection
 */
@Component
public class RecommenderImplementation3 {
    private Filter filter;

    @Autowired
    @Qualifier("ContentBasedFilter")
    void setFilter(Filter filter) {
        this.filter = filter;
        System.out.println("Setter method invoked..");
    }

    public String [] recommendMovies (String movie) {

        System.out.println("\nName of the filter in use: " + filter);

        String[] results = filter.getRecommendations("Finding Dory");

        return results;
    }

}
