import Payment.CardPayment;
import Payment.GpayPayment;
import Vehicle.Vehicle;
import gate.EntryGate;
import gate.ExitGate;
import parkingSpot.ParkingSpot;
import parkingSpot.ParkingSpotManagerFactory;
import parkingSpot.VehicleType;
import ticket.Ticket;

public class ParkingLotMain {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Welcome to Parking Lot");

        ParkingSpotManagerFactory parkingSpotManagerFactory = new ParkingSpotManagerFactory();
        parkingSpotManagerFactory
                .getParkingSpotManager(VehicleType.TWO_WHEELER)
                .addParkingSpot(new ParkingSpot(1, VehicleType.TWO_WHEELER))
                .addParkingSpot(new ParkingSpot(2, VehicleType.TWO_WHEELER))
                .addParkingSpot(new ParkingSpot(3, VehicleType.TWO_WHEELER));

        parkingSpotManagerFactory.getParkingSpotManager(VehicleType.FOUR_WHEELER)
                .addParkingSpot(new ParkingSpot(4, VehicleType.FOUR_WHEELER))
                .addParkingSpot(new ParkingSpot(5, VehicleType.FOUR_WHEELER))
                .addParkingSpot(new ParkingSpot(6, VehicleType.FOUR_WHEELER));



        Vehicle car = new Vehicle(1, 1234, VehicleType.FOUR_WHEELER);
        Vehicle car2 = new Vehicle(2, 2345, VehicleType.FOUR_WHEELER);
        Vehicle bike = new Vehicle(1, 6678, VehicleType.TWO_WHEELER);
        Vehicle bike2 = new Vehicle(2, 2345, VehicleType.TWO_WHEELER);

        EntryGate entryGate = new EntryGate(parkingSpotManagerFactory);
        ExitGate exitGate = new ExitGate(parkingSpotManagerFactory);

        Ticket t1 = parkVehicle(entryGate, car);
        Ticket t2 = parkVehicle(entryGate, car2);
        Ticket t3 = parkVehicle(entryGate, bike);
        Ticket t4 = parkVehicle(entryGate, bike2);

        Thread.sleep(1000);

        long pay = exitGate.calculatePrice(t1);
        exitGate.pay(pay, new CardPayment(), t1);

        Thread.sleep(1000);
        pay = exitGate.calculatePrice(t2);
        exitGate.pay(pay, new GpayPayment(), t2);

        Thread.sleep(1000);
        pay = exitGate.calculatePrice(t3);
        exitGate.pay(pay, new GpayPayment(), t3);

        Thread.sleep(1000);
        pay = exitGate.calculatePrice(t4);
        exitGate.pay(pay, new CardPayment(), t4);

    }

    private static Ticket parkVehicle(EntryGate entryGate, Vehicle vehicle) {
        ParkingSpot parkingSpot = entryGate.getParkingSpot(vehicle);
        if (parkingSpot == null) {
            throw new IllegalStateException("No available parking spot for " + vehicle.getVehicleType());
        }
        return entryGate.parkVehicle(vehicle, parkingSpot);
    }
}
