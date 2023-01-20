import { Vehicle } from './Vehicle.js'
// 具体产品类，实现抽象产品类
export class Car implements Vehicle {
	run() {
		console.log('Car::run().')
	}
}
