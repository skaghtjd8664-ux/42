*This project has been created as part of the 42 curriculum by <honam>.*

## Description
`get_next_line`은 파일 디스크립터(File Descriptor)로부터 텍스트를 한 줄씩 읽어오는 함수를 구현하는 프로젝트입니다. 이 프로젝트를 통해 C 프로그래밍에서 매우 중요한 개념인 **정적 변수(Static Variable)**의 활용법을 익히고, 버퍼링을 통한 효율적인 I/O 처리 및 정밀한 메모리 관리(누수 방지) 메커니즘을 학습하는 것을 목표로 합니다.

## Algorithm & Logical Justification
본 프로젝트에서 채택한 알고리즘은 **정적 변수를 활용한 동적 버퍼 누적 방식**입니다.

1. **지속적인 버퍼 읽기**: `BUFFER_SIZE`만큼 데이터를 `read()` 함수로 읽어와 임시 버퍼에 저장합니다.
2. **정적 변수(`backup`)에 누적**: 새로 읽어온 데이터는 정적 변수에 계속해서 이어 붙여집니다(`ft_strjoin`). 이 정적 변수는 함수가 종료되어도 이전에 읽었던 데이터의 상태를 고스란히 유지합니다.
3. **개행 문자(`\n`) 검사**: 임시 버퍼에 개행 문자(`\n`)가 포함되어 있거나 파일의 끝(`EOF`)에 도달할 때까지 읽기 루프를 반복합니다.
4. **라인 추출 및 백업 갱신**: 개행 문자가 발견되면, 개행 문자까지의 문자열을 잘라내어 반환할 `line`을 만듭니다. 그 후, 개행 문자 이후에 남은 문자열을 다시 정적 변수 `backup`에 저장하여 다음 함수 호출 때 이어서 읽을 수 있도록 조치합니다.

### 정당성 (Justification)
이 방식은 파일 전체를 한 번에 메모리에 올리지 않고 `BUFFER_SIZE`만큼만 쪼개어 읽기 때문에 대용량 파일을 처리할 때 메모리를 매우 효율적으로 아낄 수 있습니다. 또한 정적 변수를 사용함으로써 파일의 읽기 포인터 위치나 남은 버퍼 잔여물을 유연하게 보존할 수 있어 과제의 요구사항(반복 호출 시 한 줄씩 읽기)을 완벽하게 만족합니다.

## Instructions

### Compilation
컴파일 시에는 반드시 `-D BUFFER_SIZE=n` 플래그를 추가하여 read 함수가 한 번에 읽어올 바이트 크기를 지정해 주어야 합니다.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c