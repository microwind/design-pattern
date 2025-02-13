/*
MVP 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View不直接绑定Model，而通过Presenter获取数据。
- Presenter：作为中介者，接收用户输入并更新 Model 或 View，处理业务逻辑。
*/
// Model (数据模型)
class Model {
    private String name;
    private int num;

    public Model() {
        this.name = "MVP Basic";
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
    // View 只负责显示数据，并提供更新界面的接口
    public void updateView(String name, int num) {
        System.out.println("<div><b>" + name + "</b><em>" + num + "</em></div>");
    }
}

// Presenter (中介者)
class Presenter {
    private Model model;
    private View view;

    public Presenter(Model model, View view) {
        this.model = model;
        this.view = view;
    }

    // 按钮点击时通过 Presenter 更新 Model 数据并刷新视图
    public void onButtonClick() {
        model.setName("onButtonClick");
        model.incrementNum(1);
        updateView();
    }

    // 鼠标移出时通过 Presenter 更新 Model 数据并刷新视图
    public void onMouseOut() {
        model.setName("onMouseOut");
        model.setNum(0);
        updateView();
    }

    // 由 Presenter 调用更新 View，传递数据，而不是Model
    private void updateView() {
        view.updateView(model.getName(), model.getNum());
    }
}

// Test
public class MVP {
    public static void main(String[] args) {
        Model model = new Model();
        // View 不直接持有 Model，也不传递Model，view针对数据更新
        View view = new View();
        Presenter presenter = new Presenter(model, view);

        System.out.println("Test 1: Button Click");
        presenter.onButtonClick();

        System.out.println("Test 2: Mouse Out");
        presenter.onMouseOut();
    }
}

/*
 * jarry@MacBook-Pro mvp % javac MVP.java
 * jarry@MacBook-Pro mvp % java MVP
 * Test 1: Button Click
 * <div><b>onButtonClick</b><em>2</em></div>
 * Test 2: Mouse Out
 * <div><b>onMouseOut</b><em>0</em></div>
 */
