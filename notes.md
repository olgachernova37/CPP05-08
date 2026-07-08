Це **Orthodox Canonical AForm** для класу (базовий “набір” спецфункцій).

- `Bureaucrat();`  
  **Конструктор за замовчуванням**  
  Створює об’єкт без параметрів.

- `Bureaucrat(const std::string& name, int grade);`  
  **Звичайний конструктор з параметрами**  
  Створює `Bureaucrat` з конкретними `name` і `grade`.

- `Bureaucrat(const Bureaucrat& other);`  
  **Конструктор копіювання**  
  Створює новий об’єкт як копію `other`.

- `Bureaucrat& operator=(const Bureaucrat& other);`  
  **Оператор присвоєння**  
  Коли об’єкт уже існує, копіює в нього значення з `other`:
  ```cpp
  a = b;
  ```

---

### Важливий нюанс у твоєму випадку
У `Bureaucrat` є `const std::string _name;`  
`const` поле **не можна переприсвоїти** в `operator=`.

Тому зазвичай:
- в `operator=` копіюють тільки `_grade`
- `_name` лишається як був.

