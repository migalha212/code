package com.up202304387.Lab06.bar.clients;

import com.up202304387.Lab06.bar.Bar;

public interface BarObserver {
    void happyHourStarted(Bar bar);
    void happyHourEnded(Bar bar);
}
