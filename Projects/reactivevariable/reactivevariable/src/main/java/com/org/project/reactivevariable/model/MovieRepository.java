package com.org.project.reactivevariable.model;

import com.org.project.reactivevariable.aop.MeasureTime;
import org.springframework.stereotype.Repository;

@Repository
public class MovieRepository {
    @MeasureTime
    public String getMovieDetails() {
        return "movie_details";
    }
}
