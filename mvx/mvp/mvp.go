package main

import "fmt"

// View: 负责显示数据并触发事件
type View struct {
  presenter *Presenter
}

func (v *View) render(name string, num int) {
  fmt.Printf("<b>%s</b><em>%d</em>\n", name, num)
}

func (v *View) setClickListener() {
  // 模拟点击事件
  v.presenter.add(1)
}

func (v *View) setMouseOutListener() {
  // 模拟鼠标移出事件
  v.presenter.change("Click to add")
}

// Model: 负责数据处理
type Model struct {
  name string
  num  int
}

func (m *Model) getName() string {
  return m.name
}

func (m *Model) getNum() int {
  return m.num
}

func (m *Model) update(value int) {
  m.num += value
}

func (m *Model) change(name string) {
  m.name = name
}

// Presenter: 负责协调 View 和 Model
type Presenter struct {
  view  *View
  model *Model
}

func (p *Presenter) init() {
  p.view.setClickListener()
  p.view.setMouseOutListener()
  p.render()
}

func (p *Presenter) render() {
  p.view.render(p.model.getName(), p.model.getNum())
}

func (p *Presenter) add(value int) {
  p.model.update(value)
  p.render()
}

func (p *Presenter) change(name string) {
  p.model.change(name)
  p.render()
}

func main() {
  model := &Model{name: "MVP", num: 1}
  view := &View{presenter: nil}
  presenter := &Presenter{view: view, model: model}
  view.presenter = presenter
  presenter.init()
}
