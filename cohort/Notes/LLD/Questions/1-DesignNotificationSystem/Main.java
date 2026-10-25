import Observable.IphoneObservable;
import Observable.Observable;
import Observer.EmailObserver;
import Observer.MessageObserver;
import Observer.Observer;

public class Main {
    public static void main(String[] args) {
        Observable observable = new IphoneObservable();

        Observer messageObserver = new MessageObserver(observable);
        Observer emailObserver = new EmailObserver(observable);

        observable.addObserver(messageObserver);
        observable.addObserver(emailObserver);

        observable.setCount(10);
        observable.setCount(10);
    }
}
