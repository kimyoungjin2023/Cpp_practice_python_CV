# C++ 기본 문법 가이드

## 목차
1. [프로그램 기본 구조](#프로그램-기본-구조)
2. [변수와 자료형](#변수와-자료형)
3. [연산자](#연산자)
4. [입출력](#입출력)
5. [조건문](#조건문)
6. [반복문](#반복문)
7. [함수](#함수)
8. [배열](#배열)
9. [포인터](#포인터)
10. [구조체와 클래스](#구조체와-클래스)

---

## 프로그램 기본 구조

모든 C++ 프로그램은 기본적으로 다음과 같은 구조를 가집니다:

```cpp
#include <iostream>  // 헤더 파일 포함
using namespace std; // 네임스페이스 사용

int main() {         // 메인 함수 (프로그램 시작점)
    // 코드 작성
    cout << "Hello, World!" << endl;
    return 0;        // 프로그램 종료 (0은 정상 종료)
}
```

### 주요 구성 요소 설명

- `#include <iostream>`: 입출력 스트림 라이브러리를 포함합니다.
- `using namespace std;`: std 네임스페이스를 사용하여 `std::cout` 대신 `cout`만 작성할 수 있습니다.
- `int main()`: 프로그램의 시작점입니다. 모든 C++ 프로그램은 main 함수를 가져야 합니다.
- `return 0;`: 프로그램이 정상적으로 종료되었음을 운영체제에 알립니다.

---

## 변수와 자료형

### 기본 자료형

C++에서 제공하는 기본 자료형들입니다:

```cpp
// 정수형
int age = 25;              // 4바이트, -2,147,483,648 ~ 2,147,483,647
short height = 170;        // 2바이트, -32,768 ~ 32,767
long population = 50000000L; // 4바이트 이상
long long bigNumber = 9223372036854775807LL; // 8바이트

// 부호 없는 정수형
unsigned int count = 100;  // 0 ~ 4,294,967,295

// 실수형
float price = 19.99f;      // 4바이트, 소수점 6-7자리
double pi = 3.14159265359; // 8바이트, 소수점 15-16자리

// 문자형
char grade = 'A';          // 1바이트, 단일 문자
string name = "홍길동";     // 문자열 (string 헤더 필요)

// 불린형
bool isStudent = true;     // true 또는 false
```

### 변수 선언 및 초기화

```cpp
// 선언만
int number;

// 선언과 동시에 초기화
int score = 100;

// 여러 변수 동시 선언
int a, b, c;
int x = 1, y = 2, z = 3;

// const (상수) - 값 변경 불가
const double PI = 3.14159;
const int MAX_SIZE = 100;
```

### 자료형 크기 확인

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "int 크기: " << sizeof(int) << " 바이트" << endl;
    cout << "double 크기: " << sizeof(double) << " 바이트" << endl;
    return 0;
}
```

---

## 연산자

### 산술 연산자

```cpp
int a = 10, b = 3;

cout << a + b;  // 13 (덧셈)
cout << a - b;  // 7  (뺄셈)
cout << a * b;  // 30 (곱셈)
cout << a / b;  // 3  (나눗셈, 정수 나눗셈)
cout << a % b;  // 1  (나머지)

// 실수 나눗셈
double x = 10.0, y = 3.0;
cout << x / y;  // 3.33333...
```

### 증감 연산자

```cpp
int num = 5;

num++;    // 후위 증가 (num = num + 1)
++num;    // 전위 증가
num--;    // 후위 감소 (num = num - 1)
--num;    // 전위 감소

// 전위와 후위의 차이
int a = 5;
int b = a++;  // b = 5, a = 6 (먼저 할당, 후 증가)
int c = ++a;  // c = 7, a = 7 (먼저 증가, 후 할당)
```

### 비교 연산자

```cpp
int x = 10, y = 20;

x == y;  // false (같다)
x != y;  // true  (다르다)
x > y;   // false (크다)
x < y;   // true  (작다)
x >= y;  // false (크거나 같다)
x <= y;  // true  (작거나 같다)
```

### 논리 연산자

```cpp
bool a = true, b = false;

a && b;  // false (AND - 둘 다 참이어야 참)
a || b;  // true  (OR - 하나라도 참이면 참)
!a;      // false (NOT - 부정)

// 예제
int age = 25;
bool isAdult = (age >= 18) && (age < 65);  // true
```

### 대입 연산자

```cpp
int num = 10;

num += 5;   // num = num + 5  (15)
num -= 3;   // num = num - 3  (12)
num *= 2;   // num = num * 2  (24)
num /= 4;   // num = num / 4  (6)
num %= 4;   // num = num % 4  (2)
```

---

## 입출력

### 출력 (cout)

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 25;
    string name = "김철수";
    
    // 기본 출력
    cout << "안녕하세요" << endl;
    
    // 여러 값 출력
    cout << "이름: " << name << ", 나이: " << age << endl;
    
    // endl 대신 \n 사용 가능
    cout << "첫 번째 줄\n";
    cout << "두 번째 줄\n";
    
    return 0;
}
```

### 입력 (cin)

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    string name;
    
    // 정수 입력
    cout << "숫자를 입력하세요: ";
    cin >> number;
    
    // 문자열 입력 (공백 전까지)
    cout << "이름을 입력하세요: ";
    cin >> name;
    
    // 여러 값 동시 입력
    int a, b;
    cout << "두 숫자를 입력하세요: ";
    cin >> a >> b;
    
    cout << "입력한 값: " << a << ", " << b << endl;
    
    return 0;
}
```

### 공백 포함 문자열 입력

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;
    
    cout << "전체 이름을 입력하세요: ";
    getline(cin, fullName);  // 공백 포함 한 줄 입력
    
    cout << "입력한 이름: " << fullName << endl;
    
    return 0;
}
```

---

## 조건문

### if 문

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

### 중첩 if 문

```cpp
int age = 25;
bool hasLicense = true;

if (age >= 18) {
    if (hasLicense) {
        cout << "운전 가능합니다." << endl;
    } else {
        cout << "면허가 필요합니다." << endl;
    }
} else {
    cout << "나이가 부족합니다." << endl;
}
```

### switch 문

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
    case 4:
        cout << "목요일" << endl;
        break;
    case 5:
        cout << "금요일" << endl;
        break;
    case 6:
    case 7:
        cout << "주말" << endl;
        break;
    default:
        cout << "잘못된 입력" << endl;
}
```

### 삼항 연산자

```cpp
int age = 20;
string status = (age >= 18) ? "성인" : "미성년자";
cout << status << endl;  // "성인"

// 중첩 삼항 연산자
int score = 85;
string grade = (score >= 90) ? "A" : (score >= 80) ? "B" : "C";
```

---

## 반복문

### for 문

```cpp
// 기본 for 문
for (int i = 0; i < 5; i++) {
    cout << i << " ";  // 0 1 2 3 4
}
cout << endl;

// 역순 반복
for (int i = 5; i > 0; i--) {
    cout << i << " ";  // 5 4 3 2 1
}
cout << endl;

// 2씩 증가
for (int i = 0; i <= 10; i += 2) {
    cout << i << " ";  // 0 2 4 6 8 10
}
cout << endl;

// 중첩 for 문 (구구단)
for (int i = 2; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
        cout << i << " x " << j << " = " << i * j << endl;
    }
    cout << endl;
}
```

### while 문

```cpp
int count = 0;

while (count < 5) {
    cout << count << " ";
    count++;
}
// 출력: 0 1 2 3 4

// 무한 루프 (조건에 따라 break로 탈출)
while (true) {
    int number;
    cout << "숫자 입력 (0으로 종료): ";
    cin >> number;
    
    if (number == 0) {
        break;
    }
    
    cout << "입력한 숫자: " << number << endl;
}
```

### do-while 문

```cpp
// 최소 1회는 실행됨
int num;

do {
    cout << "1~10 사이의 숫자를 입력하세요: ";
    cin >> num;
} while (num < 1 || num > 10);

cout << "올바른 입력: " << num << endl;
```

### break와 continue

```cpp
// break: 반복문 즉시 종료
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // i가 5일 때 반복문 종료
    }
    cout << i << " ";  // 0 1 2 3 4
}
cout << endl;

// continue: 현재 반복만 건너뛰고 다음 반복 계속
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // 짝수일 때 건너뛰기
    }
    cout << i << " ";  // 1 3 5 7 9
}
cout << endl;
```

---

## 함수

### 함수 기본 구조

```cpp
// 함수 선언 (프로토타입)
int add(int a, int b);

int main() {
    int result = add(5, 3);
    cout << "결과: " << result << endl;  // 8
    return 0;
}

// 함수 정의
int add(int a, int b) {
    return a + b;
}
```

### 반환값이 없는 함수 (void)

```cpp
void printMessage(string msg) {
    cout << msg << endl;
    // return 생략 가능
}

int main() {
    printMessage("안녕하세요!");
    return 0;
}
```

### 다양한 함수 예제

```cpp
// 두 수 중 큰 값 반환
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 팩토리얼 계산
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // 재귀 호출
}

// 참조를 이용한 값 교환
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << max(10, 20) << endl;        // 20
    cout << factorial(5) << endl;       // 120
    
    int x = 5, y = 10;
    swap(x, y);
    cout << x << ", " << y << endl;     // 10, 5
    
    return 0;
}
```

### 함수 오버로딩

같은 이름의 함수를 매개변수만 다르게 여러 개 정의할 수 있습니다:

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << add(1, 2) << endl;          // 3
    cout << add(1.5, 2.3) << endl;      // 3.8
    cout << add(1, 2, 3) << endl;       // 6
    return 0;
}
```

### 기본 매개변수

```cpp
void printInfo(string name, int age = 20) {
    cout << "이름: " << name << ", 나이: " << age << endl;
}

int main() {
    printInfo("홍길동");           // 이름: 홍길동, 나이: 20
    printInfo("김철수", 25);       // 이름: 김철수, 나이: 25
    return 0;
}
```

---

## 배열

### 1차원 배열

```cpp
// 배열 선언 및 초기화
int numbers[5] = {10, 20, 30, 40, 50};

// 부분 초기화 (나머지는 0)
int arr[5] = {1, 2};  // {1, 2, 0, 0, 0}

// 크기 자동 결정
int data[] = {1, 2, 3, 4, 5};  // 크기 5

// 배열 요소 접근
cout << numbers[0] << endl;  // 10 (첫 번째 요소)
cout << numbers[4] << endl;  // 50 (마지막 요소)

// 배열 요소 수정
numbers[2] = 35;

// 배열 순회
for (int i = 0; i < 5; i++) {
    cout << numbers[i] << " ";
}
cout << endl;

// 범위 기반 for 문 (C++11)
for (int num : numbers) {
    cout << num << " ";
}
cout << endl;
```

### 배열 크기 구하기

```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);
cout << "배열 크기: " << size << endl;  // 5
```

### 2차원 배열

```cpp
// 2차원 배열 선언 및 초기화
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// 2차원 배열 접근
cout << matrix[0][0] << endl;  // 1
cout << matrix[2][3] << endl;  // 12

// 2차원 배열 순회
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

### 문자 배열 (C-스타일 문자열)

```cpp
char name1[] = "Hello";  // 자동으로 널 문자(\0) 추가
char name2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

cout << name1 << endl;  // Hello

// string 클래스 (권장)
string str = "Hello, World!";
cout << str.length() << endl;  // 13
```

---

## 포인터

### 포인터 기본

```cpp
int num = 10;
int *ptr = &num;  // ptr은 num의 주소를 저장

cout << "num의 값: " << num << endl;        // 10
cout << "num의 주소: " << &num << endl;     // 주소 (예: 0x7ffd...)
cout << "ptr의 값: " << ptr << endl;        // num의 주소
cout << "*ptr의 값: " << *ptr << endl;      // 10 (역참조)

// 포인터를 통한 값 변경
*ptr = 20;
cout << "num의 값: " << num << endl;        // 20
```

### NULL 포인터

```cpp
int *ptr = nullptr;  // C++11 이후 권장
// int *ptr = NULL;  // 이전 방식

if (ptr == nullptr) {
    cout << "포인터가 아무것도 가리키지 않습니다." << endl;
}
```

### 포인터와 배열

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;  // 배열 이름은 첫 번째 요소의 주소

cout << *ptr << endl;        // 10
cout << *(ptr + 1) << endl;  // 20
cout << *(ptr + 2) << endl;  // 30

// 포인터를 이용한 배열 순회
for (int i = 0; i < 5; i++) {
    cout << *(ptr + i) << " ";
}
cout << endl;
```

### 동적 메모리 할당

```cpp
// new와 delete
int *ptr = new int;      // 정수 하나 동적 할당
*ptr = 100;
cout << *ptr << endl;
delete ptr;              // 메모리 해제

// 배열 동적 할당
int size = 5;
int *arr = new int[size];

for (int i = 0; i < size; i++) {
    arr[i] = i * 10;
}

for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}
cout << endl;

delete[] arr;  // 배열 메모리 해제
```

---

## 구조체와 클래스

### 구조체 (struct)

```cpp
// 구조체 정의
struct Student {
    string name;
    int age;
    double gpa;
};

int main() {
    // 구조체 변수 선언 및 초기화
    Student s1;
    s1.name = "홍길동";
    s1.age = 20;
    s1.gpa = 3.8;
    
    // 초기화 리스트 사용
    Student s2 = {"김철수", 22, 4.0};
    
    cout << s1.name << ", " << s1.age << "세, GPA: " << s1.gpa << endl;
    
    // 구조체 배열
    Student students[3] = {
        {"학생1", 20, 3.5},
        {"학생2", 21, 3.8},
        {"학생3", 22, 4.0}
    };
    
    return 0;
}
```

### 클래스 (class)

```cpp
class Rectangle {
private:
    double width;
    double height;

public:
    // 생성자
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    
    // 기본 생성자
    Rectangle() {
        width = 0;
        height = 0;
    }
    
    // 멤버 함수
    double getArea() {
        return width * height;
    }
    
    double getPerimeter() {
        return 2 * (width + height);
    }
    
    // Getter
    double getWidth() {
        return width;
    }
    
    // Setter
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        }
    }
};

int main() {
    Rectangle rect1(5.0, 3.0);
    
    cout << "넓이: " << rect1.getArea() << endl;        // 15
    cout << "둘레: " << rect1.getPerimeter() << endl;   // 16
    
    rect1.setWidth(10.0);
    cout << "새 넓이: " << rect1.getArea() << endl;     // 30
    
    return 0;
}
```

### 클래스 고급 기능

```cpp
class BankAccount {
private:
    string owner;
    double balance;
    
public:
    // 생성자
    BankAccount(string name, double initial) : owner(name), balance(initial) {}
    
    // 입금
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << "원 입금되었습니다." << endl;
        }
    }
    
    // 출금
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << "원 출금되었습니다." << endl;
            return true;
        }
        cout << "잔액이 부족합니다." << endl;
        return false;
    }
    
    // 잔액 조회
    double getBalance() {
        return balance;
    }
    
    // 계좌 정보 출력
    void printInfo() {
        cout << "예금주: " << owner << ", 잔액: " << balance << "원" << endl;
    }
};

int main() {
    BankAccount account("홍길동", 10000);
    
    account.printInfo();
    account.deposit(5000);
    account.withdraw(3000);
    account.printInfo();
    
    return 0;
}
```

---

## 추가 팁

### #include 주요 헤더

```cpp
#include <iostream>   // 입출력
#include <string>     // 문자열
#include <vector>     // 동적 배열
#include <algorithm>  // 알고리즘 함수
#include <cmath>      // 수학 함수
#include <ctime>      // 시간 관련
#include <fstream>    // 파일 입출력
```

### 유용한 STL 컨테이너

```cpp
#include <vector>
#include <string>

// vector (동적 배열)
vector<int> v;
v.push_back(10);  // 요소 추가
v.push_back(20);
v.push_back(30);

cout << v[0] << endl;     // 10
cout << v.size() << endl; // 3

for (int num : v) {
    cout << num << " ";
}
```

### 주석

```cpp
// 한 줄 주석

/*
   여러 줄
   주석
*/

/**
 * 함수 설명 주석
 * @param x 첫 번째 매개변수
 * @return 계산 결과
 */
```

---

이 가이드는 C++의 기본 문법을 다루고 있습니다. 더 깊이 있는 학습을 위해서는 객체지향 프로그래밍(상속, 다형성, 캡슐화), STL(Standard Template Library), 템플릿, 예외 처리 등을 추가로 공부하시면 좋습니다!
