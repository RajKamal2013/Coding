package io.datajek.springbasics.movierecommendersystem;

public interface Filter {
    public String[] getRecommendations(String Movie);
}
