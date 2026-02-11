# Python 기본 문법 가이드 (C++ 비교)

## 목차
1. [Python vs C++ 주요 차이점](#python-vs-c-주요-차이점)
2. [프로그램 기본 구조](#프로그램-기본-구조)
3. [변수와 자료형](#변수와-자료형)
4. [연산자](#연산자)
5. [입출력](#입출력)
6. [조건문](#조건문)
7. [반복문](#반복문)
8. [함수](#함수)
9. [리스트와 튜플](#리스트와-튜플)
10. [딕셔너리와 집합](#딕셔너리와-집합)
11. [클래스](#클래스)

---

### 간단한 코드 비교

**C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << "Hello, World!" << endl;
    return 0;
}
```

**Python:**
```python
x = 10
print("Hello, World!")
```

---

## 프로그램 기본 구조

### C++
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

### Python
```python
# 헤더나 main 함수 불필요
print("Hello, World!")

# 또는 모듈로 사용할 때
def main():
    print("Hello, World!")

if __name__ == "__main__":
    main()
```

### 주요 차이점
- Python은 헤더 파일이나 main 함수가 필요 없습니다
- 세미콜론(`;`)이 필요 없습니다
- 들여쓰기가 문법의 일부입니다 (보통 4칸 스페이스)

---

## 변수와 자료형

### 변수 선언 및 초기화

**C++:**
```cpp
int age = 25;              // 타입 선언 필수
double price = 19.99;
string name = "홍길동";
bool isStudent = true;
```

**Python:**
```python
age = 25                   # 타입 자동 결정
price = 19.99
name = "홍길동"
isStudent = True           # Python은 True/False (대문자)
```

### 기본 자료형 비교

| C++ | Python | 설명 |
|-----|--------|------|
| `int` | `int` | 정수 (Python은 크기 제한 없음) |
| `float` | `float` | 실수 |
| `double` | `float` | Python의 float가 C++의 double과 유사 |
| `char` | `str` | 문자 (Python은 문자도 문자열) |
| `string` | `str` | 문자열 |
| `bool` | `bool` | 불린 (true/false vs True/False) |

### Python의 추가 자료형

```python
# 복소수
complex_num = 3 + 4j
print(complex_num)  # (3+4j)

# 바이트
byte_data = b'Hello'

# None (C++의 NULL과 유사)
empty_value = None
```

### 타입 확인 및 변환

**C++:**
```cpp
int x = 10;
double y = (double)x;  // 명시적 형변환
cout << typeid(x).name() << endl;
```

**Python:**
```python
x = 10
y = float(x)           # 명시적 형변환
print(type(x))         # <class 'int'>
print(type(y))         # <class 'float'>

# 타입 확인
print(isinstance(x, int))  # True
```

### 여러 변수 동시 할당 (Python 특징)

```python
# 여러 변수에 같은 값
x = y = z = 0

# 여러 변수에 다른 값
a, b, c = 1, 2, 3

# 값 교환 (swap)
x, y = 10, 20
x, y = y, x  # Python은 이렇게 간단!
print(x, y)  # 20 10

# C++에서는
# int temp = x;
# x = y;
# y = temp;
```

### 상수

**C++:**
```cpp
const double PI = 3.14159;
const int MAX_SIZE = 100;
```

**Python:**
```python
# Python은 진짜 상수가 없음 (관례상 대문자로 표시)
PI = 3.14159
MAX_SIZE = 100

# 변경 가능하지만 하지 않는 것이 관례
# PI = 3.14  # 문법적으로는 가능
```

---

## 연산자

### 산술 연산자

**C++:**
```cpp
int a = 10, b = 3;
cout << a + b;   // 13
cout << a - b;   // 7
cout << a * b;   // 30
cout << a / b;   // 3 (정수 나눗셈)
cout << a % b;   // 1 (나머지)
```

**Python:**
```python
a, b = 10, 3
print(a + b)     # 13
print(a - b)     # 7
print(a * b)     # 30
print(a / b)     # 3.333... (실수 나눗셈)
print(a // b)    # 3 (정수 나눗셈, Python 특징)
print(a % b)     # 1 (나머지)
print(a ** b)    # 1000 (거듭제곱, Python 특징)
```

### Python만의 특별한 연산자

```python
# 거듭제곱
print(2 ** 3)     # 8 (2의 3승)
print(10 ** 2)    # 100

# 정수 나눗셈
print(10 / 3)     # 3.333...
print(10 // 3)    # 3

# 문자열 연산
print("Hello" * 3)           # HelloHelloHello
print("Python" + " " + "!") # Python !
```

### 비교 연산자

**C++:**
```cpp
int x = 10, y = 20;
x == y;  // false
x != y;  // true
x > y;   // false
x < y;   // true
```

**Python:**
```python
x, y = 10, 20
x == y   # False
x != y   # True
x > y    # False
x < y    # True

# Python 특징: 연쇄 비교 가능
x = 15
print(10 < x < 20)  # True
print(1 < 2 < 3)    # True

# C++에서는
# (x > 10) && (x < 20) 이렇게 써야 함
```

### 논리 연산자

**C++:**
```cpp
bool a = true, b = false;
a && b;  // false (AND)
a || b;  // true (OR)
!a;      // false (NOT)
```

**Python:**
```python
a, b = True, False
a and b  # False (AND)
a or b   # True (OR)
not a    # False (NOT)

# Python은 and, or, not 키워드 사용 (더 읽기 쉬움)
```

### 멤버십 연산자 (Python 특징)

```python
# in, not in
fruits = ['apple', 'banana', 'orange']
print('apple' in fruits)      # True
print('grape' in fruits)      # False
print('grape' not in fruits)  # True

# 문자열에서도 사용
text = "Hello, World!"
print('Hello' in text)        # True
print('Python' in text)       # False
```

### Identity 연산자 (Python 특징)

```python
# is, is not (객체의 동일성 검사)
a = [1, 2, 3]
b = [1, 2, 3]
c = a

print(a == b)   # True (값이 같음)
print(a is b)   # False (다른 객체)
print(a is c)   # True (같은 객체)
print(a is not b)  # True
```

---

## 입출력

### 출력

**C++:**
```cpp
int age = 25;
string name = "김철수";

cout << "이름: " << name << ", 나이: " << age << endl;
```

**Python:**
```python
age = 25
name = "김철수"

# 방법 1: 쉼표로 구분
print("이름:", name, ", 나이:", age)

# 방법 2: f-string (Python 3.6+, 가장 권장)
print(f"이름: {name}, 나이: {age}")

# 방법 3: format 메서드
print("이름: {}, 나이: {}".format(name, age))

# 방법 4: % 포맷팅 (옛날 방식)
print("이름: %s, 나이: %d" % (name, age))
```

### Python 출력 옵션

```python
# 줄바꿈 없이 출력
print("Hello", end=" ")
print("World")  # Hello World

# 구분자 변경
print(1, 2, 3, 4, 5)           # 1 2 3 4 5
print(1, 2, 3, 4, 5, sep="-")  # 1-2-3-4-5

# 여러 줄 문자열
print("""
    첫 번째 줄
    두 번째 줄
    세 번째 줄
""")
```

### 입력

**C++:**
```cpp
int number;
string name;

cout << "숫자를 입력하세요: ";
cin >> number;

cout << "이름을 입력하세요: ";
cin >> name;
```

**Python:**
```python
# 모든 입력은 문자열로 받음
name = input("이름을 입력하세요: ")
print(f"안녕하세요, {name}님!")

# 숫자로 변환
age = int(input("나이를 입력하세요: "))
height = float(input("키를 입력하세요: "))

# 여러 값 입력 (공백으로 구분)
# 입력: 10 20 30
numbers = input("숫자 3개를 입력하세요: ").split()
a, b, c = map(int, numbers)
print(a, b, c)  # 10 20 30

# 한 줄로
a, b = map(int, input("두 숫자 입력: ").split())
```

---

## 조건문

### if 문

**C++:**
```cpp
int score = 85;

if (score >= 90) {
    cout << "A학점" << endl;
} else if (score >= 80) {
    cout << "B학점" << endl;
} else if (score >= 70) {
    cout << "C학점" << endl;
} else {
    cout << "재수강" << endl;
}
```

**Python:**
```python
score = 85

if score >= 90:
    print("A학점")
elif score >= 80:      # else if 대신 elif
    print("B학점")
elif score >= 70:
    print("C학점")
else:
    print("재수강")

# 주요 차이점:
# 1. 괄호 () 불필요
# 2. 중괄호 {} 대신 콜론 :
# 3. 들여쓰기로 블록 구분
# 4. else if 대신 elif
```

### 조건 표현식 (삼항 연산자)

**C++:**
```cpp
int age = 20;
string status = (age >= 18) ? "성인" : "미성년자";
```

**Python:**
```python
age = 20
status = "성인" if age >= 18 else "미성년자"

# 더 복잡한 예
score = 85
grade = "A" if score >= 90 else "B" if score >= 80 else "C"
```

### Python의 특별한 조건문

```python
# 한 줄 if문
if age >= 18: print("성인입니다")

# 여러 조건 동시 확인
x = 15
if 10 < x < 20:
    print("10과 20 사이")

# in을 사용한 조건
fruit = "apple"
if fruit in ["apple", "banana", "orange"]:
    print("과일이 목록에 있습니다")

# not 조건
if not isStudent:
    print("학생이 아닙니다")
```

### switch/case 대체 (Python 3.10+)

**C++:**
```cpp
int day = 3;

switch (day) {
    case 1:
        cout << "월요일" << endl;
        break;
    case 2:
        cout << "화요일" << endl;
        break;
    case 3:
        cout << "수요일" << endl;
        break;
    default:
        cout << "기타" << endl;
}
```

**Python (3.10+):**
```python
day = 3

# match-case (Python 3.10+)
match day:
    case 1:
        print("월요일")
    case 2:
        print("화요일")
    case 3:
        print("수요일")
    case _:
        print("기타")

# 이전 버전 (딕셔너리 사용)
day_names = {
    1: "월요일",
    2: "화요일",
    3: "수요일"
}
print(day_names.get(day, "기타"))
```

---

## 반복문

### for 문

**C++:**
```cpp
// 일반 for문
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}

// 배열 순회 (C++11)
int arr[] = {10, 20, 30, 40, 50};
for (int num : arr) {
    cout << num << " ";
}
```

**Python:**
```python
# range 사용
for i in range(5):
    print(i, end=" ")  # 0 1 2 3 4

# range(시작, 끝, 간격)
for i in range(0, 10, 2):
    print(i, end=" ")  # 0 2 4 6 8

# 역순
for i in range(5, 0, -1):
    print(i, end=" ")  # 5 4 3 2 1

# 리스트 직접 순회
fruits = ["apple", "banana", "orange"]
for fruit in fruits:
    print(fruit)

# 인덱스와 값 동시 접근
for index, fruit in enumerate(fruits):
    print(f"{index}: {fruit}")
```

### while 문

**C++:**
```cpp
int count = 0;
while (count < 5) {
    cout << count << " ";
    count++;
}
```

**Python:**
```python
count = 0
while count < 5:
    print(count, end=" ")
    count += 1

# 무한 루프
while True:
    answer = input("계속하시겠습니까? (y/n): ")
    if answer == 'n':
        break
```

### break와 continue

**C++:**
```cpp
// break
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    cout << i << " ";
}

// continue
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;
    cout << i << " ";
}
```

**Python:**
```python
# break
for i in range(10):
    if i == 5:
        break
    print(i, end=" ")  # 0 1 2 3 4

# continue
for i in range(10):
    if i % 2 == 0:
        continue
    print(i, end=" ")  # 1 3 5 7 9
```

### Python의 특별한 for-else

```python
# else는 break 없이 정상 종료 시 실행
for i in range(5):
    print(i)
else:
    print("반복문이 정상 종료되었습니다")

# break 발생 시 else 실행 안됨
for i in range(5):
    if i == 3:
        break
    print(i)
else:
    print("이 메시지는 출력되지 않습니다")
```

### 리스트 컴프리헨션 (Python 특징)

```python
# 일반 방식
squares = []
for i in range(10):
    squares.append(i ** 2)

# 리스트 컴프리헨션 (한 줄로)
squares = [i ** 2 for i in range(10)]
print(squares)  # [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

# 조건 포함
even_squares = [i ** 2 for i in range(10) if i % 2 == 0]
print(even_squares)  # [0, 4, 16, 36, 64]

# 중첩 반복문
matrix = [[i * j for j in range(3)] for i in range(3)]
print(matrix)  # [[0, 0, 0], [0, 1, 2], [0, 2, 4]]
```

---

## 함수

### 함수 기본

**C++:**
```cpp
// 함수 선언
int add(int a, int b);

int main() {
    int result = add(5, 3);
    cout << result << endl;
    return 0;
}

// 함수 정의
int add(int a, int b) {
    return a + b;
}
```

**Python:**
```python
# 함수 정의 (선언과 정의 동시)
def add(a, b):
    return a + b

# 함수 호출
result = add(5, 3)
print(result)  # 8

# 타입 힌트 (선택사항, Python 3.5+)
def add(a: int, b: int) -> int:
    return a + b
```

### 반환값이 없는 함수

**C++:**
```cpp
void printMessage(string msg) {
    cout << msg << endl;
}
```

**Python:**
```python
def print_message(msg):
    print(msg)
    # return 생략 가능 (자동으로 None 반환)

# 또는 명시적으로
def print_message(msg):
    print(msg)
    return  # None 반환
```

### 기본 매개변수

**C++:**
```cpp
void greet(string name, int age = 20) {
    cout << "이름: " << name << ", 나이: " << age << endl;
}

greet("홍길동");        // 이름: 홍길동, 나이: 20
greet("김철수", 25);    // 이름: 김철수, 나이: 25
```

**Python:**
```python
def greet(name, age=20):
    print(f"이름: {name}, 나이: {age}")

greet("홍길동")         # 이름: 홍길동, 나이: 20
greet("김철수", 25)     # 이름: 김철수, 나이: 25

# 키워드 인수 사용 (순서 무관)
greet(age=30, name="이영희")
```

### 여러 값 반환 (Python 특징)

**C++:**
```cpp
// 구조체나 pair 사용해야 함
#include <utility>
pair<int, int> getMinMax(int a, int b) {
    return make_pair(min(a, b), max(a, b));
}
```

**Python:**
```python
# 튜플로 여러 값 반환
def get_min_max(a, b):
    return min(a, b), max(a, b)

minimum, maximum = get_min_max(10, 20)
print(minimum, maximum)  # 10 20

# 여러 값 반환 예제
def divide(a, b):
    quotient = a // b
    remainder = a % b
    return quotient, remainder

q, r = divide(17, 5)
print(f"몫: {q}, 나머지: {r}")  # 몫: 3, 나머지: 2
```

### 가변 인수 (Python 특징)

```python
# *args: 위치 인수를 튜플로 받음
def sum_all(*numbers):
    total = 0
    for num in numbers:
        total += num
    return total

print(sum_all(1, 2, 3))        # 6
print(sum_all(1, 2, 3, 4, 5))  # 15

# **kwargs: 키워드 인수를 딕셔너리로 받음
def print_info(**info):
    for key, value in info.items():
        print(f"{key}: {value}")

print_info(name="홍길동", age=25, city="서울")
# name: 홍길동
# age: 25
# city: 서울

# 둘 다 사용
def func(a, b, *args, **kwargs):
    print(f"a: {a}, b: {b}")
    print(f"args: {args}")
    print(f"kwargs: {kwargs}")

func(1, 2, 3, 4, 5, x=10, y=20)
# a: 1, b: 2
# args: (3, 4, 5)
# kwargs: {'x': 10, 'y': 20}
```

### Lambda 함수 (익명 함수)

**C++:**
```cpp
// C++11 람다
auto add = [](int a, int b) { return a + b; };
cout << add(3, 5) << endl;  // 8
```

**Python:**
```python
# lambda
add = lambda a, b: a + b
print(add(3, 5))  # 8

# 주로 sorted, map, filter 등과 함께 사용
numbers = [5, 2, 8, 1, 9]
sorted_numbers = sorted(numbers, key=lambda x: -x)
print(sorted_numbers)  # [9, 8, 5, 2, 1]

# map: 모든 요소에 함수 적용
numbers = [1, 2, 3, 4, 5]
squares = list(map(lambda x: x ** 2, numbers))
print(squares)  # [1, 4, 9, 16, 25]

# filter: 조건에 맞는 요소만 선택
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # [2, 4]
```

### 재귀 함수

**C++:**
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

**Python:**
```python
def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)

print(factorial(5))  # 120
```

---

## 리스트와 튜플

### 리스트 (List) - C++의 vector와 유사

**C++:**
```cpp
#include <vector>

vector<int> numbers = {10, 20, 30, 40, 50};
numbers.push_back(60);      // 추가
numbers[0] = 15;            // 수정
cout << numbers[0] << endl; // 접근
```

**Python:**
```python
# 리스트 생성
numbers = [10, 20, 30, 40, 50]

# 요소 추가
numbers.append(60)         # 끝에 추가
numbers.insert(0, 5)       # 특정 위치에 추가

# 요소 접근
print(numbers[0])          # 10 (첫 번째)
print(numbers[-1])         # 60 (마지막, Python 특징)
print(numbers[-2])         # 50 (뒤에서 두 번째)

# 요소 수정
numbers[0] = 15

# 요소 삭제
numbers.remove(20)         # 값으로 삭제
del numbers[0]             # 인덱스로 삭제
popped = numbers.pop()     # 마지막 요소 삭제 및 반환

# 리스트 길이
print(len(numbers))
```

### 리스트 슬라이싱 (Python 특징)

```python
numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# [시작:끝] - 끝은 포함 안됨
print(numbers[2:5])      # [2, 3, 4]
print(numbers[:5])       # [0, 1, 2, 3, 4] (처음부터)
print(numbers[5:])       # [5, 6, 7, 8, 9] (끝까지)
print(numbers[:])        # 전체 복사

# [시작:끝:간격]
print(numbers[::2])      # [0, 2, 4, 6, 8] (2칸씩)
print(numbers[1::2])     # [1, 3, 5, 7, 9]
print(numbers[::-1])     # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0] (역순)

# 슬라이싱으로 수정
numbers[2:5] = [20, 30, 40]
print(numbers)
```

### 리스트 메서드

```python
numbers = [3, 1, 4, 1, 5, 9, 2, 6]

# 정렬
numbers.sort()              # 원본 수정
print(numbers)              # [1, 1, 2, 3, 4, 5, 6, 9]

sorted_nums = sorted(numbers, reverse=True)  # 새 리스트 반환
print(sorted_nums)          # [9, 6, 5, 4, 3, 2, 1, 1]

# 뒤집기
numbers.reverse()
print(numbers)

# 요소 개수
print(numbers.count(1))     # 2

# 인덱스 찾기
print(numbers.index(5))     # 5가 있는 인덱스

# 리스트 합치기
list1 = [1, 2, 3]
list2 = [4, 5, 6]
combined = list1 + list2    # [1, 2, 3, 4, 5, 6]
list1.extend(list2)         # list1에 list2 추가
```

### 2차원 리스트

**C++:**
```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

**Python:**
```python
# 2차원 리스트 생성
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

# 접근
print(matrix[0][0])  # 1
print(matrix[1][2])  # 6

# 리스트 컴프리헨션으로 생성
matrix = [[i * 3 + j + 1 for j in range(3)] for i in range(3)]

# 순회
for row in matrix:
    for element in row:
        print(element, end=" ")
    print()
```

### 튜플 (Tuple) - 수정 불가능한 리스트

```python
# 튜플 생성
coordinates = (10, 20)
rgb = (255, 128, 0)

# 접근
print(coordinates[0])  # 10

# 튜플은 수정 불가
# coordinates[0] = 15  # 에러!

# 패킹과 언패킹
point = 10, 20, 30     # 패킹 (괄호 생략 가능)
x, y, z = point        # 언패킹
print(x, y, z)         # 10 20 30

# 함수에서 여러 값 반환 (튜플 사용)
def get_name_age():
    return "홍길동", 25

name, age = get_name_age()

# 단일 요소 튜플
single = (5,)  # 쉼표 필수!
not_tuple = (5)  # 이건 그냥 정수 5
```

---

## 딕셔너리와 집합

### 딕셔너리 (Dictionary) - C++의 map과 유사

**C++:**
```cpp
#include <map>

map<string, int> ages;
ages["홍길동"] = 25;
ages["김철수"] = 30;

cout << ages["홍길동"] << endl;  // 25
```

**Python:**
```python
# 딕셔너리 생성
ages = {
    "홍길동": 25,
    "김철수": 30,
    "이영희": 28
}

# 값 접근
print(ages["홍길동"])     # 25

# 안전한 접근 (키가 없을 때 기본값 반환)
print(ages.get("박민수", 0))  # 0

# 값 추가/수정
ages["박민수"] = 35
ages["홍길동"] = 26       # 수정

# 값 삭제
del ages["김철수"]
removed = ages.pop("이영희")  # 삭제 및 반환

# 키 존재 확인
if "홍길동" in ages:
    print("존재합니다")

# 모든 키, 값, 항목
print(ages.keys())        # dict_keys(['홍길동', '박민수'])
print(ages.values())      # dict_values([26, 35])
print(ages.items())       # dict_items([('홍길동', 26), ...])

# 순회
for name, age in ages.items():
    print(f"{name}: {age}세")
```

### 딕셔너리 메서드

```python
person = {
    "name": "홍길동",
    "age": 25,
    "city": "서울"
}

# update: 여러 항목 추가/수정
person.update({"age": 26, "job": "개발자"})
print(person)

# setdefault: 키가 없을 때만 추가
person.setdefault("country", "한국")
person.setdefault("name", "김철수")  # 이미 있어서 무시됨
print(person)

# clear: 모든 항목 삭제
person.clear()
```

### 집합 (Set) - C++의 set과 유사

```python
# 집합 생성 (중복 제거, 순서 없음)
numbers = {1, 2, 3, 4, 5}
fruits = set(["apple", "banana", "apple"])  # {"apple", "banana"}

# 요소 추가/제거
numbers.add(6)
numbers.remove(3)      # 없으면 에러
numbers.discard(10)    # 없어도 에러 안남

# 집합 연산
set1 = {1, 2, 3, 4, 5}
set2 = {4, 5, 6, 7, 8}

print(set1 | set2)  # 합집합: {1, 2, 3, 4, 5, 6, 7, 8}
print(set1 & set2)  # 교집합: {4, 5}
print(set1 - set2)  # 차집합: {1, 2, 3}
print(set1 ^ set2)  # 대칭차집합: {1, 2, 3, 6, 7, 8}

# 멤버십 테스트 (매우 빠름)
print(3 in set1)    # True

# 리스트에서 중복 제거
numbers = [1, 2, 2, 3, 3, 3, 4, 5]
unique = list(set(numbers))
print(unique)  # [1, 2, 3, 4, 5]
```

---

## 클래스

### 클래스 기본

**C++:**
```cpp
class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    
    double getArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    cout << rect.getArea() << endl;
    return 0;
}
```

**Python:**
```python
class Rectangle:
    # 생성자
    def __init__(self, width, height):
        self.width = width    # self는 C++의 this와 유사
        self.height = height
    
    # 메서드
    def get_area(self):
        return self.width * self.height
    
    def get_perimeter(self):
        return 2 * (self.width + self.height)

# 객체 생성 (new 불필요)
rect = Rectangle(5.0, 3.0)
print(rect.get_area())       # 15.0
print(rect.get_perimeter())  # 16.0

# 속성 직접 접근 (Python은 기본적으로 public)
print(rect.width)   # 5.0
rect.width = 10.0
```

### 클래스 변수와 인스턴스 변수

```python
class Student:
    # 클래스 변수 (모든 인스턴스가 공유)
    school = "파이썬 고등학교"
    student_count = 0
    
    def __init__(self, name, grade):
        # 인스턴스 변수 (각 인스턴스마다 다름)
        self.name = name
        self.grade = grade
        Student.student_count += 1
    
    def introduce(self):
        print(f"{self.school}의 {self.name}입니다. {self.grade}학년입니다.")

# 사용
s1 = Student("홍길동", 1)
s2 = Student("김철수", 2)

s1.introduce()  # 파이썬 고등학교의 홍길동입니다. 1학년입니다.
print(Student.student_count)  # 2
```

### Private 속성 (Python 방식)

```python
class BankAccount:
    def __init__(self, owner, balance):
        self.owner = owner
        self.__balance = balance  # __ 로 시작하면 private
    
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"{amount}원 입금되었습니다.")
    
    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            print(f"{amount}원 출금되었습니다.")
        else:
            print("잔액이 부족합니다.")
    
    def get_balance(self):
        return self.__balance

# 사용
account = BankAccount("홍길동", 10000)
account.deposit(5000)
account.withdraw(3000)
print(account.get_balance())  # 12000

# 직접 접근 시도 (에러)
# print(account.__balance)  # AttributeError
```

### 상속

**C++:**
```cpp
class Animal {
public:
    void eat() {
        cout << "먹이를 먹습니다." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "멍멍!" << endl;
    }
};
```

**Python:**
```python
class Animal:
    def __init__(self, name):
        self.name = name
    
    def eat(self):
        print(f"{self.name}이(가) 먹이를 먹습니다.")

class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name)  # 부모 클래스 생성자 호출
        self.breed = breed
    
    def bark(self):
        print(f"{self.name}: 멍멍!")

# 사용
dog = Dog("바둑이", "진돗개")
dog.eat()   # 바둑이이(가) 먹이를 먹습니다.
dog.bark()  # 바둑이: 멍멍!
```

### 특수 메서드 (매직 메서드)

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    # 문자열 표현
    def __str__(self):
        return f"Point({self.x}, {self.y})"
    
    # 연산자 오버로딩
    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)
    
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    
    # 길이
    def __len__(self):
        return 2

p1 = Point(1, 2)
p2 = Point(3, 4)

print(p1)           # Point(1, 2)
p3 = p1 + p2        # 연산자 오버로딩
print(p3)           # Point(4, 6)
print(p1 == p2)     # False
print(len(p1))      # 2
```

### 프로퍼티 (Property)

```python
class Circle:
    def __init__(self, radius):
        self._radius = radius
    
    @property  # getter
    def radius(self):
        return self._radius
    
    @radius.setter  # setter
    def radius(self, value):
        if value > 0:
            self._radius = value
        else:
            raise ValueError("반지름은 양수여야 합니다")
    
    @property
    def area(self):  # 읽기 전용 속성
        return 3.14159 * self._radius ** 2

# 사용
circle = Circle(5)
print(circle.radius)  # 5
circle.radius = 10    # setter 호출
print(circle.area)    # 314.159
# circle.area = 100   # 에러! (setter 없음)
```

---

## 추가 Python 특징

### 파일 입출력

**C++:**
```cpp
#include <fstream>

// 쓰기
ofstream file("data.txt");
file << "Hello, World!" << endl;
file.close();

// 읽기
ifstream infile("data.txt");
string line;
while (getline(infile, line)) {
    cout << line << endl;
}
infile.close();
```

**Python:**
```python
# 쓰기
with open("data.txt", "w", encoding="utf-8") as file:
    file.write("Hello, World!\n")
    file.write("Python is easy!")

# 읽기
with open("data.txt", "r", encoding="utf-8") as file:
    content = file.read()
    print(content)

# 한 줄씩 읽기
with open("data.txt", "r", encoding="utf-8") as file:
    for line in file:
        print(line.strip())

# 모든 줄을 리스트로
with open("data.txt", "r", encoding="utf-8") as file:
    lines = file.readlines()
```

### 예외 처리

**C++:**
```cpp
try {
    int x = 10 / 0;
} catch (exception& e) {
    cout << "에러 발생!" << endl;
}
```

**Python:**
```python
try:
    x = 10 / 0
except ZeroDivisionError:
    print("0으로 나눌 수 없습니다!")
except Exception as e:
    print(f"에러 발생: {e}")
else:
    print("에러 없이 실행됨")
finally:
    print("항상 실행됨")

# 여러 예외 동시 처리
try:
    value = int(input("숫자 입력: "))
    result = 10 / value
except (ValueError, ZeroDivisionError) as e:
    print(f"에러: {e}")
```

### 모듈과 패키지

```python
# math 모듈 사용
import math
print(math.pi)        # 3.141592...
print(math.sqrt(16))  # 4.0

# 특정 함수만 import
from math import pi, sqrt
print(pi)
print(sqrt(16))

# 별칭 사용
import math as m
print(m.pi)

# 모든 것 import (권장하지 않음)
from math import *
```

### 유용한 내장 함수

```python
# 범위
numbers = [1, 2, 3, 4, 5]
print(sum(numbers))      # 15
print(max(numbers))      # 5
print(min(numbers))      # 1
print(len(numbers))      # 5

# 타입 변환
print(int("123"))        # 123
print(float("3.14"))     # 3.14
print(str(100))          # "100"
print(list("hello"))     # ['h', 'e', 'l', 'l', 'o']

# enumerate
for i, value in enumerate(['a', 'b', 'c']):
    print(f"{i}: {value}")

# zip
names = ["Alice", "Bob", "Charlie"]
ages = [25, 30, 35]
for name, age in zip(names, ages):
    print(f"{name}: {age}세")

# any, all
print(any([False, False, True]))   # True
print(all([True, True, True]))     # True
```

---

## 학습 팁

### Python을 배우면 좋은 점

1. **쉬운 문법**: C++보다 배우기 쉽고 읽기 쉬움
2. **빠른 개발**: 같은 기능을 더 적은 코드로 구현
3. **풍부한 라이브러리**: 데이터 분석, 웹, AI 등 다양한 분야
4. **커뮤니티**: 초보자를 위한 자료가 풍부함

### C++을 배우면 좋은 점

1. **성능**: 시스템 프로그래밍, 게임 개발 등에 필수
2. **메모리 제어**: 하드웨어에 가까운 프로그래밍 가능
3. **깊은 이해**: 컴퓨터 구조와 메모리 관리를 깊이 이해
4. **취업**: 많은 기업에서 C++ 개발자 필요

### 두 언어 모두 배우는 것을 추천합니다!

- **C++**: 컴퓨터 과학의 기초를 탄탄히
- **Python**: 빠른 프로토타이핑과 실용적인 프로젝트

---

## 자주 사용하는 Python 라이브러리

```python
# NumPy - 수치 계산
import numpy as np
arr = np.array([1, 2, 3, 4, 5])
print(arr.mean())  # 3.0

# Pandas - 데이터 분석
import pandas as pd
df = pd.DataFrame({
    'name': ['Alice', 'Bob'],
    'age': [25, 30]
})

# Matplotlib - 그래프
import matplotlib.pyplot as plt
plt.plot([1, 2, 3, 4])
plt.show()

# Requests - HTTP 요청
import requests
response = requests.get('https://api.example.com')
```

이제 C++과 Python의 기본 문법을 모두 이해하셨을 거예요! 두 언어를 비교하면서 배우면 더 깊이 이해할 수 있습니다. 화이팅! 🚀
