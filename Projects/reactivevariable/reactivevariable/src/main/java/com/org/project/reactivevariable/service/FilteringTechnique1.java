package com.org.project.reactivevariable.service;

import com.org.project.reactivevariable.aop.MeasureTime;
import com.org.project.reactivevariable.model.MovieRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class FilteringTechnique1 {

    @Autowired
    private MovieRepository movieRepository;

    @MeasureTime
    public String contentBasedFiltering() {
        String movieDetails = movieRepository.getMovieDetails();
        return movieDetails;
    }
}
