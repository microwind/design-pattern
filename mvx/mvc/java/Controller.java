  // src/mvc/Controller.java
  import javax.servlet.RequestDispatcher;
  import javax.servlet.ServletException;
  import javax.servlet.annotation.WebServlet;
  import javax.servlet.http.HttpServlet;
  import javax.servlet.http.HttpServletRequest;
  import javax.servlet.http.HttpServletResponse;
  import java.io.IOException;

// 1. 控制器Controller。负责处理接受请求和调用后端服务映射模型到视图层，然后将内容返回给请求方。
// 2. 早期的架构均是将Model等数据映射到view层进行渲染，新的架构体系则直接将数据以JSON格式返回给请求方。
// 3. 控制层只是负责接入和响应，不要进行业务逻辑和数据模型处理，这样这一层只是作为入口分发层，从而比较轻薄。
// 4. 分层隔离后，控制层的改动不影响底层的服务。控制层也可以轻易调用其他服务层。
  @WebServlet(
          name = "ModelServlet",
          urlPatterns = "/hello-model")
  public class Controller extends HttpServlet {
      private ModelService modelService = new ModelService();
      private void processRequest(
          HttpServletRequest request, HttpServletResponse response)
          throws ServletException, IOException {
          modelService.getModel().ifPresent(s -> {
              request.setAttribute("helloModel", s);
          });
          RequestDispatcher dispatcher = request.getRequestDispatcher(
                  "/WEB-INF/template/model.jsp");
          dispatcher.forward(request, response);
      }

      @Override
      protected void doGet(
              HttpServletRequest request, HttpServletResponse response)
              throws ServletException, IOException {
          processRequest(request, response);
      }

      @Override
      protected void doPost(
              HttpServletRequest request, HttpServletResponse response)
              throws ServletException, IOException {
          processRequest(request, response);
      }
  }
