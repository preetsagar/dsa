package Observable;

import Observer.Observer;

public interface Observable {
    void addObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObservers();
    void setCount(int count);
}
