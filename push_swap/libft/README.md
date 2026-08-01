# libft

*이 프로젝트는 42 커리큘럼의 일부로 만들어졌습니다 / part of the 42 curriculum by 송도훈, dosong.*

---

## 설명

**libft**는 C 표준 라이브러리 함수들을 직접 재구현하는 프로젝트입니다.

이 프로젝트의 목표는 다음과 같습니다:
- C 언어의 기초를 깊이 이해한다.
- 문자열, 메모리, 연결리스트 등 핵심 자료구조와 알고리즘을 직접 구현한다.
- 이후 42 과제에서 재사용 가능한 개인 라이브러리를 구축한다.

---

## 지침

### 컴파일

```bash
# 필수 함수만 컴파일
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
# 컴파일 시 libft.a 링크
cc -Wall -Wextra -Werror your_file.c libft.a -o your_program
```

---

## 함수 목록

### Part 1 - 표준 라이브러리 함수 재구현

| 함수 | 설명 |
|------|------|
| `ft_isalpha` | 알파벳 문자인지 확인 |
| `ft_isdigit` | 숫자 문자인지 확인 |
| `ft_isalnum` | 알파벳 또는 숫자인지 확인 |
| `ft_isascii` | ASCII 문자인지 확인 |
| `ft_isprint` | 출력 가능한 문자인지 확인 |
| `ft_toupper` | 소문자를 대문자로 변환 |
| `ft_tolower` | 대문자를 소문자로 변환 |
| `ft_strlen` | 문자열 길이 반환 |
| `ft_memset` | 메모리 블록을 특정 값으로 채움 |
| `ft_bzero` | 메모리 블록을 0으로 초기화 |
| `ft_memcpy` | 메모리 블록 복사 |
| `ft_memmove` | 겹치는 영역도 안전하게 메모리 복사 |
| `ft_strlcpy` | 안전한 문자열 복사 |
| `ft_strlcat` | 안전한 문자열 이어붙이기 |
| `ft_strchr` | 문자열에서 문자 앞에서부터 탐색 |
| `ft_strrchr` | 문자열에서 문자 뒤에서부터 탐색 |
| `ft_strncmp` | 두 문자열을 n바이트만큼 비교 |
| `ft_memchr` | 메모리에서 문자 탐색 |
| `ft_memcmp` | 두 메모리 블록 비교 |
| `ft_strnstr` | 문자열 안에서 부분 문자열 탐색 |`
| `ft_atoi` | 문자열을 정수로 변환 |
| `ft_calloc` | 0으로 초기화된 메모리 할당 |
| `ft_strdup` | 문자열 복사본을 동적 할당하여 반환 |

### Part 2 - 추가 함수

| 함수 | 설명 |
|------|------|
| `ft_substr` | 문자열의 부분 문자열 반환 |
| `ft_strjoin` | 두 문자열을 이어붙인 새 문자열 반환 |
| `ft_strtrim` | 문자열 앞뒤의 특정 문자 제거 |
| `ft_split` | 구분자로 문자열을 나눠 배열로 반환 |
| `ft_itoa` | 정수를 문자열로 변환 |
| `ft_strmapi` | 문자열 각 문자에 함수를 적용한 새 문자열 반환 |
| `ft_striteri` | 문자열 각 문자에 함수를 적용하여 원본 수정 |
| `ft_putchar_fd` | 파일 디스크립터에 문자 출력 |
| `ft_putstr_fd` | 파일 디스크립터에 문자열 출력 |
| `ft_putendl_fd` | 파일 디스크립터에 문자열 + 개행 출력 |
| `ft_putnbr_fd` | 파일 디스크립터에 정수 출력 |

### Part 3 - 연결리스트 함수

| 함수 | 설명 |
|------|------|
| `ft_lstnew` | 새 노드 생성 |
| `ft_lstadd_front` | 리스트 앞에 노드 추가 |
| `ft_lstadd_back` | 리스트 뒤에 노드 추가 |
| `ft_lstsize` | 리스트 노드 개수 반환 |
| `ft_lstlast` | 마지막 노드 반환 |
| `ft_lstdelone` | 노드 하나 삭제 |
| `ft_lstclear` | 리스트 전체 삭제 |
| `ft_lstiter` | 리스트 각 노드에 함수 적용 |
| `ft_lstmap` | 리스트 각 노드에 함수를 적용한 새 리스트 반환 |

---

## 자원

### AI 사용 안내
이 프로젝트에서 AI(Claude)는 다음 용도로 활용되었습니다:
- 함수의 동작 방식과 개념 설명
- 엣지 케이스(예: `INT_MIN`, 빈 문자열, NULL 입력) 발생 원인 이해
- 코드 직접 작성이 아닌, 스스로 구현할 수 있도록 방향 제시

실제 코드 구현은 모두 직접 작성하였습니다.