import { Vehicle } from './Vehicle.js'
export class Car extends Vehicle {
	constructor(options) {
		super(options)
	}
	run() {
		console.log('Car::run().')
	}
}
