import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.util.HashMap;
import java.util.Map;

// 数据模型（Model）
class ObservableModel {
    private final PropertyChangeSupport support = new PropertyChangeSupport(this);
    private final Map<String, Object> properties = new HashMap<>();

    public ObservableModel() {
    }

    public void setProperty(String key, Object value) {
        Object oldValue = properties.get(key);
        properties.put(key, value);
        support.firePropertyChange(key, oldValue, value); // 通知属性变化
    }

    public Object getProperty(String key) {
        return properties.get(key);
    }

    public void addPropertyChangeListener(String propertyName, PropertyChangeListener listener) {
        support.addPropertyChangeListener(propertyName, listener);
    }
}

// 视图（View）
class View {
    private final JFrame frame;
    private final Map<String, JComponent> components = new HashMap<>();
    private final Map<String, ActionListener> actions = new HashMap<>();

    public View(String title, int width, int height) {
        frame = new JFrame(title);
        frame.setSize(width, height);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());
    }

    public void addLabel(String key, String text) {
        JLabel label = new JLabel(text);
        components.put(key, label);
        frame.add(label);
    }

    public void addButton(String key, String text, ActionListener action) {
        JButton button = new JButton(text);
        components.put(key, button);
        actions.put(key, action);
        button.addActionListener(action);
        frame.add(button);
    }

    public void setComponentText(String key, String text) {
        if (components.containsKey(key)) {
            ((JLabel) components.get(key)).setText(text);
        }
    }

    public void setButtonActionListener(String key, ActionListener action) {
        if (components.containsKey(key) && components.get(key) instanceof JButton) {
            ((JButton) components.get(key)).addActionListener(action);
        }
    }

    public void show() {
        frame.setVisible(true);
    }
}

// 视图模型（ViewModel）
class ViewModel {
    private final ObservableModel model;
    private final View view;

    public ViewModel(ObservableModel model, View view) {
        this.model = model;
        this.view = view;
    }

    public void bindPropertyToView(String propertyName, String componentKey, String labelPrefix) {
        model.addPropertyChangeListener(propertyName, evt -> {
            // 只更新数字部分，保持标签不变
            String newText = labelPrefix + " " + model.getProperty(propertyName);
            view.setComponentText(componentKey, newText);
        });
    }

    public void bindActionToButton(String buttonKey, Runnable action) {
        view.setButtonActionListener(buttonKey, e -> action.run());
    }

    public void setProperty(String key, Object value) {
        model.setProperty(key, value);
    }

    public Object getProperty(String key) {
        return model.getProperty(key);
    }
}

// TinyMVVM 框架
class TinyMVVM {
    private final ObservableModel model;
    private final View view;
    private final ViewModel viewModel;

    public TinyMVVM(String title, int width, int height, Map<String, Object> initialData, Map<String, String> labels,
            Map<String, String> buttons) {
        model = new ObservableModel();
        view = new View(title, width, height);
        viewModel = new ViewModel(model, view);

        // 初始化数据模型
        initialData.forEach(model::setProperty);

        // 添加标签
        labels.forEach(view::addLabel);

        // 添加按钮
        buttons.forEach((key, text) -> view.addButton(key, text, null));
    }

    public void bindPropertyToView(String propertyName, String componentKey, String labelPrefix) {
        viewModel.bindPropertyToView(propertyName, componentKey, labelPrefix);
    }

    public void bindActionToButton(String buttonKey, Runnable action) {
        viewModel.bindActionToButton(buttonKey, action);
    }

    public void setProperty(String key, Object value) {
        viewModel.setProperty(key, value);
    }

    public Object getProperty(String key) {
        return viewModel.getProperty(key);
    }

    public void show() {
        view.show();
    }
}

// 使用 TinyMVVM 框架的示例
public class TinyMVVMExample {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            // 初始化数据
            Map<String, Object> initialData = new HashMap<>();
            initialData.put("num", 1);

            // 初始化标签
            Map<String, String> labels = new HashMap<>();
            labels.put("numberLabel", "Number: 1");

            // 初始化按钮
            Map<String, String> buttons = new HashMap<>();
            buttons.put("incrementButton", "Increment");

            // 创建 TinyMVVM 实例
            TinyMVVM tinyMVVM = new TinyMVVM("Tiny MVVM Framework", 300, 200, initialData, labels, buttons);

            // 绑定属性到视图，传入标签前缀
            tinyMVVM.bindPropertyToView("num", "numberLabel", "Number added:");

            // 绑定按钮行为
            tinyMVVM.bindActionToButton("incrementButton", () -> {
                int currentNum = (int) tinyMVVM.getProperty("num");
                tinyMVVM.setProperty("num", currentNum + 1);
            });

            // 显示视图
            tinyMVVM.show();
        });
    }
}
