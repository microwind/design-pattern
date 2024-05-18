package src;

/**
 * 这个例子符合开闭原则，为了演示方便把其他类作为子类放在一起。
 * 1. 各品类有自己的折扣策略，而不是把策略都写在一个折扣策略里。
 * 2. 当有新的品类和折扣策略时，而无需修改现有代码，只需要扩展一个品类和折扣即可。
 */
public class OpenClosed_example {
  public OpenClosed_example() {
    return;
  }

  /*** 这是开闭原则的反例 ***/
  // 将各种折扣策略写在一个类里面，那么每次增加品类或者修改策略都涉及修改
  // 这样就不利于代码扩展和维护
  public class DiscountCalculator {

    // 这个方法逻辑复杂，先判断商品类型，在计算各种商品对应的打折策略
    public double applyDiscount(String itemType, double price, int quantity) {
      double totalPrice = price * quantity;
      if (itemType.equals("book")) {
        return totalPrice * 0.9; // 书籍打9折
      } else if (itemType.equals("clothing")) {
        if (quantity > 2) {
          return totalPrice * 0.8; // 超过两件衣服打8折
        } else {
          return totalPrice;
        }
      } else if (itemType.equals("electronic")) {
        if (quantity >= 5) {
          return totalPrice * 0.7; // 超过五件打7折
        } else {
          return totalPrice;
        }
      } else {
        return totalPrice; // 其他类型没有折扣
      }
    }
  }

  /*** 以下是开闭原则的正确例子 ***/

  // 先将折扣策略抽象为一个接口，不同品类实现自己的折扣策略
  // 当有新的品类增加时，不用修改原逻辑，只需扩展新的品类策略即可
  public interface DiscountStrategy {
    double applyDiscount(double price, int quantity);
  }

  public class BookDiscountStrategy implements DiscountStrategy {
    @Override
    public double applyDiscount(double price, int quantity) {
      // 书籍折扣逻辑
      return price * quantity * 0.9;
    }
  }

  public class ClothingDiscountStrategy implements DiscountStrategy {
    @Override
    public double applyDiscount(double price, int quantity) {
      // 衣物折扣逻辑
      if (quantity > 2) {
        return price * quantity * 0.8;
      } else {
        return price * quantity;
      }
    }
  }

  // 类似这样扩展，还可以扩展很多品类折扣策略来
  public class ElectronicsDiscountStrategy implements DiscountStrategy {
    @Override
    public double applyDiscount(double price, int quantity) {
      // 电子产品折扣逻辑
      if (quantity >= 5) {
        return price * quantity * 0.7;
      } else {
        return price * quantity;
      }
    }
  }

  public static void main(String[] args) {
    OpenClosed_example openClosed_example = new OpenClosed_example();

    // 书本单价与数量
    double bookPrice = 100.0; // 商品单价
    int bookQuantity = 3; // 购买数量

    // 衣物单价与数量
    double clothingPrice = 200.0; // 商品单价
    int clothingQuantity = 5; // 购买数量

    double electronicPrice = 800.0; // 商品单价
    int electronicQuantity = 2; // 购买数量

    /*** 先测试反例 ***/
    DiscountCalculator discountCalculator = openClosed_example.new DiscountCalculator();
    System.out.println("Book final price: " + discountCalculator.applyDiscount("book", bookPrice, bookQuantity));
    System.out.println(
        "Clothing final price: " + discountCalculator.applyDiscount("clothing", clothingPrice, clothingQuantity));
    System.out.println("Electronic final price: "
        + discountCalculator.applyDiscount("electronic", electronicPrice, electronicQuantity));

    // *********************** 分割线 ******************************************/
    System.out.println("***********************");
    /*** 再测试正确例子 ***/
    // 创建书本的折扣策略对象
    DiscountStrategy bookStrategy = openClosed_example.new BookDiscountStrategy();
    double bookFinalPrice = bookStrategy.applyDiscount(bookPrice, bookQuantity);
    System.out.println("Book final price: " + bookFinalPrice);

    // 创建衣物的折扣策略对象
    DiscountStrategy clothingStrategy = openClosed_example.new ClothingDiscountStrategy();
    double clothingFinalPrice = clothingStrategy.applyDiscount(clothingPrice, clothingQuantity);
    System.out.println("Clothing final price: " + clothingFinalPrice);

    // 创建电子产品的折扣策略对象
    DiscountStrategy electronicStrategy = openClosed_example.new ElectronicsDiscountStrategy();
    double electronicFinalPrice = electronicStrategy.applyDiscount(electronicPrice, electronicQuantity);
    System.out.println("Electronic final price: " + electronicFinalPrice);

  }
}

/** 测试验证
jarry@jarrys-MacBook-Pro open-closed % cd java
jarry@jarrys-MacBook-Pro java % javac src/OpenClosed_example.java 
jarry@jarrys-MacBook-Pro java % java src/OpenClosed_example 
Book final price: 270.0
Clothing final price: 800.0
Electronic final price: 1600.0
***********************
Book final price: 270.0
Clothing final price: 800.0
Electronic final price: 1600.0
 */