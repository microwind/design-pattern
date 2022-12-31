package src;

// 实现部件的叶子节点，叶子节点不能再含有子节点
public class EmployeeLeaf implements OrganizationComponent {

   private String name;

   public EmployeeLeaf(String name) {
      this.name = name;
   }

   // 叶子节点不能再增加内容
   public void add(OrganizationComponent component) {
      System.out.println("Leaf can't add.");
   }

   // 叶子节点没有移除内容
   public void remove(OrganizationComponent component) {
      System.out.println("Leaf can't remove.");
   }

   // 叶子节点无获取子节点
   public OrganizationComponent getChild(int index) {
      System.out.println("Leaf can't getChild.");
      return null;
   }

   public void operation() {
      System.out.println(this.getClass().getName() + " EmployeeLeaf::operation() " + this.name);
   }

   public String getName() {
      return name;
   }
}