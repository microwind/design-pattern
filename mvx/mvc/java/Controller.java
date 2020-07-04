  // src/mvc/Controller.java
  import javax.servlet.RequestDispatcher;
  import javax.servlet.ServletException;
  import javax.servlet.annotation.WebServlet;
  import javax.servlet.http.HttpServlet;
  import javax.servlet.http.HttpServletRequest;
  import javax.servlet.http.HttpServletResponse;
  import java.io.IOException;

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