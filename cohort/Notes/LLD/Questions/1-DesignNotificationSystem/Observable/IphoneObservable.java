package Observable;

import java.util.ArrayList;
import java.util.List;

import Observer.Observer;

public class IphoneObservable implements Observable {

    List<Observer> observers;
    int count;

    public IphoneObservable() {
        this.count = 0;
        observers = new ArrayList<>();
    }

    @Override
    public void addObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o : observers) {
            o.update();
        }
    }

    public void setCount(int count) {
        if (this.count == 0) {
            this.count += count;
            notifyObservers();
        }else {
            this.count += count;
        }
    }
    
}
