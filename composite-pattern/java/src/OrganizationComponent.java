package src;

// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
public interface OrganizationComponent {
   public void add(OrganizationComponent component);

   public void remove(OrganizationComponent component);

   public OrganizationComponent getChild(int index);

   public void operation();

   public String getName();
}