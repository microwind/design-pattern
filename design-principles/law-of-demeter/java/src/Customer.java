package src;

/**
 * Customer类，减轻逻辑，调用购物车来实现商品的购买，不直接跟商品交互。
 */
public class Customer {
    private String name;
    private ShoppingCart shoppingCart;

    public Customer(String name) {
        this.name = name;
        this.shoppingCart = new ShoppingCart();
    }

    public void buy(Product product) {
        // 只跟购物车打交道，且不用了解购物车实现细节，只是调用购物车方法
        if (shoppingCart.validateProduct(product)) {
            shoppingCart.addProduct(product);
            double totalPrice = shoppingCart.calculateTotalPrice();
            System.out.println(name + " 购买了 " + product.getName() + " 价格为 " + totalPrice);
        } else {
            System.out.println(product.getName() + "的价格超出范围：" + product.getPrice());
        }
    }
}