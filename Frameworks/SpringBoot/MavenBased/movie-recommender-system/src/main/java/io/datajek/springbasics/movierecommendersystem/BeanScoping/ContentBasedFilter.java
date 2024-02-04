package io.datajek.springbasics.movierecommendersystem.Autowiring;

import org.springframework.stereotype.Component;

@Component("ContentBasedFilter")
public class ContentBasedFilter implements Filter {
    public ContentBasedFilter() {
        super();
        System.out.println("content-based filter constructor called");
    }
    @Override
    public String[] getRecommendations(String movie) {
        return new String[] {"Happy Feet", "Ice Age", "Shark Tale"};
    }
}
