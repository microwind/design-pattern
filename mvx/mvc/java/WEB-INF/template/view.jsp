 <%!--
 // /WEB-INF/template/view.jsp
  // View，使用JSP
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