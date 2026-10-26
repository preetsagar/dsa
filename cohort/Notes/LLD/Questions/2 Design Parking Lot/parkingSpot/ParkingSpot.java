package parkingSpot;

public class ParkingSpot {
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public VehicleType getParkingSpotType() {
        return parkingSpotType;
    }

    public void setParkingSpotType(VehicleType parkingSpotType) {
        this.parkingSpotType = parkingSpotType;
    }

    public Boolean getAvailable() {
        return isAvailable;
    }

    public void setAvailable(Boolean available) {
        isAvailable = available;
    }

    private int id;
    private VehicleType parkingSpotType;
    private Boolean isAvailable;

    public ParkingSpot(int id, VehicleType parkingSpotType) {
        this.id = id;
        this.parkingSpotType = parkingSpotType;
        this.isAvailable = true;
    }

    public void assignVehicle(){
        this.isAvailable = false;
    }

    public void freeParkingSpot(){
        this.isAvailable = true;
    }

}
