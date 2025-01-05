package org.example.spelengine;

import org.springframework.expression.ExpressionParser;
import org.springframework.expression.spel.standard.SpelExpressionParser;
import org.springframework.stereotype.Component;

@Component
public class SpelAst {
    public void printAst() {
        String expression = "4 + 4";
        ExpressionParser parser =  new SpelExpressionParser();
        String value = parser.parseExpression(expression).getValue(String.class);
        System.out.println(value);
    }
}
