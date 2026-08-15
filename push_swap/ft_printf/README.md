*이 프로젝트는 42 커리큘럼의 일부로 만들어졌습니다 / part of the 42 curriculum by [dosong].*

# ft_printf

## 설명

**ft_printf**는 C 표준 라이브러리의 `printf` 함수를 직접 재구현하는 프로젝트입니다.

이 프로젝트의 목표는 다음과 같습니다:
- 가변인자(`va_list`) 개념을 이해하고 활용한다.
- 형식 문자열을 파싱하여 각 변환자에 맞게 출력하는 로직을 구현한다.
- libft에서 만든 함수들을 실제 프로젝트에 활용한다.

---

## 지침

### 컴파일

```bash
# 라이브러리 빌드
make

# 오브젝트 파일 삭제
make clean

# 오브젝트 파일 + 라이브러리 삭제
make fclean

# 전체 재컴파일
make re
```

### 사용 방법

```bash
# 컴파일 시 libftprintf.a 링크
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

### 사용 예시

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
	printf("\n\n");
	printf("Hello, %s!\n", "world");
    printf("Number: %d\n", 42);
    printf("Hex: %x\n", 255);
    printf("Pointer: %p\n", &main);
    return (0);
}
```

---

## 구현 함수 목록

### 지원 변환자

| 변환자 | 출력 대상 |
|--------|----------|
| `%c` | 문자 (char) |
| `%s` | 문자열 (string) |
| `%p` | 포인터 주소 (16진수, `0x` 접두사 포함) |
| `%d` | 정수 (int) |
| `%i` | 정수 (int) |
| `%u` | 양의 정수 (unsigned int) |
| `%x` | 16진수 소문자 |
| `%X` | 16진수 대문자 |
| `%%` | `%` 문자 출력 |

### 파일 구조

| 파일 | 설명 |
|------|------|
| `ft_printf.c` | 메인 함수 및 형식 문자열 파싱 |
| `ft_check.c`  | 자료형 확인 (`cspdiuxX%`)|
| `ft_printf_x.c` | 16진수 출력 함수 (`%x`, `%X`) |
| `ft_printf_p.c` | 포인터 주소 출력 |
| `ft_putchar_fd.c` | 문자 출력 |
| `ft_putstr_fd.c` | 문자열 출력 |
| `ft_putnbr_fd.c` | 정수 출력 |
| `ft_printf.h` | 헤더 파일 |

---

## 동작 원리

```
ft_printf("Hello %s, %d", "dosong", 20)

1. 'H', 'e', 'l', 'l', 'o', ' ' → 일반 문자 → 그대로 출력
2. '%' 발견 → 다음 문자 확인
3. 's' → va_arg로 문자열 꺼내서 출력 → "dosong"
4. ',' ' ' → 일반 문자 → 그대로 출력
5. '%' 발견 → 다음 문자 확인
6. 'd' → va_arg로 정수 꺼내서 출력 → "20"

반환값: 출력한 총 문자 수
```

---

## 가변인자 (va_list)

`printf`는 인자 개수가 정해져 있지 않아요. 이를 처리하기 위해 가변인자를 사용합니다.

```c
#include <stdarg.h>

int ft_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str); // 가변인자 시작
    // va_arg(args, 타입)으로 하나씩 꺼냄
    va_end(args);           // 가변인자 종료 (필수!)
}
```

| 함수 | 역할 |
|------|------|
| `va_list` | 가변인자를 담는 그릇 |
| `va_start(list, last)` | 가변인자 읽기 시작 |
| `va_arg(list, type)` | 가변인자 하나씩 꺼내기 |
| `va_end(list)` | 가변인자 사용 종료 |

---
## 알고리즘 설계 및 선택 이유 (Algorithm Explanation & Justification)

본 프로젝트는 C 표준 라이브러리의 `printf` 함수를 모방하기 위해 **"단일 루프 스트림 파싱(Single-pass Stream Parsing)"** 알고리즘과 **"중앙 집중식 가변 인자 분기(Centralized Variadic Dispatch)"** 구조를 채택하여 구현했습니다.

### 1. 형식 문자열 파싱 방식 (Format String Parsing)
문자열을 처음부터 끝까지 인덱스 `i`를 이용해 단 한 번만 순회(O(N))하는 방식을 사용합니다.
- 일반 문자를 만나면 즉시 `write`를 통해 표준 출력(stdout)으로 내보내고 출력 바이트 수를 누적합니다.
- 탈출 문자 `%`를 만나면, 루프를 멈추지 않고 즉시 그 다음 인덱스(`i + 1`)의 문자를 확인하는 전방 탐색(Look-ahead)을 수행합니다.
- `%` 뒤의 문자가 유효한 서식 지정자(`cspdiuxX%`)인지 `ft_check` 함수로 검사한 뒤, 일치하면 지정자 처리 함수(`ft_mainprintf`)로 분기합니다.

### 2. 변환자별 가변 인자 처리 방식 (Conversion Handling)
`va_list`, `va_start`, `va_arg`, `va_end` 매크로를 사용하여 타입 안전성을 고려한 가변 인자 추출을 수행합니다. 중앙 분기 함수인 `ft_mainprintf`에서 각 서식 지정자에 매칭되는 적절한 데이터 타입으로 가변 인자를 꺼냅니다.

- **`%c`, `%s`, `%%`**: 문자 및 문자열을 출력하며, 부호 있는 `int` 및 `char *` 경로로 데이터를 안전하게 전달합니다.
- **`%d`, `%i`**: 부호 있는 정수 출력을 처리하며, `long long` 범위를 수용할 수 있는 재귀 함수를 통해 자릿수를 나누어 출력합니다.
- **`%u`**: 부호 없는 10진수 출력을 위해 **전용 unsigned 함수(`ft_printf_u`)를 독립적으로 분리**하여, 큰 양수 데이터 입력 시 부호 비트 오류(음수 출력 현상)가 발생하는 오버플로우 문제를 구조적으로 차단했습니다.
- **`%x`, `%X`, `%p`**: 16진수 및 포인터 주소 출력을 처리하며, 주소값의 경우 `unsigned long long`으로 캐스팅하여 하드웨어 아키텍처에 독립적인 메모리 주소 파싱을 보장합니다.

### 3. 해당 알고리즘과 구조를 선택한 이유 (Justification)
- **가독성과 확장성 (Extensibility):** 서브젝트 가이드라인(Chapter I)에서 요구하는 *'well-structured and extensible code'* [cite: 15] 지침을 따랐습니다. 문자열 파싱부와 가변 인자 처리부, 그리고 각 서식 지정자별 유틸 함수들을 명확히 분리함으로써, 추후 보너스 플래그(`-`, `0`, `.`, `#`, `+`, `공백`)를 추가하더라도 메인 루프를 수정하지 않고 유틸 함수 및 파싱 조건만 확장하면 되도록 설계했습니다.
- **메모리 안정성 (Memory Efficiency):** 동적 할당(`malloc`)을 최소화하고, 내부 스택 메모리와 재귀 호출을 이용해 출력을 처리함으로써 버퍼 관리의 복잡성을 줄이고 42 과제에서 가장 치명적인 **메모리 누수(Memory Leak) 가능성을 원천적으로 배제**했습니다.
- **엄격한 예외 처리 (Robust Error Handling):** `%` 뒤에 처리할 수 없는 잘못된 서식 지정자가 들어오는 '정의되지 않은 동작(Undefined Behavior)'이 발생할 경우, 표준 출력 스트림의 오염을 막기 위해 가변 인자 매크로를 안전하게 종료(`va_end`)하고 즉시 에러 시그널(`-1`)을 반환하도록 설계하여 함수의 견고함을 높였습니다.

## 자원

### 참고 문서
- [printf 공식 문서 - cppreference.com](https://en.cppreference.com/w/c/io/fprintf)
- [va_list 공식 문서 - cppreference.com](https://en.cppreference.com/w/c/variadic)

### AI 사용 안내
이 프로젝트에서 AI(Claude)는 다음 용도로 활용되었습니다:
- 가변인자(`va_list`, `va_arg` 등) 동작 방식 개념 설명
- 각 변환자별 함수 동작 방식 이해
- README.md 작성 

실제 코드 구현은 모두 직접 작성하였습니다.