package Observable;

import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.Objects;
import java.util.Set;

import Observer.Observer;

public class IphoneObservable implements Observable {

    private final Set<Observer> observers;
    private int count;

    public IphoneObservable() {
        this.count = 0;
        observers = new LinkedHashSet<>();
    }

    @Override
    public void addObserver(Observer observer) {
        observers.add(Objects.requireNonNull(observer, "observer must not be null"));
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : new ArrayList<>(observers)) {
            observer.update();
        }
    }

    public void setCount(int count) {
        if (count < 0) {
            throw new IllegalArgumentException("count must not be negative");
        }

        boolean wasOutOfStock = this.count == 0;
        this.count = count;
        if (wasOutOfStock && count > 0) {
            notifyObservers();
        }
    }

    @Override
    public String getNotificationMessage() {
        return "iPhone is back in stock";
    }
    
}
