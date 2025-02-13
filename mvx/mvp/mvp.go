package main

import "fmt"

/*
MVP 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View不直接绑定Model，而通过Presenter获取数据。
- Presenter：作为中介者，接收用户输入并更新 Model 或 View，处理业务逻辑。
*/

// Model (数据模型)
type Model struct {
  name string
  num  int
}

func (m *Model) GetName() string {
  return m.name
}

func (m *Model) SetNum(num int) {
  m.num = num
}

func (m *Model) GetNum() int {
  return m.num
}

func (m *Model) IncrementNum(value int) {
  m.num += value
}

func (m *Model) SetName(name string) {
  m.name = name
}

// View (视图层)
type View struct {
  // View 只负责显示数据，并提供更新界面的接口
}

func (v *View) UpdateView(name string, num int) {
  fmt.Printf("<div><b>%s</b><em>%d</em></div>\n", name, num)
}

// Presenter (中介者)
type Presenter struct {
  model *Model
  view  *View
}

func (p *Presenter) OnButtonClick() {
  p.model.SetName("onButtonClick")
  p.model.IncrementNum(1)
  p.UpdateView()
}

func (p *Presenter) OnMouseOut() {
  p.model.SetName("onMouseOut")
  p.model.SetNum(0)
  p.UpdateView()
}

func (p *Presenter) UpdateView() {
  p.view.UpdateView(p.model.GetName(), p.model.GetNum())
}

// Test
func main() {
  model := &Model{}
  // view与model无关联
  view := &View{}
  presenter := &Presenter{model: model, view: view}

  fmt.Println("Test 1: Button Click")
  presenter.OnButtonClick()

  fmt.Println("Test 2: Mouse Out")
  presenter.OnMouseOut()
}

/*
jarry@MacBook-Pro mvp % go run mvp.go
Test 1: Button Click
<div><b>onButtonClick</b><em>1</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/
