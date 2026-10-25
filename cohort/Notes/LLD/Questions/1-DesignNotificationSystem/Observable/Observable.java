package Observable;

import Observer.Observer;

public interface Observable {
    void addObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers();
    void setCount(int count);
    String getNotificationMessage();
}
