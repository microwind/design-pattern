package src

// 定义一个实体类，用来过滤的对象
type Person struct {
  name   string
  gender string
  status string
}

func CreatePerson(name string, gender string, status string) *Person {
  return &Person{
    name:   name,
    gender: gender,
    status: status,
  }
}

func (p *Person) GetName() string {
  return p.name
}

// 是否被包含在对象slice中
func (p *Person) IsContained(persons []*Person) bool {
  for _, person := range persons {
    if p == person {
      return true
    }
  }
  return false
}

func (p *Person) GetGender() string {
  return p.gender
}

func (p *Person) GetStatus() string {
  return p.status
}

func (p *Person) ToString() string {
  return "Person : [ Name : " + p.GetName() + ", Gender : " +
    p.GetGender() + ", Marital Status : " + p.GetStatus() + " ]"
}
