package src

const (
  VehicleType_BUS        = "bus"
  VehicleType_CAR        = "car"
  VehicleType_MOTORCYCLE = "motorcycle"
  VehicleType_VAN        = "van"
)

// 定义对象生产工具类
type VehicleFactory struct {
}

func (v *VehicleFactory) GetVehicle(vehicleType string) Vehicle {
  switch vehicleType {
  case VehicleType_BUS:
    return new(Bus)
  case VehicleType_CAR:
    return new(Car)
  case VehicleType_MOTORCYCLE:
    return new(Motorcycle)
  case VehicleType_VAN:
    return new(Van)
  default:
    return nil
  }
}
