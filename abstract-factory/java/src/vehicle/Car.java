package src.vehicle;
public class Car implements Vehicle {
 
  @Override
  public void run() {
     System.out.println("Car::run().");
  }
}