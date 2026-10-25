package Observer;

import Observable.Observable;

public class MessageObserver implements Observer {

    Observable observable;
    public MessageObserver(Observable observable) {
        this.observable = observable;
    }
    
    @Override
    public void update() {
        System.out.println("MessageObserver: Received notification");
    }
    
}
