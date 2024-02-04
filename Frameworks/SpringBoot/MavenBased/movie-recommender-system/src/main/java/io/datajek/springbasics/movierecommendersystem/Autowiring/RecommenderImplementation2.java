package io.datajek.springbasics.movierecommendersystem;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

/**
 * Constructor based injection
 */

@Component
public class RecommenderImplementation2 {
    private Filter filter;

    RecommenderImplementation2(@Qualifier("CollaborativeFilter") Filter filter){
        super();
        this.filter = filter;
        System.out.println("Constructor Invoked...");
    }

    public String [] recommendMovies (String movie) {

        System.out.println("\nName of the filter in use: " + filter);

        String[] results = filter.getRecommendations("Finding Dory");

        return results;
    }
}
