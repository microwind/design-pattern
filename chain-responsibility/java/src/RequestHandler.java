package src;

// 请求是否安全合法检查
public class RequestHandler extends AbstractHandler {
    // 如果检查不通过则返回失败，否则继续下一个检查
    public boolean check(int uid) {
      System.out.println(this.getClass().getName() + "::check() [uid = " + uid + "]");
      if (uid % 1 != 0) {
          return false;
      }
      return checkNext(uid);
  }
}
