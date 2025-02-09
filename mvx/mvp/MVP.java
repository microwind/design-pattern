// View: 负责显示数据并触发事件
class View {
  private Presenter presenter;

  public View(Presenter presenter) {
      this.presenter = presenter;
  }

  public void render(String name, int num) {
      System.out.println("<b>" + name + "</b><em>" + num + "</em>");
  }

  public void setClickListener() {
      // 模拟点击事件
      this.presenter.add(1);
  }

  public void setMouseOutListener() {
      // 模拟鼠标移出事件
      this.presenter.change("Click to add");
  }
}

// Model: 负责数据处理
class Model {
  private String name = "MVP";
  private int num = 1;

  public String getName() {
      return name;
  }

  public int getNum() {
      return num;
  }

  public void update(int value) {
      num += value;
  }

  public void change(String name) {
      this.name = name;
  }
}

// Presenter: 负责协调 View 和 Model
class Presenter {
  private View view;
  private Model model;

  public Presenter(View view, Model model) {
      this.view = view;
      this.model = model;
  }

  public void init() {
      this.view.setClickListener();
      this.view.setMouseOutListener();
      render();
  }

  public void render() {
      this.view.render(model.getName(), model.getNum());
  }

  public void add(int value) {
      model.update(value);
      render();
  }

  public void change(String name) {
      model.change(name);
      render();
  }
}

public class MVP {
  public static void main(String[] args) {
      Model model = new Model();
      View view = new View(new Presenter(view, model));
      Presenter presenter = new Presenter(view, model);
      presenter.init();
  }
}
