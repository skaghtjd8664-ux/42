*This project has been created as part of the 42 curriculum by <dosong, honam>.*
 
# push_swap
  
## 설명 (Description)
 
`push_swap`은 **제약 조건 하에서의 정렬**을 다루는 알고리즘 과제입니다.
중복 없는 무작위 정수 목록이 스택 `a`에 주어지고, 스택 `b`는 비어 있는 상태에서
시작합니다. 사용할 수 있는 연산은 `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr` 로 제한됩니다. 목표는 이 연산들을 이용해
**최소한의 연산 횟수**로 스택 `a`를 오름차순으로 정렬하는 시퀀스를
표준 출력에 출력하는 것입니다.
 
과제 요구 사항:
 
- 어떤 연산도 수행하기 **전에** 입력의 **무질서도(disorder)** 를 계산해야 합니다
  (0% = 이미 정렬됨, 100% = 최악의 순서).
- **네 가지 서로 다른 정렬 전략**을 구현해야 하며, 각 전략은
  *push_swap 연산 모델* 상에서 서로 다른 복잡도 클래스를 목표로 합니다
  (여기서 복잡도는 배열 기반 알고리즘의 이론적 복잡도가 아니라,
  **생성된 push_swap 연산의 개수**로 측정됩니다):
  - `--simple` → O(n^2)
  - `--medium` → O(n√n)
  - `--complex` → O(n log n)
  - `--adaptive` (기본값) → 측정된 disorder 값에 따라 위 세 방식 중
    내부적으로 적절한 방식을 선택
- 선택적으로 `--bench` 모드를 통해 disorder, 선택된 전략, 총 연산 수,
  연산 종류별 세부 카운트를 표준 에러(stderr)로 출력해야 합니다.
 
## 사용 방법 (Instructions)
 
### 컴파일
 
```bash
make
make clean
make fclean
make re
```
 
`Makefile`은 `cc -Wall -Wextra -Werror` 플래그로 컴파일하며, 불필요한
재링크를 하지 않습니다. 필수 규칙인 `$(NAME)`, `all`, `clean`, `fclean`,
`re`를 포함합니다.
 
### 실행
 
```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <정수 목록>
```
 
- 정수 목록은 공백으로 구분된 여러 인자로 전달하거나, 하나의 문자열로
  묶어서(`"2 1 3 6 5 8"`) 전달할 수 있습니다.
- 전략 플래그를 지정하지 않으면 기본값인 `--adaptive`가 사용됩니다.
- 인자가 없으면 아무것도 출력하지 않고 프롬프트로 되돌아갑니다.
- 잘못된 입력(정수가 아님, 중복값, 범위 초과 등)은 표준 에러에 `Error`를
  출력합니다.
예시:
 
```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
./push_swap --bench 2 1 3 6 5 8 2> bench.txt
```
 
## 알고리즘 (Algorithms)
 
### 무질서도(disorder) 지표
 
`sort_utils.c`의 `compute_disorder()`는 어떤 연산도 수행하기 전, 스택 `a`
내에서 역전된 쌍(더 큰 값이 더 작은 값보다 앞에 오는 쌍)의 개수를 전체
쌍의 개수로 나눈 값을 한 번 계산합니다:
 
```
disorder = (i < j 이면서 a[i] > a[j]인 쌍의 개수) / (n * (n - 1) / 2)
```
 
- `disorder == 0` → 이미 정렬됨
- `disorder == 100` → 역순 정렬(최악의 경우)
이 계산 자체는 C 코드 상 O(n^2)이지만, 이는 정렬을 시작하기 *전*에 한 번
수행하는 "측정" 단계이므로 push_swap 연산 횟수에는 포함되지 않습니다.
 
### 1. Simple 전략 — O(n^2) — `--simple` (`sort_simple.c`)
 
**삽입 정렬(insertion sort) 변형**입니다:
 
1. 크기 3 이하는 하드코딩되어 있습니다 (`sort_three`는 3개 원소가 가질 수
   있는 6가지 순열 경우를 모두 나열하여 최대 2번의 연산으로 처리합니다).
2. 크기가 더 큰 경우, 맨 위 3개를 제외한 나머지를 모두 `b`로 push하고
   (`while (a->size > 3) pb(a, b)`), 남은 3개를 `sort_three`로 정렬합니다.
3. 이후 `b`에서 한 번에 하나씩 다시 삽입합니다: `find_insert_pos`가 `a`를
   선형 탐색하여 `b`의 top 값이 들어갈 위치를 찾고, `rotate_a_to_pos`가
   (더 짧은 방향인 `ra` 또는 `rra`를 선택하여) 그 위치를 top으로 회전시킨
   뒤 `pa`로 삽입합니다.
4. 마지막으로 최솟값을 top으로 회전시켜, 원형 스택이 head부터 오름차순으로
   읽히도록 맞춥니다.
`n`번의 재삽입마다 O(n)의 탐색(`find_insert_pos`)과 최악의 경우 O(n)의
회전이 필요하므로, 전체적으로 **O(n^2)** 개의 연산이 생성됩니다. 이는
고전적인 삽입 정렬의 연산 수와 일치합니다.
 
### 2. Medium 전략 — O(n√n) — `--medium` (`sort_medium.c`)
 
**청크 기반(Chunk-based) 분할 전략**입니다:
 
1. `get_range(size)`는 청크 폭을 대략 `1.4 * sqrt(size) + 1`로 정합니다.
2. `push_by_hourglass`는 스택 `a`를 순회하며, 각 원소에 대해 `a`와 `b`를
   합친 순위(rank)를 계산합니다(`get_rank`). 순위가 현재 채워진 범위
   안에 들면 `b`로 push하고 상대적 순서를 유지하도록 `b`를 회전시키며
   (`rb`), 다음 청크 범위 안에 들면 회전 없이 `b`로 push하고, 그 외의
   경우 `a`를 회전(`ra`)시켜 다음 후보를 앞으로 가져옵니다. 이렇게 하면
   원소들이 대략 `sqrt(n)` 크기의 청크 단위로 `b`에 버킷팅됩니다.
3. `push_back_by_max`는 `b`가 빌 때까지 현재 최댓값 위치로 `b`를 회전시킨
   뒤(`find_max_pos` + `rotate_b_to_pos`) `pa`로 `a`에 되돌리며, 이 과정을
   통해 `a`가 오름차순으로 재구성됩니다.
원소들이 약 `sqrt(n)`개의 청크 단위로 처리되고, 원소당 O(sqrt(n))의
순위/회전 비용이 들기 때문에, 전체적으로 **O(n·√n)** 개의 연산이
생성됩니다.
 
### 3. Complex 전략 — O(n log n) — `--complex` (`sort_complex.c`)
 
**LSD(Least Significant Digit) radix sort 변형**입니다:
 
1. `set_index`가 먼저 전체 비교를 한 차례 수행하여 각 노드에 최종 정렬
   순서상의 순위(rank, 0부터 시작)를 부여합니다. 이는 C 코드 상의 사전
   계산일 뿐이며, 그 자체로는 push_swap 연산을 생성하지 않습니다.
2. `get_max_bits(size)`는 모든 순위를 표현하는 데 필요한 비트 수, 즉
   `⌈log2(size)⌉`를 계산합니다.
3. 각 비트 위치마다(`execute_radix_pass`) `a`의 모든 원소를 한 번씩
   검사하여, 해당 비트가 `0`이면 `b`로 push하고(`pb`), 그렇지 않으면
   `a`를 회전(`ra`)시켜 뒤로 순환시킵니다. 한 패스가 끝나면 `b`에 쌓인
   모든 원소를 다시 `a`로 push하는데(`pa`), 이는 다음(더 상위) 비트를
   처리할 때를 위해 상대적 순서를 유지하는 표준 LSD radix sort의 불변
   조건입니다.
`⌈log2(n)⌉`번의 패스마다 O(n)개의 연산이 생성되므로, 전체 연산 수는
**O(n log n)** 입니다.
 
### 4. Adaptive 전략 — `--adaptive` (기본값, `push_swap.c`)
 
`sort_stack()`은 disorder를 한 번 측정한 뒤, 위 세 전략 중 하나로 곧바로
분기합니다:
 
| Disorder 범위 | 구간 | 호출되는 전략 | 목표 복잡도 |
|---|---|---|---|
| `< 20` | 낮음(Low) | `sort_simple` | O(n^2) |
| `20 – 49` | 중간(Medium) | `sort_medium` | O(n√n) |
| `≥ 50` | 높음(High) | `sort_complex` | O(n log n) |
 
이 두 임계값(`0.2`, `0.5`)은 자체 벤치마킹을 통해 도출한 경험적 값이
아니라, 과제 스펙(VI.3.3)의 구간표에서 직접 명시한 값입니다. 즉 adaptive
알고리즘의 역할은 각 disorder 구간에 맞는 전략으로 라우팅하는 것이며,
각 전략은 해당 구간에서 요구되는 복잡도 상한을 개별적으로 만족합니다.
 
> **참고:** `size <= 5`인 경우 `sort_medium`과 `sort_complex` 모두
> `sort_simple`로 대체됩니다. 이 정도 크기에서는 청크 분할이나
> radix 비트 패스의 고정 오버헤드가 이득이 되지 않으며, `sort_simple`의
> 2개/3개 원소에 대한 하드코딩된 처리가 이미 최적이기 때문입니다.

## 참고 자료 (Resources)

AI Tool Assistance: 본 README.md 문서 작성 및 구조화 과정에서 AI Assistant의 도움을 받았습니다.