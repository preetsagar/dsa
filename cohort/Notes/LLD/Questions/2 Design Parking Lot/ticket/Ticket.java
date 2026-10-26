package ticket;

import Vehicle.Vehicle;
import parkingSpot.ParkingSpot;

public class Ticket {
    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public ParkingSpot getParkingSpot() {
        return parkingSpot;
    }

    public void setParkingSpot(ParkingSpot parkingSpot) {
        this.parkingSpot = parkingSpot;
    }

    public Long getEntryTime() {
        return entryTime;
    }

    public boolean isPaid() {
        return paid;
    }

    Vehicle vehicle;
    ParkingSpot parkingSpot;
    Long entryTime;
    private boolean paid;

    public Ticket(Vehicle vehicle, ParkingSpot parkingSpot) {
        this.vehicle = vehicle;
        this.parkingSpot = parkingSpot;
        this.entryTime = System.currentTimeMillis();
        this.paid = false;
    }

    public void markPaid() {
        this.paid = true;
    }
}
