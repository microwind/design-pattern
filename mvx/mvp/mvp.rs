/*
MVP 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View不直接绑定Model，而通过Presenter获取数据。
- Presenter：作为中介者，接收用户输入并更新 Model 或 View，处理业务逻辑。
*/
// Model (数据模型)
struct Model {
  name: String,
  num: i32,
}

impl Model {
  fn new() -> Model {
      Model {
          name: "MVP Basic".to_string(),
          num: 1,
      }
  }

  fn get_name(&self) -> &str {
      &self.name
  }

  fn set_name(&mut self, name: &str) {
      self.name = name.to_string();
  }

  fn get_num(&self) -> i32 {
      self.num
  }

  fn set_num(&mut self, num: i32) {
      self.num = num;
  }

  fn increment_num(&mut self, value: i32) {
      self.num += value;
  }
}

// View (视图层)
struct View;

impl View {
  // 现在是实例方法
  fn update_view(&self, name: &str, num: i32) {
      println!("<div><b>{}</b><em>{}</em></div>", name, num);
  }
}

// Presenter (中介者)
struct Presenter<'a> {
  model: &'a mut Model,
  view: &'a View,
}

impl<'a> Presenter<'a> {
  fn new(model: &'a mut Model, view: &'a View) -> Presenter<'a> {
      Presenter { model, view }
  }

  fn on_button_click(&mut self) {
      self.model.set_name("onButtonClick");
      self.model.increment_num(1);
      self.update_view();
  }

  fn on_mouse_out(&mut self) {
      self.model.set_name("onMouseOut");
      self.model.set_num(0);
      self.update_view();
  }

  fn update_view(&self) {
      // 调用实例方法
      self.view.update_view(self.model.get_name(), self.model.get_num());
  }
}

// Test (测试)
fn main() {
  let mut model = Model::new();
  // MVP下view与model解耦，render时传递数据，而不是model
  let view = View;
  let mut presenter = Presenter::new(&mut model, &view);

  println!("Test 1: Button Click");
  presenter.on_button_click();

  println!("Test 2: Mouse Out");
  presenter.on_mouse_out();
}

/*
jarry@MacBook-Pro mvp % rustc mvp.rs
jarry@MacBook-Pro mvp % ./mvp   
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/