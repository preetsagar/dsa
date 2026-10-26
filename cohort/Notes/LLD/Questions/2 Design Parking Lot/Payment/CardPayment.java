package Payment;

public class CardPayment implements Payment {
    @Override
    public boolean pay(long bill) {
        System.out.println("Paid " + bill + "₹ via Card");
        return true;
    }
}
