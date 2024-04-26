 <%!--
 // /WEB-INF/template/view.jsp
 // 1. View，负责视图呈现。早期有JSP、JSTL、Velocity、Freemarker等。
 // 2. 主要就是将数据按照HTML/CSS输出，得到Web页面。
 // 3. 这里使用JSP演示，JSP已经很少使用了。
 // 4. 新的前后分离，采取由JS来渲染页面，后端只是提供API。因此这在微服务体系中可以省略。
%-->
  <%@ page import="mvc.Model" %>
  <html>
  <head>
    <title>Hello Model</title>
  </head>
  <body>
  <h1>Hello Model</h1>
  <%
    if (request.getAttribute("helloModel") != null) {
        System.out.print(new Model());
        Model model = (Model) request.getAttribute("helloModel");
  %>
  <div>Name: <%= model.getName()%></div>
  <div>Num: <%= model.getNum()%></div>
  <% } %>
  </body>
  </html>
