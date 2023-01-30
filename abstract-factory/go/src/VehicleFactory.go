package src

import (
  "microwind/src/shop"

  "microwind/src/vehicle"
)

const (
  VehicleType_BUS        = "bus"
  VehicleType_CAR        = "car"
  VehicleType_MOTORCYCLE = "motorcycle"
  VehicleType_VAN        = "van"
)

type VehicleFactory struct {
}

func (v *VehicleFactory) GetVehicle(vehicleType string, name string) vehicle.Vehicle {
  switch vehicleType {
  case VehicleType_BUS:
    return &vehicle.Bus{
      Name: name,
    }
  case VehicleType_CAR:
    return &vehicle.Car{
      Name: name,
    }
  case VehicleType_MOTORCYCLE:
    return &vehicle.Motorcycle{
      Name: name,
    }
  case VehicleType_VAN:
    return &vehicle.Van{
      Name: name,
    }
  default:
    return nil
  }
}

func (v *VehicleFactory) GetShop(shopType string, name string) shop.Shop {
  // ignored, this function for Shop
  return nil
}
