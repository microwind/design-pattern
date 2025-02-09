// Model
class Model {
    constructor() {
        this.name = "MVC Basic";
        this.num = 1;
    }

    getName() {
        return this.name;
    }

    getNum() {
        return this.num;
    }

    setName(name) {
        this.name = name;
    }

    incrementNum(value) {
        this.num += value;
    }
}

// View
class View {
    display(name, num) {
        console.log(`<div><b>${name}</b><em>${num}</em></div>`);
    }
}

// Controller
class Controller {
    constructor(model, view) {
        this.model = model;
        this.view = view;
    }

    onButtonClick() {
        this.model.incrementNum(1);
        this.view.display(this.model.getName(), this.model.getNum());
    }

    onMouseOut() {
        this.model.setName("Click to add");
        this.view.display(this.model.getName(), this.model.getNum());
    }
}

// Test
function test() {
    const model = new Model();
    const view = new View();
    const controller = new Controller(model, view);

    console.log("Test 1: Button Click");
    controller.onButtonClick();  // simulate button click

    console.log("Test 2: Mouse Out");
    controller.onMouseOut();     // simulate mouse out
}

test();

/*
jarry@MacBook-Pro mvc % node mvc.js 
Test 1: Button Click
<div><b>MVC Basic</b><em>2</em></div>
Test 2: Mouse Out
<div><b>Click to add</b><em>2</em></div>
*/
