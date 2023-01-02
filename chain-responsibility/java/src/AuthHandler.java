package src;

// 权限检查类
public class AuthHandler extends AbstractHandler {
    // 如果检查不通过则返回失败，否则继续下一个检查
    public boolean check(int uid) {
      System.out.println(this.getClass().getName() + "::check() [uid = " + uid + "]");
      if (uid % 2 == 0) {
          return false;
      }
      return checkNext(uid);
  }
}