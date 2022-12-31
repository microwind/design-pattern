package src;

import java.util.*;

// 实现部件的树枝构件2
public class DepartmentComposite implements OrganizationComponent {

   private String name;
   private List<OrganizationComponent> children = new ArrayList<OrganizationComponent>();

   public DepartmentComposite(String name) {
      this.name = name;
   }

   public void add(OrganizationComponent component) {
      children.add(component);
   }

   public void remove(OrganizationComponent component) {
      children.remove(component);
   }

   public OrganizationComponent getChild(int index) {
      return children.get(index);
   }

   public void operation() {
      System.out.println(this.getClass().getName() + " DepartmentComposite::operation() " + this.name);
      for (Object component : children) {
         ((OrganizationComponent) component).operation();
      }
   }

   public String getName() {
      return name;
   }
}