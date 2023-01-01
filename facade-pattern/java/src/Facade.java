package src;

// 外观模式实现类，是外部调用与内部子系统的衔接层
public class Facade implements AbstractFacade {

   private FileModule fileModule;
   private NetworkModule networkModule;
   private EncodeModule encodeModule;

   public Facade() {
      fileModule = new FileModule();
      networkModule = new NetworkModule();
      encodeModule = new EncodeModule();
   }

   public void encoding(int id) {
      System.out.println(this.getClass().getName() + "::encoding() [id=" + id + "]");
      networkModule.request();
      fileModule.readFile();
      encodeModule.encoding();
      fileModule.saveFile();
   }

   public void encrypt(int id) {
      System.out.println(this.getClass().getName() + "::encrypt() [id=" + id + "]");
      fileModule.readFile();
      encodeModule.encoding();
   }

   public FileModule getFileModule() {
      return this.fileModule;
   }

   public NetworkModule getNetworkModule() {
      return this.networkModule;
   }

   public EncodeModule getEncodeModule() {
      return this.encodeModule;
   }
}
