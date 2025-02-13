// MVC 模式
// - Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
// - View：负责渲染用户界面，显示数据给用户。View 可与 Model 绑定。
// - Controller：作为用户输入的中介，接收用户的输入并更新 Model 或 View。

// Model (数据模型)
struct Model {
  name: String,
  num: i32,
}

impl Model {
  fn new() -> Self {
      Model {
          name: String::from("MVC Basic"),
          num: 1,
      }
  }

  fn get_name(&self) -> &str {
      &self.name
  }

  fn set_num(&mut self, num: i32) {
      self.num = num;
  }

  fn get_num(&self) -> i32 {
      self.num
  }

  fn increment_num(&mut self, value: i32) {
      self.num += value;
  }

  fn set_name(&mut self, name: String) {
      self.name = name;
  }
}

// View (视图层)
struct View;

impl View {
  fn new() -> Self {
      View
  }

  fn update_view(&self, model: &Model) {
      println!(
          "<div><b>{}</b><em>{}</em></div>",
          model.get_name(),
          model.get_num()
      );
  }
}

// Controller (控制器)
struct Controller {
  model: Model,
  view: View,
}

impl Controller {
  fn new(model: Model, view: View) -> Self {
      Controller { model, view }
  }

  fn on_button_click(&mut self) {
      self.model.set_name(String::from("onButtonClick"));
      self.model.increment_num(1);
      self.update_view();
  }

  fn on_mouse_out(&mut self) {
      self.model.set_name(String::from("onMouseOut"));
      self.model.set_num(0);
      self.update_view();
  }

  fn update_view(&self) {
      // view可以绑定model或在更新时传递model
      self.view.update_view(&self.model);
  }
}

// Test
fn main() {
  let model = Model::new();
  let view = View::new();
  let mut controller = Controller::new(model, view);

  println!("Test 1: Button Click");
  controller.on_button_click();

  println!("Test 2: Mouse Out");
  controller.on_mouse_out();
}
/*
jarry@MacBook-Pro mvc % rustc mvc.rs
jarry@MacBook-Pro mvc % ./mvc 
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/