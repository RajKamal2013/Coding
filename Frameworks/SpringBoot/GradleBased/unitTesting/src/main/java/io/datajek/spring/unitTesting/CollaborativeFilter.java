package io.datajek.spring.unitTesting;


import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;

@Component
@Primary
public class CollaborativeFilter implements  Filter {
    @Override
    public String[] getRecommendataions(String movie) {
        return new String[] {"CollaborativeFilter", "Finding Nemo", "Ice Age", "Toy Story"};
    }
}
