import { VehicleFactory } from './VehicleFactory.js';
import { ShopFactory } from './ShopFactory.js';
export class FactoryCreator {
    static getFactory(name) {
        switch (name) {
            case 'vehicle':
                return new VehicleFactory();
            case 'shop':
                return new ShopFactory();
            default:
                return;
        }
    }
}
