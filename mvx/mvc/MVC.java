// Model
class Model {
    private String name;
    private int num;

    public Model() {
        this.name = "MVC Basic";
        this.num = 1;
    }

    public String getName() {
        return name;
    }

    public int getNum() {
        return num;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void incrementNum(int value) {
        this.num += value;
    }
}

// View
class View {
    public void display(String name, int num) {
        System.out.println("<div><b>" + name + "</b><em>" + num + "</em></div>");
    }
}

// Controller
class Controller {
    private Model model;
    private View view;

    public Controller(Model model, View view) {
        this.model = model;
        this.view = view;
    }

    public void onButtonClick() {
        model.incrementNum(1); 
        view.display(model.getName(), model.getNum());
    }

    public void onMouseOut() {
        model.setName("Click to add");
        view.display(model.getName(), model.getNum());
    }
}

// Test
public class MVC {
    public static void main(String[] args) {
        Model model = new Model();
        View view = new View();
        Controller controller = new Controller(model, view);
        
        System.out.println("Test 1: Button Click");
        controller.onButtonClick();  // simulate button click
        System.out.println("Test 2: Mouse Out");
        controller.onMouseOut();     // simulate mouse out
    }
}

/* 
jarry@MacBook-Pro mvc % java MVC.java 
Test 1: Button Click
<div><b>MVC Basic</b><em>2</em></div>
Test 2: Mouse Out
<div><b>Click to add</b><em>2</em></div>
*/
