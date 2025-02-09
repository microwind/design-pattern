package main

import "fmt"

// Model: 负责数据管理
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

func (m *Model) GetNum() int {
    return m.num
}

func (m *Model) SetName(name string) {
    m.name = name
}

func (m *Model) IncrementNum(value int) {
    m.num += value
}

// View: 负责显示数据
type View struct{}

func (v *View) Display(name string, num int) {
    fmt.Printf("<div><b>%s</b><em>%d</em></div>\n", name, num)
}

// Controller: 负责处理用户输入和业务逻辑
type Controller struct {
    model *Model
    view  *View
}

func NewController(model *Model, view *View) *Controller {
    return &Controller{model: model, view: view}
}

func (c *Controller) OnButtonClick() {
    c.model.IncrementNum(1)
    c.view.Display(c.model.GetName(), c.model.GetNum())
}

func (c *Controller) OnMouseOut() {
    c.model.SetName("Click to add")
    c.view.Display(c.model.GetName(), c.model.GetNum())
}

// Test
func main() {
    model := NewModel()
    view := &View{}
    controller := NewController(model, view)

    fmt.Println("Test 1: Button Click")
    controller.OnButtonClick() // simulate button click

    fmt.Println("Test 2: Mouse Out")
    controller.OnMouseOut() // simulate mouse out
}

/*
jarry@MacBook-Pro mvc % go run mvc.go
Test 1: Button Click
<div><b>MVC Basic</b><em>2</em></div>
Test 2: Mouse Out
<div><b>Click to add</b><em>2</em></div>
*/
