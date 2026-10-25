package Observer;

import Observable.Observable;

public class EmailObserver implements Observer {

    Observable observable;

    public EmailObserver(Observable observable) {
        this.observable = observable;
    }

    @Override
    public void update() {
        System.out.println("EmailObserver: Received notification");
    }
    
}
