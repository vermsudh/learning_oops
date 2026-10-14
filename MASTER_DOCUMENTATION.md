# 🧸 OOPS Master Guide (C++) — Explained Like You're 5

> Every concept here comes from the code in this repo. Each section has:
> 1. 🧒 **The kid version**: a toy or real-life story.
> 2. 💻 **The code**: from this repo (with the file path) or a tiny extra example.
> 3. 🧠 **How to remember it**: a one-line hook.
> 4. ⚠️ **Gotchas**: places where the repo's code teaches a lesson, or has a bug worth knowing about.

**Reading order (same as the repo):**

1. Classes & Objects
2. Access Modifiers (public / private)
3. Encapsulation
4. Constructors (default, parameterized, `this`, copy)
5. Shallow vs Deep Copy
6. Destructors
7. Inheritance (single, multi-level, multiple, hierarchical)
8. Polymorphism (compile-time, run-time)
9. Abstraction
10. `static` keyword (last, as requested)

---

## 0. What is OOPS?

🧒 **Kid version:** You have a big box of LEGO. Instead of dumping all the bricks on the floor, you build *things*: a car, a house, a robot. Each thing knows what it looks like and what it can do.

**OOPS = Object-Oriented Programming System.** We organise code around *things* (objects), not around a long list of instructions.

The 4 pillars, in kid language:

| Pillar | One-line kid explanation | Real-life picture |
|---|---|---|
| **Encapsulation** | Keep your private stuff inside a box with a lock | A piggy bank: you drop coins in through the slot, you can't grab them directly |
| **Abstraction** | Show only what's needed, hide how it works | You press the TV remote button. You don't need to know the circuits |
| **Inheritance** | Kids get things from their parents | You have your mom's eyes, but you also have your own talents |
| **Polymorphism** | One name, many behaviours | The word "speak": a dog barks, a cat meows, a duck quacks |

🧠 **Remember:** **E-A-I-P** → *"Every Awesome Idea Pops"*.

---

## 1. Classes & Objects

🧒 **Kid version:**
A **class** is a **cookie cutter**. An **object** is a **cookie**.
The cutter isn't edible. It only describes the shape. You press it into dough and get real cookies, and every cookie can have different sprinkles.

- **Class** = blueprint / recipe / cookie cutter (no real thing yet)
- **Object** = the real thing built from the blueprint (takes up memory)

A class has two kinds of members:

| Part | Kid word | Programmer word | Example |
|---|---|---|---|
| What it **has** | "My name is…" | **Properties / attributes / data members** | `name`, `dept`, `subject` |
| What it **can do** | "I can run!" | **Methods / member functions** | `changeDept()`, `getSalary()` |

💻 **From the repo** (`classes&objects/oops.cpp`):

```cpp
class Teacher {
private:
    double salary;          // hidden property

public:
    // properties or attributes
    string name;
    string dept;
    string subject;

    // methods
    void changeDept(string newDept) { dept = newDept; }
    void setSalary(double s)        { salary = s; }
    double getSalary()              { return salary; }
};

int main() {
    Teacher t1;             // make 3 cookies from 1 cutter
    Teacher t2;
    Teacher t3;

    t1.name    = "Sudhanshu";   // the dot (.) means "reach inside this object"
    t1.subject = "c++";
    t1.dept    = "IT";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary();
}
```

What happens in memory (picture it):

```
 class Teacher  (the cutter. Nothing is stored here)
      │
      ├── t1 → { name:"Sudhanshu", dept:"IT", subject:"c++", salary:25000 }
      ├── t2 → { name:"",          dept:"",   subject:"",    salary:??? }
      └── t3 → { name:"",          dept:"",   subject:"",    salary:??? }
```

Each object has **its own copy** of the properties. Changing `t1.name` does not touch `t2.name`.

🧠 **Remember:** *Class = idea. Object = the real thing. One cutter, many cookies.*

⚠️ **Gotcha:** `t2.getSalary()` before you set it gives a garbage number, because `double salary` is never given a starting value. This is one of the reasons **constructors** exist (Section 4).

---

## 2. Access Modifiers: `public` and `private`

🧒 **Kid version:** Your house has a **front yard** and a **bedroom**.
- **Front yard = `public`**: any visitor can walk in.
- **Bedroom = `private`**: only you (and your family) can enter.

| Keyword | Who can touch it? |
|---|---|
| `public` | Anyone, from anywhere (`main()`, other classes) |
| `private` | **Only the class's own methods** |
| `protected` | The class itself **and its children** (see Inheritance) |

💻 **From the repo** (`classes&objects/oops.cpp`):

```cpp
class Teacher {
private:
    double salary;     // 🔒 bedroom
public:
    string name;       // 🌳 front yard
};

Teacher t1;
t1.name = "Sudhanshu";   // ✅ allowed (public)
t1.salary = 25000;       // ❌ ERROR: salary is private
t1.setSalary(25000);     // ✅ allowed, we ask politely through a public method
```

🧠 **Remember:** *Private = "knock first." Public = "come on in."* In a C++ `class`, everything is **private by default**.

---

## 3. Encapsulation

🧒 **Kid version:** A **piggy bank**. 🐷
You put coins in through the slot (a *public method*). You can't reach in and grab coins whenever you like (the coins are *private*). The bank protects what's inside.

**Encapsulation = wrapping data + the functions that use it into one unit (class), and hiding the data so only safe doors can reach it.**

Two ideas hide in this one word:
1. **Bundling:** data and methods live together in one class.
2. **Data hiding:** sensitive data is `private`, and you get at it through `public` methods (getters and setters).

💻 **From the repo** (`encapsulation/code.cpp`):

```cpp
class Account {
private:
    double balance;
    string password;      // data hiding in private
public:
    string accountId;
    string username;
};
```

Nobody outside can read `password` or change `balance`. Now let's add the "slots" so the repo's example comes alive (extra example, not in the repo):

```cpp
class Account {
private:
    double balance = 0;
    string password;
public:
    string accountId;
    string username;

    void deposit(double amount) {          // the coin slot
        if (amount > 0) balance += amount; // ✅ rule: no negative deposits!
    }
    double getBalance() { return balance; } // a window to LOOK, not to touch
};

Account a;
a.deposit(500);
a.balance = 1000000;   // ❌ compiler stops the cheater
```

**The same idea from the repo's `Teacher`:** `setSalary()` is the **setter** (write door) and `getSalary()` is the **getter** (read door).

| Without encapsulation | With encapsulation |
|---|---|
| Anyone can set `balance = -9999` | `deposit()` checks the rules first |
| Bugs everywhere | Bugs can only come from one place, the class |

🧠 **Remember:** *Encapsulation = capsule 💊. The medicine is sealed inside.*

---

## 4. Constructors

🧒 **Kid version:** When a baby is born, it gets a **name and a birth certificate right away**. Nobody has to remember to do it later.
A **constructor** is the code that runs **automatically the moment an object is born**. It gives the object its starting values.

**Rules of a constructor:**
- Has the **same name as the class**.
- Has **no return type** (not even `void`).
- Runs **automatically** when you create an object.
- If you write none, the compiler gives you an empty default one.

### 4.1 Default constructor (no parameters)

💻 `constructor/basics/code.cpp`

```cpp
Teacher() {
    cout << "Hi, I am a constructor \n";
    dept = "Computer Science";    // every new Teacher starts in CS
}

Teacher t;    // prints "Hi, I am a constructor", and t.dept is already "Computer Science"
```

### 4.2 Parameterized constructor (you decide the starting values)

🧒 *Like telling the hospital: "Please name my baby Tony."*

```cpp
Teacher(string n, string d, string s, double sal) {
    name = n;
    dept = d;
    subject = s;
    salary = sal;
}

Teacher t1("sudhanshu", "computer science", "C++", 40000);
t1.getInfo();   // name : sudhanshu / subject : C++
```

### 4.3 Constructor Overloading

You can have **many constructors in one class** as long as their parameters differ. The compiler picks the right one from what you pass in (this is a kind of *compile-time polymorphism*, see Section 8).

💻 `polymorphism/runtime_overloading/code.cpp`

```cpp
class Student {
public:
    string name;

    Student() {                       // no parameters
        cout << "non-parameterized constructor \n";
    }
    Student(string name) {            // one string parameter
        this->name = name;
        cout << "parameterized constructor\n";
    }
};

Student s2("Tony Stark");   // prints: parameterized constructor
Student s1;                 // prints: non-parameterized constructor
```

> ⚠️ **Gotcha about the folder name:** this folder is called `runtime_overloading`, but what it shows is *constructor overloading*, and that's decided at **compile time**, not run time. True run-time polymorphism uses `virtual` functions. See Section 8.2.

### 4.4 The `this` pointer

🧒 **Kid version:** Imagine 3 kids in a classroom, each wearing a name tag. When any kid says **"my pencil"**, the word **"my"** means *"the kid who is talking right now."*
**`this` = "my"**. It's a secret pointer every object carries that points to **itself**.

**Why do we need it?** When the parameter has the **same name** as the property, C++ gets confused about which is which:

💻 `constructor/this/code.cpp`

```cpp
Teacher(string name, string dept, string subject, double sal) {
    this->name    = name;      // left = MY property, right = the parameter
    this->dept    = dept;
    this->subject = subject;
    this->salary  = salary;    // ⚠️ see the bug below
}
```

- `this->name` = *the property that belongs to the object being built*
- `name` (alone) = *the nearest thing with that name, the parameter*

`this->name` can also be written `(*this).name`. The arrow `->` means "go through the pointer, then reach inside."

> 🐞 **Bug spotted in the repo:** the parameter is called `sal`, not `salary`. So `this->salary = salary;` assigns the member **to itself**. (There's no parameter named `salary`, so the right-hand side is the member too.) The salary is never set and stays garbage.
> ✅ **Fix:** `this->salary = sal;` (or rename the parameter to `salary`).
> The same line appears in `constructor/copy_construct/code.cpp`.

🧠 **Remember:** *`this` = "me, myself."*

### 4.5 Copy Constructor

🧒 **Kid version:** A **photocopier**. 🖨️ You put a drawing in, and a second identical drawing comes out. Both papers look alike, but they are **two separate sheets**.

A **copy constructor** builds a **new object as a copy of an existing one**.

💻 `constructor/copy_construct/code.cpp`

```cpp
Teacher(Teacher &originalObject) {            // pass by REFERENCE
    cout << "This is a custom made copy constructor" << endl;

    this->name    = originalObject.name;
    this->dept    = originalObject.dept;
    this->subject = originalObject.subject;
    this->salary  = originalObject.salary;
}

Teacher t1("sudhanshu", "computer science", "C++", 40000);
Teacher t2(t1);      // 👈 calls the copy constructor
t2.getInfo();
```

**Why `&` (reference)?** To copy `t1` we'd have to pass `t1` into the constructor. If we passed it **by value**, C++ would need to make a copy to pass it, which needs the copy constructor, which needs a copy... an **infinite loop**! 🔁 Passing by reference avoids the copy.

> 💡 **If you don't write one,** C++ writes a copy constructor for you. It copies every member value one by one. That's called a **shallow copy**, and it's fine until you have pointers. Next section.

🧠 **Remember:** *Copy constructor = photocopier. `Teacher t2(t1);` = "t2, be a copy of t1."*

---

## 5. Shallow Copy vs Deep Copy

🧒 **Kid version:** Your friend gives you a **treasure map** 🗺️ that says *"treasure is buried under the big tree."*

- **Shallow copy:** you **photocopy the map**. Now two maps exist, but **both point to the same treasure**. If your friend digs it up, yours is empty too! 😱
- **Deep copy:** you **go dig your own hole and bury your own treasure**, then draw a new map to it. Now each of you has **your own treasure**. 💰💰

In code, the **map = a pointer** and the **treasure = the data it points to** (made with `new`).

💻 `constructor/copy_construct/deep_copyShallow_copy/code.cpp`

```cpp
class Student {
public:
    string name;
    double *cgpaPtr;                 // a pointer → "the map"

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;        // dig a hole on the heap → "the treasure"
        *cgpaPtr = cgpa;
    }

    // 🅰️ SHALLOW copy: copies the MAP only
    Student(Student &obj) {
        this->name    = obj.name;
        this->cgpaPtr = obj.cgpaPtr;     // both now point to the SAME double
    }

    // 🅱️ DEEP copy: builds NEW treasure
    Student(Student &obj) {
        this->name = obj.name;
        cgpaPtr  = new double;           // a brand-new hole
        *cgpaPtr = *obj.cgpaPtr;         // copy the VALUE, not the address
    }
};
```

Pictures:

```
SHALLOW                                DEEP
s1.cgpaPtr ──┐                         s1.cgpaPtr ──► [ 8.8 ]
             ├──► [ 8.8 ]              s2.cgpaPtr ──► [ 8.8 ]   (separate box)
s2.cgpaPtr ──┘
```

The experiment from `main()`:

```cpp
Student s1("Sudhanshu Verma", 8.8);
Student s2(s1);

*(s2.cgpaPtr) = 9.2;   // change ONLY s2's cgpa…
s1.getInfo();
//   shallow → s1 ALSO shows 9.2 😱   (shared treasure)
//   deep    → s1 still shows 8.8 ✅  (own treasure)

s2.name = "neha";      // names are plain values, so they were always independent
```

| | Shallow | Deep |
|---|---|---|
| Copies | the pointer's address | the pointed-to data |
| After copy | objects **share** memory | objects have **own** memory |
| Danger | change one, change both; double `delete` crash | none (slightly slower) |
| Default in C++? | ✅ yes | ❌ you must write it |

> ⚠️ **The repo file doesn't compile as-is:** it contains **both** versions with the identical signature `Student(Student &obj)`. C++ says *"constructor cannot be redeclared."* That's by design for teaching: it puts the two versions side by side. To run an experiment, **comment out one**.
> Also, `getInfo()` prints the CGPA with the label `age`. Harmless, but a label typo.

🧠 **Remember:** *Shallow = share the map. Deep = build your own treasure.* **If your class has a pointer, write a deep copy.**

---

## 6. Destructors

🧒 **Kid version:** After a birthday party, a good kid **cleans up**: throws away the plates, pops the balloons, and puts the toys back. 🎈
A **destructor** is the cleanup code that runs **automatically when an object dies**.

**Rules:**
- Name = `~` + class name (e.g. `~Student()`).
- **No parameters, no return type**, and only **one** per class.
- Runs **automatically** when the object goes out of scope (or is `delete`d).

**Why do we need it?** If a constructor did `new` (borrowed memory from the heap), someone must `delete` it (give it back). Otherwise: **memory leak**, like borrowing toys and never returning them until the house overflows. 🧸🧸🧸🧸

💻 `destructor/code.cpp`

```cpp
class Student {
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa) {     // BORN: borrow memory
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    ~Student() {                            // DIES: return memory
        cout << "Hi, I am deleteing everything!";
        delete cgpaPtr;
    }
};

int main() {
    Student s1("rahul kumar", 8.9);
    s1.getInfo();
    return 0;       // 👈 s1 dies here → destructor runs automatically
}
```

**Order of life:** `Constructor → (object lives, you use it) → Destructor`.

🧠 **Remember:** *Constructor = "Hello!" 👋 Destructor = "Goodbye, and I cleaned my room."*

**The "Rule of Three" (bonus):** if your class needs one of these three, it almost certainly needs all three:
1. **Destructor**, 2. **Copy constructor**, 3. **Copy assignment operator**.
This is why Section 5 (deep copy) and Section 6 (destructor) belong together: with a shallow copy, **both** objects would `delete` the *same* pointer when they die, which crashes the program (double free).

---

## 7. Inheritance

🧒 **Kid version:** You look like your parents: you got **Dad's nose** and **Mom's smile** without doing anything. Then you add **your own** skills, like riding a bike.
**Inheritance = a child class automatically gets the properties and methods of a parent class, then adds its own.**

**Why?** To **avoid writing the same code again and again** (the **DRY** rule: Don't Repeat Yourself).

Vocabulary:

| Word | Also called |
|---|---|
| Parent | Base class / Super class |
| Child | Derived class / Sub class |

Syntax: `class Child : public Parent { ... };`
Read it as: *"Child **is a** Parent."* (A Student **is a** Person.)

### 7.1 Single & Multi-level Inheritance

💻 `Inheritance/public/code.cpp`

```
Person            (name, age)
   ▲
Student           (+ rollNo, getInfo())
   ▲
GradStudent       (+ researchArea)
```

```cpp
class Person {
public:
    string name;
    int age;
    Person()  { cout << "THis is a Parent constructor \n"; }
    ~Person() { cout << "THis is a Parent destructor \n"; }
};

class Student : public Person {     // Student inherits from Person
public:
    int rollNo;                     // + name, age come free
    Student()  { cout << "THis is a child constructor \n"; }
    ~Student() { cout << "THis is a Child destructor \n"; }

    void getInfo() {
        cout << "name : "   << name   << endl;   // 👈 `name` was never declared here
        cout << "Age : "    << age    << endl;   //    it came from Person!
        cout << "RollNo : " << rollNo << endl;
    }
};

class GradStudent : public Student {   // a child of a child
public:
    string researchArea;
};
```

- **Single inheritance:** one parent → one child (`Person → Student`).
- **Multi-level inheritance:** a chain (`Person → Student → GradStudent`). `GradStudent` gets `name`, `age`, `rollNo` **and** `getInfo()`.

**Constructor/destructor order, "build the foundation first, then the house":**

```
Creating a Student:
  1. Person constructor   (parent first)
  2. Student constructor  (then child)
Object dies:
  3. Student destructor   (child first)
  4. Person destructor    (then parent)
```

🧒 *Build the ground floor before the 2nd floor. Tear down the 2nd floor before the ground floor.*

**What does `public` in `: public Person` mean?** It says *"keep the parent's public stuff public in the child."* (C++ also has `protected` and `private` inheritance, which are rarer.)

| Member in Parent | `public` inheritance → in Child |
|---|---|
| `public` | stays `public` |
| `protected` | stays `protected` |
| `private` | **inherited but not accessible** |

### 7.2 Multiple Inheritance

🧒 **Kid version:** A child who got **Mom's** curly hair **and Dad's** height: **two parents at once.**

💻 `Inheritance/multiple_inheritance/code.cpp`

```
 Teacher (name, rollNo)     Student (subject, salary)
        ▲                          ▲
        └────────────┬─────────────┘
                     TA  (+ researchArea)
```

```cpp
class Teacher { public: string name; int rollNo; };
class Student { public: string subject; double salary; };

class TA : public Student, public Teacher {   // two parents, comma separated
public:
    string researchArea;
};

TA t1;
t1.name = "Tony Stark";       // from Teacher
t1.rollNo = 23;               // from Teacher
t1.researchArea = "Physics";  // its own
```

A **Teaching Assistant** is a student *and* a teacher, so it makes sense to inherit from both.

⚠️ **The "Diamond / ambiguity" danger:** if **both** parents had a member with the **same name**, e.g. both had `name`, then `t1.name` is ambiguous: *"Whose name? Mom's or Dad's?"* The compiler refuses. You'd resolve it with `t1.Teacher::name`.

### 7.3 Hierarchical Inheritance

🧒 **Kid version:** **One parent, many kids.** One mom, three children: each gets her traits but grows up differently.

```
          Person (name, age)
         /        |        \
   Student    Teacher     Staff
```

💻 **What the repo has** (`Inheritance/hierarchial_inheritance/code.cpp`): the file defines `Person`, `Teacher`, `Student` and `TA`, but `TA` inherits from `Student` and `Teacher` directly. `Person` isn't used yet, so as written it's really *multiple* inheritance again. The commit message says hierarchical, so here's what the **true** hierarchical version looks like (extra example):

```cpp
class Person {
public:
    string name;
    int age;
};

class Student : public Person { public: int rollNo; };       // child 1
class Teacher : public Person { public: string subject; };   // child 2

Student s;  s.name = "Tony";   // from Person
Teacher t;  t.name = "Pepper"; // from Person, both share the same blueprint
```

> 🔎 Also in the repo version: `Student` has `rollno` (lowercase) while `Teacher` has `rollNo` (capital N). C++ is **case-sensitive**, so they're *different* names, and that accidentally avoids the ambiguity problem above.

### 7.4 Summary of the 5 types

| Type | Shape | Kid picture |
|---|---|---|
| **Single** | `A → B` | One parent, one child |
| **Multi-level** | `A → B → C` | Grandparent → parent → child |
| **Multiple** | `A, B → C` | Child with two parents |
| **Hierarchical** | `A → B, A → C` | One parent, many children |
| **Hybrid** | mix of the above | A big messy family tree |

🧠 **Remember:** *Inheritance = "is-a".* A Student **is a** Person. A Dog **is an** Animal. If "is-a" sounds silly (a Car **is a** Wheel?), don't inherit.

---

## 8. Polymorphism

🧒 **Kid version:** *Poly* = many, *morph* = forms. **One word, many behaviours.**
Say **"make a sound!"** to a dog → "Woof!" To a cat → "Meow!" To a cow → "Moo!" Same command, different results.

Two kinds:

| | When is the choice made? | How |
|---|---|---|
| **Compile-time** (static) | While the program is being *built* | Function / constructor **overloading** |
| **Run-time** (dynamic) | While the program is *running* | **Overriding** with `virtual` functions |

### 8.1 Compile-time Polymorphism (Overloading)

🧒 **Kid version:** A **vending machine with one slot named "insert."** Insert a coin → it gives candy. Insert a card → it gives a receipt. It decides **by looking at what you put in**, before anything is dispensed.

**Same function name, different parameters.** The compiler looks at the arguments and picks the right version while compiling.

💻 `polymorphism/compile_time_overloading/code.cpp`

```cpp
class Print {
public:
    void show(int x)     { cout << "int : "       << x  << endl; }
    void show(char ch)   { cout << "character : " << ch << endl; }
};

Print p1;
p1.show(1);       // → "int : 1"            (compiler sees an int)
p1.show('A');     // → "character : A"      (compiler sees a char)
```

The earlier **constructor overloading** (Section 4.3) is the same trick applied to constructors.

**What counts as "different parameters"?** Different **number** or different **types** (or order). A different **return type alone** does *not* count.

### 8.2 Run-time Polymorphism (Overriding)

🧒 **Kid version:** A **mystery toy box**. You reach in without looking and say "make your sound!" You only learn *which* toy it was **when it actually makes the sound**.

Here a **child redefines** a method it got from its parent, and the **actual object type** (decided while running) picks which version runs. The parent's method must be marked **`virtual`**.

*(Extra example, since the repo's `runtime_overloading` folder shows constructor overloading instead:)*

```cpp
class Animal {
public:
    virtual void speak() { cout << "Some sound\n"; }   // virtual = "children may override me"
    virtual ~Animal() {}                               // good habit: virtual destructor
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Meow!\n"; }
};

int main() {
    Animal *a;          // an Animal "remote control"…
    Dog d;  Cat c;

    a = &d;  a->speak();   // Woof!   ← decided at RUN time
    a = &c;  a->speak();   // Meow!
}
```

Without `virtual`, `a->speak()` would print "Some sound" both times, because C++ would decide at compile time using only the pointer's type.

| | Overloading | Overriding |
|---|---|---|
| Where | **same** class | **parent & child** classes |
| Signature | **different** parameters | **same** parameters |
| Decided | compile time | run time |
| Needs `virtual`? | no | yes |

🧠 **Remember:** *Overload = same name, different inputs (compile-time). Override = same name, same inputs, child re-does it (run-time).*

---

## 9. Abstraction

🧒 **Kid version:** When you drive a **toy car with a remote**, you push the stick forward and the car moves. You don't know about motors, gears, or batteries, and you don't need to. 🚗
**Abstraction = show only WHAT something does, hide HOW it does it.**

How is it different from encapsulation?

| | Encapsulation | Abstraction |
|---|---|---|
| Question it answers | "How do I **protect** my data?" | "How do I **simplify** what the user sees?" |
| Tool | `private` + getters/setters | abstract classes, pure virtual functions |
| Kid version | Piggy bank with a lock 🐷 | TV remote with a few buttons 📺 |

### Abstract classes and pure virtual functions

An **abstract class** is a class you **can't make objects from**. It's an **idea**, not a real thing, and it makes a **promise** to its children: *"Whoever inherits from me MUST provide a `draw()`."*

You make a class abstract by giving it at least one **pure virtual function**: `virtual void draw() = 0;` (The `= 0` means "no body here, children must supply it.")

💻 `abstraction/code.cpp`

```cpp
class Shape {
    virtual void draw() = 0;      // pure virtual function: "every shape can draw"
};

class Circle : public Shape {
public:
    void draw() {                 // Circle keeps the promise
        cout << "drawing a circle";
    }
};

int main() {
    Circle c1;
    c1.draw();                    // "drawing a circle"
    // Shape s;                   // ❌ ERROR: you can't create a "generic shape"
}
```

🧒 *Nobody has ever seen just "a shape." You've seen a circle, a square, a triangle. "Shape" is only the idea that they all can be drawn.*

Add a `Square`, and each draws itself differently. That's **abstraction and polymorphism teaming up**:

```cpp
class Square : public Shape { public: void draw() { cout << "drawing a square"; } };
```

> 💡 **Tiny note:** in the repo, `Shape`'s `draw()` has no `public:` label, so it is **private** (the class default). It still compiles because `Circle` makes its own public `draw()`. In real code you'd write `public:` before the pure virtual function so shapes can be used through a `Shape*`.

🧠 **Remember:** *Abstraction = the remote control. Pure virtual `= 0` = "my kids MUST do this."*

---

## 10. The `static` Keyword (last, as promised) 🧊

🧒 **Kid version:** In a classroom there are 20 kids and **one class whiteboard**.
- Each kid has **their own** notebook → **normal (instance) members**: every object gets its own copy.
- The whiteboard belongs to **the whole class**, and every kid sees the same one → **`static` member**: **one shared copy for the entire class.**

> 📝 **The repo doesn't use `static` yet**, so every example in this section is new, in the same style as the rest of the guide.

**`static` = "belongs to the class, not to any single object."**

### 10.1 Static data member (a shared variable)

```cpp
class Student {
public:
    string name;
    static int count;          // ONE shared whiteboard for ALL students

    Student(string name) {
        this->name = name;
        count++;               // every new student adds 1 to the shared counter
    }
};

int Student::count = 0;        // ⚠️ must be defined ONCE outside the class
                               // (or write `inline static int count = 0;` in C++17)

int main() {
    Student a("Tony");
    Student b("Pepper");
    Student c("Rhodey");
    cout << Student::count;    // 3, reached through the CLASS name
}
```

Memory picture:

```
 Student::count  →  [ 3 ]        ← ONE copy, shared
 a → { name:"Tony"   }           ← each object has its own name
 b → { name:"Pepper" }
 c → { name:"Rhodey" }
```

### 10.2 Static member function

A **static method** belongs to the class too. You can call it **without creating any object**.

```cpp
class Student {
public:
    static int count;
    static void showCount() {
        cout << "Total students: " << count << endl;
    }
};
int Student::count = 0;

Student::showCount();    // ✅ no object needed
```

**The big rule:** a static function has **no `this`** (it isn't "about" any single object), so it can **only use other static members**. It can't touch `name`, because *which* student's name?

### 10.3 Static local variable (remembers between calls)

🧒 *A kid who keeps a tally on a wall: every time you come back, the tally is still there.*

```cpp
void visit() {
    static int visits = 0;   // created ONCE; lives for the whole program
    visits++;
    cout << "visit #" << visits << endl;
}

visit();   // visit #1
visit();   // visit #2
visit();   // visit #3   (a normal int would reset to 0 every time)
```

### 10.4 Normal vs. static at a glance

| | Normal (instance) member | `static` member |
|---|---|---|
| Copies | one **per object** | **one for the whole class** |
| Reached via | `object.member` | `ClassName::member` (object also works) |
| Needs an object to exist? | yes | **no** |
| Has `this`? | yes | **no** |
| Lives until | the object dies | the program ends |
| Good for | name, age, salary | counters, shared settings, utility functions |

### 10.5 Using `static` together with what you learned

- **Constructors + static:** count how many objects were created, as `Student::count` above does.
- **Destructors + static:** add `count--;` inside `~Student()` to track how many are *alive*.
- **Encapsulation + static:** make `count` `private` and expose it through a `static int getCount()`, a shared whiteboard that is still protected.

🧠 **Remember:** *Normal member = your own notebook. `static` member = the class whiteboard everyone shares.*

---

## 📌 Master Cheat-Sheet

| Concept | Kid line | Keyword / syntax | Repo file |
|---|---|---|---|
| Class | Cookie cutter | `class X { };` | `classes&objects/oops.cpp` |
| Object | The cookie | `X obj;` | `classes&objects/oops.cpp` |
| Access modifiers | Yard vs bedroom | `public` `private` `protected` | `classes&objects/oops.cpp` |
| Encapsulation | Piggy bank | `private` + getters/setters | `encapsulation/code.cpp` |
| Constructor | Birth certificate | `X() {}` | `constructor/basics/code.cpp` |
| Parameterized ctor | "Name my baby Tony" | `X(string n) {}` | `constructor/basics/code.cpp` |
| `this` pointer | "my" | `this->name` | `constructor/this/code.cpp` |
| Copy constructor | Photocopier | `X(X &o) {}` | `constructor/copy_construct/code.cpp` |
| Shallow copy | Share the treasure map | copies pointer | `…/deep_copyShallow_copy/code.cpp` |
| Deep copy | Dig your own treasure | `new` + copy value | `…/deep_copyShallow_copy/code.cpp` |
| Destructor | Cleaning up the party | `~X() {}` | `destructor/code.cpp` |
| Single / multi-level inheritance | Family chain | `class B : public A` | `Inheritance/public/code.cpp` |
| Multiple inheritance | Two parents | `class C : public A, public B` | `Inheritance/multiple_inheritance/code.cpp` |
| Hierarchical inheritance | One parent, many kids | `B : A`, `C : A` | `Inheritance/hierarchial_inheritance/code.cpp` |
| Compile-time polymorphism | Vending machine slot | overloading | `polymorphism/compile_time_overloading/code.cpp` |
| Constructor overloading | Many ways to be born | several constructors | `polymorphism/runtime_overloading/code.cpp` |
| Run-time polymorphism | Mystery toy box | `virtual` + `override` | *(extra example, Section 8.2)* |
| Abstraction | TV remote | `virtual void f() = 0;` | `abstraction/code.cpp` |
| `static` | Class whiteboard | `static int count;` | *(extra examples, Section 10)* |

---

## 🐞 Things to Fix in the Repo (good practice exercises!)

| File | Issue | Fix |
|---|---|---|
| `constructor/this/code.cpp`, `constructor/copy_construct/code.cpp` | `this->salary = salary;` assigns the member to itself (parameter is named `sal`) | `this->salary = sal;` |
| `…/deep_copyShallow_copy/code.cpp` | Two copy constructors with the same signature → compile error | Keep only one at a time |
| `Inheritance/hierarchial_inheritance/code.cpp` | `Person` unused; `TA` inherits from two classes, so it's actually *multiple* inheritance | Make `Student` and `Teacher` inherit from `Person` |
| `polymorphism/runtime_overloading/code.cpp` | Demonstrates constructor overloading (compile-time), not run-time polymorphism | Rename the folder, or add a `virtual` example |
| `abstraction/code.cpp` | `Shape::draw()` is private by default | Add `public:` |
| `encapsulation/code.cpp` | `main()` is empty and there are no getters/setters yet | Add `deposit()` / `getBalance()` |
| `destructor/code.cpp` | Destructor message has no newline, and its `//memory leak` comment is placed on the `delete` line that *prevents* the leak | Add `endl` and fix the comment |

---

## 🛠️ How to Run Any Example

```bash
cd <folder>            # e.g. cd destructor
g++ code.cpp -o a.out
./a.out
```

Happy learning! 🎉 Try changing a value, breaking a rule on purpose, and reading the compiler's error. That's how it sticks.
