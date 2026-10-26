package parkingSpot;

import java.util.ArrayList;

public class ParkingSpotManagerFactory {
    ParkingSpotManager twoWheelerParkingSpotManager;
    ParkingSpotManager fourWheelerParkingSpotManager;

    public ParkingSpotManagerFactory() {
        if (twoWheelerParkingSpotManager==null){
            twoWheelerParkingSpotManager = new ParkingSpotManager(new ArrayList<>());
        }
        if (fourWheelerParkingSpotManager==null){
            fourWheelerParkingSpotManager = new ParkingSpotManager(new ArrayList<>());
        }
    }

    public ParkingSpotManager getParkingSpotManager(VehicleType vehicleType) {
        if (vehicleType==VehicleType.TWO_WHEELER){
            return twoWheelerParkingSpotManager;
        }else if (vehicleType==VehicleType.FOUR_WHEELER){
            return fourWheelerParkingSpotManager;
        }else{
            System.out.println("Invalid VehicleType");
            return null;
        }
    }
}
