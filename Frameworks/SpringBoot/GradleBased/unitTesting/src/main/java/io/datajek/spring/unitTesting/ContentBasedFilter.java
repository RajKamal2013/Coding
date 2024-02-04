package io.datajek.spring.unitTesting;

import org.springframework.stereotype.Component;

@Component
public class ContentBasedFilter implements Filter {

    @Override
    public String[] getRecommendataions(String movie) {
        return new String[] {"ContentBasedFilter", "Happy Feet", "Ice Age", "Shark Tale"};
    }
}
