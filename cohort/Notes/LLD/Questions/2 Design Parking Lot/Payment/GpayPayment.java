package Payment;

public class GpayPayment implements Payment {
    @Override
    public boolean pay(long bill) {
        System.out.println("Paid " + bill + "₹ via Gpay");
        return true;
    }
}
