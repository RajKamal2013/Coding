package io.datajek.springbasics.movierecommendersystem.Autowiring;

import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.context.annotation.Primary;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component("CollaborativeFilter")
@Primary
public class CollaborativeFilter implements Filter {

    public CollaborativeFilter() {
        super();
        System.out.println("Collaborative filter constructor called");
    }

    @Override
    public String[] getRecommendations(String Movie) {
        return new String[] {"Finding Nemo", "Ice Age", "Toy Story"};
    }
}
