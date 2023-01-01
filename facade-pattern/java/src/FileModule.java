package src;

// 文件模块
public class FileModule {

   public void readFile() {
      System.out.println(this.getClass().getName() + "::readFile() 读取文件。");
   }

   public void saveFile() {
      System.out.println(this.getClass().getName() + "::saveFile() 保存文件。");
   }
}
