import { VehicleType } from '../src/VehicleFactory.js';
import { FactoryCreator } from '../src/FactoryCreator.js';
export function test() {
    const vehicleFactory = FactoryCreator.getFactory('vehicle');
    if (!vehicleFactory) {
        return;
    }
    const bus = vehicleFactory.getVehicle(VehicleType.BUS);
    bus && bus.run();
    const car = vehicleFactory.getVehicle(VehicleType.CAR);
    car && car.run();
    const motorcycle = vehicleFactory.getVehicle(VehicleType.MOTORCYCLE);
    motorcycle && motorcycle.run();
    const van = vehicleFactory.getVehicle(VehicleType.VAN);
    van && van.run();
    const shopFactory = FactoryCreator.getFactory('shop');
    const shop = shopFactory && shopFactory.getShop('SupermarketShop', {});
    shop && shop.greetings();
    const shopFactory2 = FactoryCreator.getFactory('shop');
    const directSaleShop = shopFactory2 && shopFactory2.getShop('DirectSaleShop', {});
    if (directSaleShop) {
        directSaleShop.greetings();
        directSaleShop.welcome();
    }
}
;
(function () {
    console.log('test start:');
    test();
})();
