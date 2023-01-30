package src

import (
  "microwind/src/shop"
  "microwind/src/vehicle"
)

type ShopFactory struct {
}

func (s *ShopFactory) GetShop(shopType string, name string) shop.Shop {
  switch shopType {
  case "AgencyShop":
    return &shop.AgencyShop{
      Name: name,
    }
  case "DirectSaleShop":
    return &shop.DirectSaleShop{
      Name: name,
    }
  case "SupermarketShop":
    return &shop.SupermarketShop{
      Name: name,
    }
  default:
    return &shop.AgencyShop{
      Name: name,
    }
  }
}

func (s *ShopFactory) GetVehicle(vehicleType string, name string) vehicle.Vehicle {
  // ignored, this function for Vehicle
  return nil
}
