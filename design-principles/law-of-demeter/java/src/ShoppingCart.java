package src;

import java.util.ArrayList;
import java.util.List;

/**
 * ShoppingCart类，负责商品校验价格计算等逻辑，是顾客和商品之间的桥梁
 */
class ShoppingCart {
  private List<Product> products;

  public ShoppingCart() {
    this.products = new ArrayList<>();
  }

  public void addProduct(Product product) {
    products.add(product);
  }

  public double calculateTotalPrice() {
    double totalPrice = 0.0;
    for (Product product : products) {
      totalPrice += product.getPrice();
    }
    return totalPrice;
  }

  public boolean validateProduct(Product product) {
    double price = product.getPrice();
    return price > 1000;
  }
}