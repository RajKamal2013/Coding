package com.org.project.reactivevariable.construct;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class StateVariable<T> {
    private T state;
}
