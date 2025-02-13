/*
MVC 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View可与Model绑定。
- Controller：作为用户输入的中介，接收用户的输入并更新 Model 或 View。
*/
// Model (数据模型)
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

    public void setNum(int num) {
        this.num = num;
    }

    public int getNum() {
        return num;
    }

    public void incrementNum(int value) {
        this.num += value;
    }

    public void setName(String name) {
        this.name = name;
    }
}

// View (视图层)
class View {
    // 关联 Model
    private Model model;

    public View(Model model) {
        this.model = model;
    }

    // 更新视图显示，直接从 Model 获取数据
    public void updateView() {
        System.out.println("<div><b>" + model.getName() + "</b><em>" + model.getNum() + "</em></div>");
    }
}

// Controller (控制器)
class Controller {
    private Model model;
    private View view;

    public Controller(Model model, View view) {
        this.model = model;
        this.view = view;
    }

    public void onButtonClick() {
        model.setName("onButtonClick");
        model.incrementNum(1);
        updateView();
    }

    public void onMouseOut() {
        model.setName("onMouseOut");
        model.setNum(0);
        updateView();
    }

    // 由 Controller 调用更新 View
    private void updateView() {
        view.updateView();
    }
}

// Test
public class MVC {
    public static void main(String[] args) {
        Model model = new Model();
        // View 可以持有 Model，或在更新视图时传递Model
        View view = new View(model);
        Controller controller = new Controller(model, view);

        System.out.println("Test 1: Button Click");
        controller.onButtonClick();

        System.out.println("Test 2: Mouse Out");
        controller.onMouseOut();
    }
}

/*
 * jarry@MacBook-Pro mvc % javac MVC.java
 * jarry@MacBook-Pro mvc % java MVC
 * Test 1: Button Click
 * <div><b>onButtonClick</b><em>2</em></div>
 * Test 2: Mouse Out
 * <div><b>onMouseOut</b><em>0</em></div>
 */
