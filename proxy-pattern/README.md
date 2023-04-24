# 【代理设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
代理模式（Proxy Pattern）是一种结构型设计模式，用一个类来代理另一个类或几个类的功能。

在代理模式中，我们创建具有现有对象的对象，以便向外界提供功能接口。

延迟初始化（虚拟代理）。如果你有一个偶尔使用的重量级服务对象，一直保持该对象运行会消耗系统资源时，可使用代理模式。

访问控制（保护代理）。如果你只希望特定客户端使用服务对象，这里的对象可以是操作系统中非常重要的部分，而客户端则是各种已启动的程序 （包括恶意程序）， 此时可使用代理模式。

# 作用
1. 为其他对象提供一种代理访问的方式。
2. 避免直接访问可能带来的问题，通过接口和代理来实现高扩展。

# 实现步骤
1. 定义一个基础接口，约定一些方法。
2. 建立原始类，实现接口方法。
3. 再建立代理类，也实现基础接口。代理类调用原始类来实现功能。

# UML
<img src="../docs/uml/proxy-pattern.png">


# Java代码

## 代理接口类
```java
// Image.java 定义一个接口供代理和实际调用来使用
public interface Image {
  void display();
}
```

## 功能代理类
```java
// ProxyImage.java 代理类也实现了基础接口
public class ProxyImage implements Image {

  private RealImage realImage;
  private String fileName;

  public ProxyImage(String fileName) {
    this.fileName = fileName;
  }

  @Override
  public void display() {
    System.out.println("ProxyImage::display() " + fileName);
    if (realImage == null) {
      realImage = new RealImage(fileName);
    }
    // 代理类调用真实类的方法
    realImage.display();
  }
}
```

## 真实功能类
```java
// RealImage.java 真实类也实现基础代理接口
public class RealImage implements Image {

  private String fileName;

  public RealImage(String fileName) {
    // 在初始化时执行内部逻辑
    this.fileName = fileName;
    loadFromDisk(fileName);
  }

  @Override
  public void display() {
    System.out.println("RealImage::display() " + fileName);
  }

  // 这个方法只是内部使用
  private void loadFromDisk(String fileName) {
    System.out.println("RealImage::loadFromDisk()  " + fileName);
  }
}
```

## 测试调用
```java
  /**
   * 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类
   * 这样真实类和调用方之间有一个代理屏障，保证了安全
   * 同时真实的类如果初始化过，就不再初始化，提升了性能
   */

    // 声明代理类来执行真实类的能力
    Image image = new ProxyImage("001.jpg");

    // 代理类执行真实类的能力
    image.display();

    // 再调用一次，不会重复实例化
    image.display();
```

# Go代码

## 代理接口类
```go
// Image.go 定义一个接口供代理和实际调用来使用
type Image interface {
  Init(fileName string)
  Display()
}

```

## 功能代理类
```go
// ProxyImage.go 代理类也实现了基础接口
type ProxyImage struct {
  fileName string
  // 直接聚合真实类
  // realImage RealImage
  // 聚合接口
  realImage Image
}

// 设置文件名称
func (p *ProxyImage) SetFileName(fileName string) {
  p.fileName = fileName
}

func (p *ProxyImage) Display() {
  fmt.Println("ProxyImage::Display() " + p.fileName)
  if p.realImage == nil {
    p.realImage = &RealImage{}
    p.realImage.Init(p.fileName)
  }
  // 代理类调用真实类的方法
  p.realImage.Display()
}

```

## 真实功能类
```go
// RealImage.go 真实类也实现基础代理接口
type RealImage struct {
  fileName string
}

// 在初始化时执行内部逻辑
func (r *RealImage) Init(fileName string) {
  r.fileName = fileName
  r.LoadFromDisk(fileName)
}

func (r *RealImage) Display() {
  fmt.Println("RealImage::Display() " + r.fileName)
}

// 这个方法只是内部使用
func (r *RealImage) LoadFromDisk(fileName string) {
  fmt.Println("RealImage::LoadFromDisk()  " + fileName)
}
```

## 测试调用
```go
func main() {
  fmt.Println("test start:")
  /**
   * 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类
   * 这样真实类和调用方之间有一个代理屏障，保证了安全
   * 同时真实的类如果初始化过，就不再初始化，提升了性能
   */

  // 声明代理类来执行真实类的能力
  var image = &src.ProxyImage{}
  image.SetFileName("001.jpg")

  // 代理类执行真实类的能力
  image.Display()

  // 再调用一次，真实类不会重复实例化
  image.Display()
}
```

# C代码简版
```c 
// simple_proxy.c
#include <stdio.h>

// 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类

// 定义接口
typedef struct Interface
{
    void (*method)(struct Interface *interface);
} Interface;

// 实现接口的具体类
typedef struct Concrete
{
    void (*method)(struct Concrete *interface);
} Concrete;

void real_method(struct Concrete *interface)
{
    printf("调用真实方法 real_method.\n");
}

// 代理类，继承接口，聚合具体类实例
typedef struct Proxy
{
    struct Interface *real_subject;
} Proxy;

// 代理类方法实现，通过聚合的具体类实例来调用具体类的方法
void proxy_method(struct Interface *interface)
{
    struct Proxy *p = (struct Proxy *)interface;
    p->real_subject->method((struct Interface *)p);
}

int main()
{
    // 创建具体类实例
    struct Concrete real_subject = {
        .method = &real_method,
    };

    // 创建代理类实例并聚合具体类实例
    struct Proxy proxy_instance = {
        .real_subject = (struct Interface *)&real_subject,
    };

    // 将代理类的方法指针指向代理类的方法实现
    struct Interface proxy_interface = {
        .method = &proxy_method,
    };

    // 通过代理类的接口调用具体类方法
    proxy_interface.method((struct Interface *)&proxy_instance);

    return 0;
}

```
## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)