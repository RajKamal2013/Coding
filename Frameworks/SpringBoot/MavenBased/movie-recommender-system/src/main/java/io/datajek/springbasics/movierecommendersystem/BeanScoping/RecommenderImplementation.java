package io.datajek.springbasics.movierecommendersystem.Autowiring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

import java.util.Arrays;

/**
 * Understanding the different type of Autowiring
 *  1. Primary
 *  2. By Name
 *  3. Using Qualifier
 */

@Component
public class RecommenderImplementation {

    @Autowired
    private Filter filter;

    /* Injection via name */
    @Autowired
    private Filter contentBasedFilter;

    @Autowired
    @Qualifier("CollaborativeFilter")
    /* Qualifier based injection */
    private Filter qualifierBasedFilter;

    public RecommenderImplementation(Filter filter) {
        this.filter = filter;
    }
    public String[] recommendMovies (String movie) {

        System.out.println("Name of Primary filter in use: " + filter);
        String[] results = filter.getRecommendations(movie);
        System.out.println(Arrays.toString(results) + "\n");

        /* IF primary annotation is set then name based does not work and primary is returned */
        System.out.println("Name of Name based filter in use: " + contentBasedFilter);
        String[] results1 = contentBasedFilter.getRecommendations(movie);
        System.out.println(Arrays.toString(results1)+ "\n");

        System.out.println("Name of Qualifier based filter in use: " + qualifierBasedFilter);
        String[] results2 = qualifierBasedFilter.getRecommendations(movie);
        System.out.println(Arrays.toString(results2) + "\n");

        return results;
    }
}
