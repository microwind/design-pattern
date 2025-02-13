package main

import "fmt"

/*
MVC 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View可与Model绑定。
- Controller：作为用户输入的中介，接收用户的输入并更新 Model 或 View。
*/

// Model (数据模型)
type Model struct {
    name string
    num  int
}

func NewModel() *Model {
    return &Model{name: "MVC Basic", num: 1}
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
    model *Model
}

func NewView(model *Model) *View {
    return &View{model: model}
}

func (v *View) UpdateView() {
    fmt.Printf("<div><b>%s</b><em>%d</em></div>\n", v.model.GetName(), v.model.GetNum())
}

// Controller (控制器)
type Controller struct {
    model *Model
    view  *View
}

func NewController(model *Model, view *View) *Controller {
    return &Controller{model: model, view: view}
}

func (c *Controller) OnButtonClick() {
    c.model.SetName("onButtonClick")
    c.model.IncrementNum(1)
    c.updateView()
}

func (c *Controller) OnMouseOut() {
    c.model.SetName("onMouseOut")
    c.model.SetNum(0)
    c.updateView()
}

func (c *Controller) updateView() {
    c.view.UpdateView()
}

// Test
func main() {
    model := NewModel()
    // view可以绑定model
    view := NewView(model)
    controller := NewController(model, view)

    fmt.Println("Test 1: Button Click")
    controller.OnButtonClick()

    fmt.Println("Test 2: Mouse Out")
    controller.OnMouseOut()
}

/*
jarry@MacBook-Pro mvc % go run mvc.go
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/
