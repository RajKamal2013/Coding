package org.example.models;


import lombok.Builder;
import lombok.Data;

import java.util.Map;

@Builder
@Data
public class ValidationResponse {
    String code;
    Map<String, String> context;
    String message;
    String remediationMessage;
    ValidationResponse[] nestedResponse;
}

