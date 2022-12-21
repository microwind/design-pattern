package src.vehicle;

public enum VehicleType {
  BUS("bus", 1),
  CAR("car", 2),
  MOTORCYCLE("motorcycle", 3),
  VAN("van", 4);

  private String name;
  private int index;

  public static String getName(int index) {
    VehicleType values[] = VehicleType.values();
    for (int i = 0; i < values.length; i++) {
      if (values[i].getIndex() == index) {
        return values[i].getName();
      }
    }
    return null;
  }

  private VehicleType(String name, int index) {
    this.name = name;
    this.index = index;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getIndex() {
    return index;
  }

  public void setIndex(int index) {
    this.index = index;
  }
}