import { Bus } from './vehicle/Bus.js';
import { Car } from './vehicle/Car.js';
import { Motorcycle } from './vehicle/Motorcycle.js';
import { Van } from './vehicle/Van.js';
import { AbstractFactory } from './AbstractFactory.js';
export var VehicleType;
(function (VehicleType) {
    VehicleType["BUS"] = "bus";
    VehicleType["CAR"] = "car";
    VehicleType["MOTORCYCLE"] = "motorcycle";
    VehicleType["VAN"] = "van";
})(VehicleType || (VehicleType = {}));
export class VehicleFactory extends AbstractFactory {
    getVehicle(type) {
        switch (type) {
            case VehicleType.BUS:
                return new Bus();
            case VehicleType.CAR:
                return new Car();
            case VehicleType.MOTORCYCLE:
                return new Motorcycle();
            case VehicleType.VAN:
                return new Van();
            default:
                return;
        }
    }
    getShop(type) {
        return;
    }
}
