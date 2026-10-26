package gate;

import Payment.Payment;
import parkingSpot.ParkingSpot;
import parkingSpot.ParkingSpotManagerFactory;
import parkingSpot.VehicleType;
import ticket.Ticket;

public class ExitGate {
    ParkingSpotManagerFactory parkingSpotManagerFactory;
    Payment payment;

    public ExitGate(ParkingSpotManagerFactory parkingSpotManagerFactory) {
        this.parkingSpotManagerFactory = parkingSpotManagerFactory;
    }

    public long calculatePrice(Ticket ticket){
        if (ticket == null) {
            throw new IllegalArgumentException("Ticket cannot be null");
        }
        long currentTime = System.currentTimeMillis();
        long durationMillis = currentTime - ticket.getEntryTime();

        if (ticket.getVehicle().getVehicleType() == VehicleType.TWO_WHEELER) {
            return durationMillis;
        }
        return durationMillis * 20;
    }

    public void pay(long bill, Payment payment, Ticket ticket){
        if (ticket == null || payment == null) {
            throw new IllegalArgumentException("Ticket and payment method are required");
        }
        if (ticket.isPaid()) {
            throw new IllegalStateException("Ticket has already been paid");
        }
        if (payment.pay(bill)) {
            ticket.markPaid();
            ticket.getParkingSpot().freeParkingSpot();
        }
    }
}
