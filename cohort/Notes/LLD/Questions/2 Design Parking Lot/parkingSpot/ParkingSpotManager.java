package parkingSpot;

import java.util.ArrayList;
import java.util.List;

public class ParkingSpotManager {
    List<ParkingSpot> parkingSpots;

    public List<ParkingSpot> getParkingSpots() {
        return parkingSpots;
    }

    public void setParkingSpots(List<ParkingSpot> parkingSpots) {
        this.parkingSpots = parkingSpots;
    }

    public ParkingSpotManager(List<ParkingSpot> parkingSpots) {
        this.parkingSpots = parkingSpots;
    }

    public ParkingSpotManager addParkingSpot(ParkingSpot parkingSpot) {
        parkingSpots.add(parkingSpot);
        return this;
    }

    public void removeParkingSpot(ParkingSpot parkingSpot) {
        parkingSpots.remove(parkingSpot);
    }

    public ParkingSpot findAvailableParkingSpot() {
        for (ParkingSpot parkingSpot : parkingSpots) {
            if(parkingSpot.getAvailable()) {
                return parkingSpot;
            }
        }
        return null;
    }
}
