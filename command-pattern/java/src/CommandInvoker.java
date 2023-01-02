package src;

import java.util.*;

// 命令调用类，通过关联命令来实行命令的调用
public class CommandInvoker {

    private List<Command> commandList = new ArrayList<Command>();

    // 储存命令
    public void takeOrder(Command command) {
        System.out.println(this.getClass().getName() + "::takeOrder() " + command.getClass().getName());
        commandList.add(command);
    }

    // 统一执行
    public void executeOrders() {
        System.out.println(this.getClass().getName() + "::executeOrders() ");
        for (Command command : commandList) {
            command.execute();
        }
        commandList.clear();
    }
}
