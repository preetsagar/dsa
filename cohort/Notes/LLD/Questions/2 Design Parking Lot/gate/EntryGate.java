package gate;

import Vehicle.Vehicle;
import parkingSpot.ParkingSpot;
import parkingSpot.ParkingSpotManagerFactory;
import ticket.Ticket;

public class EntryGate {
    ParkingSpotManagerFactory parkingSpotManagerFactory;


    public EntryGate(ParkingSpotManagerFactory parkingSpotManagerFactory) {
        this.parkingSpotManagerFactory = parkingSpotManagerFactory;
    }

    public ParkingSpot getParkingSpot(Vehicle vehicle) {
        if (vehicle == null) {
            throw new IllegalArgumentException("Vehicle cannot be null");
        }
        return parkingSpotManagerFactory
                .getParkingSpotManager(vehicle.getVehicleType())
                .findAvailableParkingSpot();
    }

    public Ticket parkVehicle(Vehicle vehicle, ParkingSpot parkingSpot) {
        if (vehicle == null || parkingSpot == null) {
            throw new IllegalArgumentException("Vehicle and parking spot are required");
        }
        if (!parkingSpot.getAvailable()) {
            throw new IllegalStateException("Parking spot is already occupied");
        }
        if (vehicle.getVehicleType() != parkingSpot.getParkingSpotType()) {
            throw new IllegalArgumentException("Vehicle type does not match parking spot type");
        }
        parkingSpot.assignVehicle();
        return new Ticket(vehicle, parkingSpot);
    }
}
