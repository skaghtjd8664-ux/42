*This project has been created as part of the 42 curriculum by [honam].*

# ft_printf

## Description
**ft_printf** 프로젝트는 C 언어 표준 라이브러리의 `printf` 함수를 직접 재구현하는 과제입니다. 이 프로젝트의 주요 목표는 C 언어의 가변 인자(Variadic arguments) 활용법을 익히고, 서식 지정자를 통한 출력 데이터의 내부 처리 프로세스를 깊이 있게 이해하는 것입니다.

본 구현체는 다음과 같은 서식 지정자(Format Specifiers)를 처리합니다:
* `%c` - 단일 문자 출력
* `%s` - 문자열 출력
* `%p` - `void *` 포인터 주소를 16진수 형태로 출력 (앞에 `0x` 포함)
* `%d` / `%i` - 부호 있는 10진수 정수 출력
* `%u` - 부호 없는 10진수 정수 출력
* `%x` - 16진수 소문자 출력
* `%X` - 16진수 대문자 출력
* `%%` - 퍼센트 문자(`%`) 자체를 출력

---

## Algorithm and Data Structure Justification

### 자료 구조 (Data Structures)
* **가변 인자 (`va_list`)**: `ft_printf`에 몇 개의 인자가 들어올지 알 수 없기 때문에, 표준 라이브러리 `<stdarg.h>`의 매크로(`va_start`, `va_arg`, `va_end`)를 사용했습니다. 이를 통해 파싱된 서식 지정자에 따라 동적으로 인자 타입을 구조화하여 가져올 수 있습니다.

### 알고리즘 (Algorithms)
* **순차 파싱 (Sequential Parsing)**: 입력받은 문자열을 처음부터 끝까지 순서대로 훑어 나갑니다. 일반 문자는 바로 출력하고, `%` 문자를 만나면 그 다음 문자를 읽어 `parse_format` 함수 내의 조건문 분기를 통해 각 타입에 맞는 출력 함수로 분기(Dispatch)합니다.
* **재귀를 이용한 진법 변환 (Recursion for Conversion)**: `%u`, `%x`, `%X` 등 숫자를 출력할 때 별도의 임시 버퍼(배열)를 크게 잡지 않고, 10진수 및 16진수로 나눈 몫을 재귀적으로 호출하여 가장 큰 자릿수부터 자연스럽게 화면에 write되도록 구현했습니다.

---

## Instructions

### 컴파일 방법 (Compilation)
본 프로젝트는 `libftprintf.a`라는 정적 라이브러리 파일로 컴파일됩니다. 터미널에서 다음 명령어를 입력하여 컴파일할 수 있습니다 (저장소 루트에 `Makefile`이 포함되어 있어야 합니다):

---

## Resources

### AI 활용 명시 (AI Usage Description)
본 프로젝트의 문서화 및 코드 최적화 과정에서 AI(대형 언어 모델)를 다음과 같이 제한적으로 활용하였습니다.

* **활용 목적 및 작업 (Tasks)**:
  * 서식 지정자 분기 루프(`parse_format`)의 구조적 가독성을 높이기 위한 코드 리팩토링 가이드라인 자문.
  * 42 서브젝트 규정에 부합하는 `README.md` 필수 구성 요소 누락 여부 검증 및 기술 문서 초안 포맷팅.
  * `ft_printf_hex` 및 `ft_printf_int` 내 작성된 예외 처리 로직의 출력 바이트 수 반환 흐름 검토.
* **프로젝트 적용 부분 (Parts of the project)**:
  * `ft_printf.c` 및 `ft_printf_hex.c` 소스 파일 리뷰 과정에서 데이터 타입 매칭 구조 검증 시 아이디어 도출에 활용되었습니다.
  * 현재 저장소 루트에 제공되는 기술 문서인 `README.md` 구조 설계 및 서식 지정자 요약 레이아웃 작성 전반에 적용되었습니다.

```bash
make