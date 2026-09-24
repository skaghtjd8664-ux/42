# Data Quest
## 파이썬 컬렉션 마스터하기

**요약:** 데이터 엔지니어가 되어 디지털 세계를 여행합니다! 게임 데이터를 만들고 처리하면서 파이썬의 강력한 자료구조들을 마스터합니다.

**버전:** 3.0

---

## 목차

1. [머리말](#머리말)
2. [AI 사용 지침](#ai-사용-지침)
3. [소개](#소개)
4. [공통 지침](#공통-지침)
5. [실습 0: 명령어 퀘스트](#실습-0-명령어-퀘스트)
6. [실습 1: 점수 분석기](#실습-1-점수-분석기)
7. [실습 2: 위치 추적기](#실습-2-위치-추적기)
8. [실습 3: 업적 헌터](#실습-3-업적-헌터)
9. [실습 4: 인벤토리 마스터](#실습-4-인벤토리-마스터)
10. [실습 5: 스트림 마법사](#실습-5-스트림-마법사)
11. [실습 6: 데이터 연금술사](#실습-6-데이터-연금술사)
12. [제출 방법](#제출-방법)

---

## 머리말

트위터(Twitter)의 초기 성장기에, 확장(scaling)은 그저 서버를 더 추가하는 문제가 아니었습니다. 대규모에서 갑자기 중요해지는 사소한 결정들을 바로잡는 일이었죠. 자주 나타났던 패턴 하나는, 리스트나 배열 같은 단순한 순차 자료구조를 사용하는 것이었습니다 — 트래픽이 적을 땐 쉽고 완벽하게 잘 작동했으니까요. 그러다 사용자 기반이 폭발적으로 늘어났습니다. "이게 이미 존재하는가?" 같은, 한때는 마이크로초 단위로 끝나던 연산이 초당 수백만 번 실행되기 시작하면서, 조용히 성능 병목으로 변해갔습니다. 논리적으로 잘못된 건 아무것도 없었습니다 — 코드는 깔끔하고 정확했지만, 잘못된 컨테이너가 선형 시간을 실제 서비스 장애로 만들어버린 것이었죠. 해시 기반 구조로 교체하는 것만으로 문제가 거의 마법처럼 해결되곤 했습니다. 대규모에서는 여러분의 자료구조가 곧 알고리즘이라는 걸 일깨워주는 좋은 사례입니다.

---

## AI 사용 지침

### 핵심 메시지

- 반복적이거나 지루한 작업을 줄이는 데 AI를 활용하세요.
- 코딩과 비(非)코딩 모두에서 향후 커리어에 도움이 될 프롬프트 작성 능력을 키우세요.
- AI 시스템의 작동 방식을 배워 흔한 위험, 편향, 윤리적 문제를 더 잘 예측하고 피하세요.
- 동료들과 함께 작업하며 기술적 역량과 대인 역량을 계속 키우세요.
- 완전히 이해하고 책임질 수 있는 AI 생성 콘텐츠만 사용하세요.

### 학습자 규칙

- AI 도구를 탐색하고 작동 원리를 이해하는 시간을 가지세요.
- 프롬프트를 작성하기 전에 문제를 먼저 곰곰이 생각해 보세요.
- AI가 생성한 모든 것을 체계적으로 확인, 검토, 질문, 테스트하는 습관을 기르세요.
- 항상 동료 검토를 구하세요.

### 좋은 예 / 나쁜 예

**✓ 좋은 예:** AI를 활용해 파서 설계를 돕게 합니다. 동료와 함께 로직을 짚어보고, 버그를 발견하고 함께 다시 작성합니다.

**✗ 나쁜 예:** Copilot이 핵심 코드를 생성하게 두고, 어떻게 동작하는지 설명하지 못해 평가에서 낙제합니다.

---

## 소개

디지털 세계로 다시 돌아오신 것을 환영합니다, 데이터 엔지니어!

파이썬 기초를 다지는 여정이 여러분을 잘 준비시켜줬습니다. 디지털 정원을 움직이는 기본 문법을 마스터했고, 실제 시스템을 모델링하는 견고한 클래스 계층 구조를 만들었으며, 우아한 예외 처리로 예상치 못한 상황을 다루는 법도 배웠습니다. 이제 데이터 엔지니어링의 핵심, 즉 게이밍 환경에서 탐구할 **컬렉션(collections)과 자료구조**를 다룰 준비가 되었습니다.

이렇게 상상해보세요: 1980년, 팩맨(Pac-Man)의 게임 상태 전체 — 모든 점, 유령 위치, 점수 — 가 단 16KB의 RAM에 들어갔습니다. 프로그래머들은 효율성의 마법사여야 했죠! 그들은 데이터를 정리하는 것이 단순히 메모리를 절약하는 문제가 아니라, 게임의 마법을 여는 열쇠라는 걸 발견했습니다. 시간을 빨리 감아 오늘날로 와보면: 포트나이트(Fortnite)는 천만 명이 넘는 동시 접속 플레이어를 처리하며, 각자가 초당 수천 개의 데이터 포인트를 생성합니다. 같은 원리, 더 커진 놀이터죠!

파이썬의 컬렉션 타입은 다양한 용도를 위해 설계되었고, 각각 고유한 특징을 가집니다: **리스트**(순서 있음, 인덱싱 가능, 확장 가능), **튜플**(순서 있음, 불변, 해시 가능), **집합**(고유한 요소들의 순서 없는 모음), **딕셔너리**(키-값 쌍).

여기에 더해 **제너레이터**와 **컴프리헨션**이 강력한 문법과 동작 방식을 얹어줍니다.

이번 여정에서는 게임 분석 플랫폼을 뒷받침하는 구성 요소들을 만들게 됩니다. 각 실습은 새로운 자료구조를 열어주며, 끝에 다다르면 여러분은 데이터 엔지니어처럼 파이썬 컬렉션을 다루고 있을 것입니다!

> ℹ️ 이 프로젝트부터, 그리고 실습에서 정식으로 소개될 때마다, 여러분은 새로운 파이썬 자료구조와 그에 딸린 모든 클래스 메서드를 사용할 수 있습니다.

---

## 공통 지침

### 일반 규칙

- 프로젝트는 **Python 3.10 이상**으로 작성해야 합니다.
- **flake8** 코딩 표준을 준수해야 합니다.
- 모든 함수와 메서드는 타입 힌트를 포함해야 합니다; `mypy`로 확인하세요.
- 함수는 크래시를 방지하기 위해 예외를 우아하게 처리해야 합니다.
- 이 프로젝트에서는 커맨드라인 매개변수 접근이 필요합니다. `import` 메커니즘을 통해 **sys** 모듈을 사용하세요. import는 이후 프로젝트에서 더 자세히 다룹니다.
- 파일 입출력(File I/O) 연산은 허용되지 않습니다. 모든 데이터는 메모리 안에서 처리하거나 커맨드라인 인자를 통해 처리해야 합니다.
- 컬렉션 사용 패턴을 명확히 보여주는 데 집중하세요.
- 각 자료구조에 대해 기본 연산과 고급 기법을 둘 다 보여주세요.

> ℹ️ 다음 표준 타입은 관련된 모든 메서드 및 생성자와 함께 사용이 허용됩니다: `str`, `int`, `float`.

### 추가 안내사항

- 지정된 Git 저장소에 작업물을 제출하세요.
- 이 저장소 안의 내용만 평가됩니다.

---

## 실습 0: 명령어 퀘스트

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_command_quest` |
| 디렉토리 | `ex0/` |
| 제출 파일 | `ft_command_quest.py` |
| 허용 함수 | `import sys`, `sys.argv`, `len()`, `print()` |

데이터 모험가님, 환영합니다! 모든 위대한 여정은 도구를 이해하는 것에서 시작됩니다. 디지털 세계에서 프로그램은 외부로부터 지시를 받아야 합니다. 첫 임무는 프로그램이 사용자로부터 어떻게 메시지를 받는지 알아내는 것입니다!

이제 **리스트**를 소개할 시간입니다. 직접 리스트를 만들기 전에, 이미 존재하는 리스트 하나를 다뤄봅시다: `sys` 모듈을 통해 사용 가능한 커맨드라인 매개변수입니다. 그 구조는 C에 있던 것과 비슷합니다 — 문자열의 배열이죠. 리스트 요소에 접근하고 조작하는 법을 탐구해보세요.

커맨드라인 매개변수로 받은 데이터를 표시하는 간단한 스크립트를 만드세요. 아래 예시를 따라 하세요.

**예시:**
```
$> python3 ft_command_quest.py
=== Command Quest ===
Program name: ft_command_quest.py
No arguments provided!
Total arguments: 1

$> python3 ft_command_quest.py hello world 42
=== Command Quest ===
Program name: ft_command_quest.py
Arguments received: 3
Argument 1: hello
Argument 2: world
Argument 3: 42
Total arguments: 4

$> python3 ft_command_quest.py "Data Quest"
=== Command Quest ===
Program name: ft_command_quest.py
Arguments received: 1
Argument 1: Data Quest
Total arguments: 2
```

> 💡 스크립트 맨 위에서 그냥 `import sys`를 쓰면 `sys.argv` 리스트에 접근할 수 있습니다.
>
> ℹ️ 프로그램 이름을 인자들과 함께 다시 출력하지 않는 방법은 여러 가지가 있습니다. 평가 중 대안적인 해결 방법을 논의할 준비를 하세요.

---

## 실습 1: 점수 분석기

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_score_analytics` |
| 디렉토리 | `ex1/` |
| 제출 파일 | `ft_score_analytics.py` |
| 허용 함수 | `import sys`, `sys.argv`, `len()`, `sum()`, `max()`, `min()`, `print()` |

**임무 브리핑:** 명령어 소통을 마스터했으니, 이제 데이터 정리를 할 시간입니다! 프로그램에 명령을 보내는 사용자는 사람이고, 실수를 할 수 있으니까요.

이 실습은 점수를 저장하기 위한 **리스트**와, 잘못된 입력(예: 사용자가 숫자가 아닌 값을 제공했을 때)을 우아하게 처리하기 위한 **`try`/`except`** 블록 사용을 요구합니다.

게임 점수를 커맨드라인 매개변수로 받게 됩니다. 다음을 수행해야 합니다:

- 커맨드라인 인자를 처리
- 다양한 잘못된 케이스(인자 없음, 숫자가 아닌 값)를 적절한 메시지로 처리
- 점수를 저장하고 정리할 새 **리스트** 생성
- 게임 플레이어를 기쁘게 할 기본 통계 계산 (개수, 합계, 평균, 최고점, 최저점, 범위)
- 게임 친구들에게 자랑할 만큼 멋진 출력 만들기 (예시를 따라 해도 됩니다)
- 유효한 입력과 잘못된 입력이 커맨드라인에 함께 제공된 경우, 잘못된 것들은 버리고 남은 유효한 입력으로 진행 (유효한 게 하나도 안 남으면 예외)

**예시:**
```
$> python3 ft_score_analytics.py 1500 2300 1800 2100 1950
=== Player Score Analytics ===
Scores processed: [1500, 2300, 1800, 2100, 1950]
Total players: 5
Total score: 9650
Average score: 1930.0
High score: 2300
Low score: 1500
Score range: 800

$> python3 ft_score_analytics.py
=== Player Score Analytics ===
No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...

$> python3 ft_score_analytics.py ab ac
=== Player Score Analytics ===
Invalid parameter: 'ab'
Invalid parameter: 'ac'
No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...
```

---

## 실습 2: 위치 추적기

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_coordinate_system` |
| 디렉토리 | `ex2/` |
| 제출 파일 | `ft_coordinate_system.py` |
| 허용 함수 | `import math`, `math.sqrt()`, `input()`, `round()`, `print()` |

**레벨 업!** 3D 좌표를 마스터할 시간입니다! 3D 세계의 특정 위치로 순간이동하는 게임을 해보신 적 있나요? 혹은 3D 공간 안의 두 점 사이 거리를 구해야 했던 적은요? 바로 그걸 만들어볼 겁니다!

이 실습은 3D 좌표(x, y, z)를 저장하기 위한 **튜플** 사용을 요구합니다.

먼저, `get_player_pos()` 함수를 작성하세요. 이 함수는:
- 사용자에게 `x,y,z` 형식으로 새 플레이어 좌표를 요청
- 잘못된 입력을 처리
- 유효한 좌표 세트가 주어질 때까지 재시도
- 플레이어의 현재 3D 좌표를 담은 **튜플**을 반환

그 다음 코드는:
- 첫 번째 좌표 세트를 받음
- 튜플을 표시하고 각 좌표를 따로 표시
- 3D 중심(0, 0, 0)까지의 거리를 계산 (아래 참고)
- 새 좌표 세트를 받음
- 두 번째 좌표 세트와 첫 번째 좌표 세트 사이의 거리를 계산

**거리 공식:** 3D 상의 두 점 사이 거리를 계산하기 위해, 유클리드 거리 공식을 사용합니다: √((x₂-x₁)² + (y₂-y₁)² + (z₂-z₁)²)

점 (x1, y1, z1)과 (x2, y2, z2)에 대해, 거리는 `math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)`입니다. 이는 피타고라스 정리를 3차원으로 확장한 것뿐입니다!

**예시:**
```
$> python3 ft_coordinate_system.py
=== Game Coordinate System ===

Get a first set of coordinates
Enter new coordinates as floats in format 'x,y,z': hello world
Invalid syntax
Enter new coordinates as floats in format 'x,y,z': 1.0 , 2.5, 3.0
Got a first tuple: (1.0, 2.5, 3.0)
It includes: X=1.0, Y=2.5, Z=3.0
Distance to center: 4.0311

Get a second set of coordinates
Enter new coordinates as floats in format 'x,y,z': 4,abc,5
Error on parameter 'abc': could not convert string to float: 'abc'
Enter new coordinates as floats in format 'x,y,z': 4,5,6
Distance between the 2 sets of coordinates: 4.9244
```

> 💡 스크립트 맨 위에서 그냥 `import math`를 써서 `math.sqrt()`를 사용하세요.
>
> ℹ️ 튜플은 돌에 새겨진 데이터와 같습니다. 한 번 만들어지면 바뀌지 않습니다.

---

## 실습 3: 업적 헌터

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_achievement_tracker` |
| 디렉토리 | `ex3/` |
| 제출 파일 | `ft_achievement_tracker.py` |
| 허용 함수 | `len()`, `print()`, `import random`, `random.*`, `set()`, `set.union()`, `set.intersection()`, `set.difference()` |

**업적 달성!** 최고의 업적 시스템을 만들 시간입니다! 그 희귀한 업적을 언락할 때 얼마나 뿌듯한지 아시죠? 이제 그 모든 걸 추적하는 시스템을 만들게 됩니다!

이 실습은 고유한 업적을 저장하기 위한 **집합(set)**과, 플레이어들의 업적 모음을 분석하기 위한 연산(합집합, 교집합, 차집합) 수행을 요구합니다.

큰 고정 업적 목록을 사용해 플레이어에게 무작위로 집합을 배정하는 `gen_player_achievements()` 함수를 만드세요. 무작위 개수의 업적을 정하고, 목록에서 그 개수만큼 업적을 골라 **집합**을 만들고 반환하세요.

그 다음 코드는:
- 최소 4명의 서로 다른 플레이어에 대한 업적 집합 생성
- 모든 플레이어 사이의 고유한 업적을 추적
- 모든 플레이어가 공유하는 업적 찾기
- 각 플레이어별로, 다른 아무도 갖지 않은 업적 찾아내기
- 각 플레이어별로, 모든 업적을 다 갖기 위해 부족한 업적 나열하기

**예시:**
```
$> python3 ft_achievement_tracker.py
=== Achievement Tracker System ===

Player Alice: {'Crafting Genius', 'World Savior', 'Master Explorer', 'Collector Supreme', 'Untouchable', 'Boss Slayer'}
Player Bob: {'Crafting Genius', 'Strategist', 'World Savior', 'Master Explorer', 'Unstoppable', 'Collector Supreme', 'Untouchable'}
Player Charlie: {'Strategist', 'Speed Runner', 'Survivor', 'Master Explorer', 'Treasure Hunter', 'First Steps', 'Collector Supreme', 'Untouchable', 'Sharp Mind'}
Player Dylan: {'Strategist', 'Speed Runner', 'Unstoppable', 'Untouchable', 'Boss Slayer'}

All distinct achievements: {...전체 업적 목록...}

Common achievements: {'Untouchable'}

Only Alice has: set()
Only Bob has: set()
Only Charlie has: {'Survivor', 'Treasure Hunter', 'First Steps', 'Sharp Mind'}
Only Dylan has: set()

Alice is missing: {...}
Bob is missing: {...}
Charlie is missing: {...}
Dylan is missing: {...}
```

> 💡 전체 업적 개수와 각 플레이어가 몇 개씩 가져갈지를 조정해서, 요청된 모든 집합이 대체로 비어있지 않도록 만드세요. 그런데, 파이썬은 빈 집합을 어떻게 출력하며, 왜 그럴까요?

---

## 실습 4: 인벤토리 마스터

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_inventory_system` |
| 디렉토리 | `ex4/` |
| 제출 파일 | `ft_inventory_system.py` |
| 허용 함수 | `import sys`, `sys.argv`, `len()`, `print()`, `sum()`, `list()`, `round()`, `dict.keys()`, `dict.values()`, `dict.update()` |

**루팅 타임!** RPG에서 인벤토리를 정리하던 것 기억하시나요? 그 전설의 검을 가지고 있는지 확인하던 것도요? 궁극의 인벤토리 시스템을 만들 시간입니다!

이 실습은 인벤토리 데이터를 저장하기 위한 **딕셔너리** 사용을 요구합니다.

코드는 먼저 커맨드라인 매개변수를 파싱해서 인벤토리 시스템을 채웁니다. 각 매개변수는 `<아이템이름>:<수량>` 형식을 따라야 합니다. 잘못된 매개변수(잘못된 문법, 중복된 매개변수)는 에러 메시지와 함께 버리고, 유효한 것들만 딕셔너리에 넣으세요. 딕셔너리 안의 `<수량>` 값은 나중에 계산할 수 있도록 `int`로 저장되어야 합니다.

이제 인벤토리에 대해 연산할 시간입니다:

- 인벤토리 표시
- 인벤토리에 포함된 모든 아이템의 목록 생성 및 표시
- 인벤토리 안 모든 아이템의 총 수량 계산 및 출력
- 각 아이템이 인벤토리에서 차지하는 수량 비율(%) 표시
- 가장 많고 가장 적은 아이템 보고 (동률일 경우 커맨드라인에서 먼저 나온 것 선택)
- 마지막으로, 인벤토리에 새 아이템을 추가하고 다시 표시

**예시:**
```
$> python3 ft_inventory_system.py sword:1 potion:5 shield:2 armor:3 helmet:1 sword:2 hello key:value
=== Inventory System Analysis ===
Redundant item 'sword' - discarding
Error - invalid parameter 'hello'
Quantity error for 'key': invalid literal for int() with base 10: 'value'
Got inventory: {'sword': 1, 'potion': 5, 'shield': 2, 'armor': 3, 'helmet': 1}
Item list: ['sword', 'potion', 'shield', 'armor', 'helmet']
Total quantity of the 5 items: 12
Item sword represents 8.3%
Item potion represents 41.7%
Item shield represents 16.7%
Item armor represents 25.0%
Item helmet represents 8.3%
Item most abundant: potion with quantity 5
Item least abundant: sword with quantity 1
Updated inventory: {'sword': 1, 'potion': 5, 'shield': 2, 'armor': 3, 'helmet': 1, 'magic_item': 1}
```

> 💡 게임 시작 시점엔 보통 인벤토리가 비어 있죠 ;)

---

## 실습 5: 스트림 마법사

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_data_stream` |
| 디렉토리 | `ex5/` |
| 제출 파일 | `ft_data_stream.py` |
| 허용 함수 | `next()`, `range()`, `len()`, `print()`, `import typing`, `typing.Generator`, `import random`, `random.*` |

**마법의 시간!** 게임이 크래시 없이 수백만 개의 이벤트를 어떻게 처리하는지 궁금했던 적 있나요? **제너레이터(generators)**의 세계에 오신 것을 환영합니다, 파이썬의 메모리 절약 초능력이죠!

이 실습은 데이터 스트림을 그때그때 만들어내기 위한 **`yield`** 키워드가 있는 **제너레이터** 사용을 요구합니다. 모든 것을 메모리에 저장하는 대신, 필요할 때마다 값을 생산하는 제너레이터 함수를 구현해야 합니다.

플레이어 목록에서 무작위 이름을, 행동 목록에서 무작위 행동을 고르는 끝없는 제너레이터 함수 `gen_event()`를 만드세요. 이 제너레이터에 `next()`가 호출될 때마다, 새로운 이벤트를 튜플 `(name, action)`로 반환합니다.

스크립트의 메인 부분에서, 천 번 반복하며 `gen_event()`로부터 받은 1000개의 이벤트를 전부 표시하세요.

그 다음, `gen_event()`로 다시 생성한 10개 튜플의 리스트를 만드세요.

마지막으로, 앞서 만든 리스트를 받아 무작위로 요소 하나를 골라 리스트에서 제거하고 그것을 `yield`하는 새 제너레이터 함수 `consume_event`를 만드세요. 이 과정을 리스트가 빌 때까지 반복합니다. 이 제너레이터는 `for .. in ..` 구문에서 직접 사용되어야 합니다.

**예시:**
```
$> python3 ft_data_stream.py
=== Game Data Stream Processor ===
Event 0: Player bob did action run
Event 1: Player alice did action eat
...
Event 999: Player alice did action move
Built list of 10 events: [('charlie', 'move'), ('dylan', 'grab'), ...]
Got event from list: ('charlie', 'swim')
Remains in list: [...]
...
Got event from list: ('dylan', 'grab')
Remains in list: []
```

---

## 실습 6: 데이터 연금술사

| 항목 | 내용 |
|---|---|
| 함수명 | `ft_data_alchemist` |
| 디렉토리 | `ex6/` |
| 제출 파일 | `ft_data_alchemist.py` |
| 허용 함수 | `import random`, `random.*`, `print()`, `len()`, `sum()`, `round()` |

**최종 보스 타임!** 모든 자료구조를 마스터했습니다. 이제 그것들을 우아하고 압축된 형태로 다시 발견할 시간입니다! 여기서 진정한 데이터 연금술사가 됩니다!

이 실습은 데이터를 효율적으로 변환하고 필터링하기 위한 **리스트**와 **딕셔너리 컴프리헨션** 사용을 요구합니다. 이는 데이터 처리를 위한 파이썬의 핵심 기능입니다.

일부는 대문자로 시작하고 일부는 그렇지 않은 플레이어 이름 리스트를 만드세요. 두 개의 리스트 컴프리헨션을 만드세요: 첫 번째는 모든 이름을 대문자로 시작하게 만든 새 리스트를, 두 번째는 원래 리스트에서 이미 대문자로 시작하는 이름들만 담은 새 리스트를 만듭니다.

이제, 이 완전히 대문자화된 플레이어 이름 리스트로부터 딕셔너리를 만듭시다. 이름이 키가 되고, 값은 정해진 범위 안에서 무작위로 생성된 점수가 됩니다. 물론 컴프리헨션으로 이 딕셔너리를 만듭니다. 그 다음 평균보다 높은 점수를 가진 두 번째 딕셔너리도 컴프리헨션으로 만듭니다.

**예시:**
```
$> python3 ft_data_alchemist.py
=== Game Data Alchemist ===

Initial list of players: ['Alice', 'bob', 'Charlie', 'dylan', 'Emma', 'Gregory', 'john', 'kevin', 'Liam']
New list with all names capitalized: ['Alice', 'Bob', 'Charlie', 'Dylan', 'Emma', 'Gregory', 'John', 'Kevin', 'Liam']
New list of capitalized names only: ['Alice', 'Charlie', 'Emma', 'Gregory', 'Liam']

Score dict: {'Alice': 263, 'Bob': 666, 'Charlie': 907, 'Dylan': 170, 'Emma': 568, 'Gregory': 446, 'John': 90, 'Kevin': 527, 'Liam': 54}
Score average is 410.11
High scores: {'Bob': 666, 'Charlie': 907, 'Emma': 568, 'Gregory': 446, 'Kevin': 527}
```

> ℹ️ 집합(set)에도 컴프리헨션을 사용하는 것이 가능합니다.
>
> ⚠️ 각 컴프리헨션은 (줄 길이를 초과하지 않는 한) 한 줄에 작성되어야 합니다.

---

## 제출 방법

Git 저장소에 과제를 제출하세요. 평가 시에는 저장소 안의 작업물만 평가됩니다.

**체크리스트:**
- [ ] 파일 이름이 정확한가?
- [ ] `flake8`과 `mypy`를 모두 통과하는가?
- [ ] 모든 함수와 메서드에 타입 힌트가 있는가?
- [ ] 파일 입출력 없이 메모리/커맨드라인 인자만으로 처리했는가?
- [ ] 각 자료구조 선택 이유, 컬렉션 연산 방식을 설명할 수 있는가? (평가 시 질문받을 수 있음)