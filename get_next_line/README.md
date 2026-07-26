*This project has been created as part of the 42 curriculum by <honam>.*

## Description
`get_next_line`은 파일 디스크립터(File Descriptor)로부터 텍스트를 한 줄씩 읽어오는 함수를 구현하는 프로젝트입니다. 이 프로젝트를 통해 C 프로그래밍에서 매우 중요한 개념인 **정적 변수(Static Variable)**의 활용법을 익히고, 버퍼링을 통한 효율적인 I/O 처리 및 정밀한 메모리 관리(누수 방지) 메커니즘을 학습하는 것을 목표로 합니다.

## Algorithm & Logical Justification
본 프로젝트에서 채택한 알고리즘은 **정적 변수를 활용한 동적 버퍼 누적 방식**입니다.

## Algorithm Explanation & Justification (알고리즘 설명 및 당위성)
`get_next_line` 구현의 가장 큰 난관은 한 번에 읽어오는 크기(`BUFFER_SIZE`)가 실제 한 줄의 길이와 일치하지 않는다는 점입니다[cite: 2, 3]. 이를 해결하기 위해, 연속적인 함수 호출 간 데이터를 보존할 수 있도록 **정적 변수**를 활용하여 크게 3단계로 구성된 알고리즘을 설계했습니다.

1. **읽기 및 데이터 누적 (`read_line`)**
   - 파일 디스크립터로부터 `BUFFER_SIZE` 바이트만큼 임시 버퍼에 데이터를 읽어옵니다.
   - 읽어온 데이터를 정적 변수인 `static char *backup` 문자열 뒤에 계속 붙여나갑니다.
   - 버퍼에 개행 문자(`\n`)가 포함되어 있거나, 파일 끝(EOF)에 도달할 때까지 이 읽기 작업을 반복합니다.
2. **한 줄 추출 (`extract`)**
   - `backup`에 한 줄 이상의 데이터가 누적되면, 첫 번째 개행 문자(`\n`)의 위치를 찾습니다[cite: 2].
   - `backup` 문서의 처음부터 해당 개행 문자(혹은 파일 끝)까지의 영역만큼 메모리를 할당하여 새로 반환할 `line` 문자열에 복사합니다.
3. **백업 업데이트 (`update_backup`)**
   - 반환할 한 줄을 추출한 뒤, `backup`에 남아있는 나머지 데이터(첫 개행 문자 이후의 텍스트)를 다음 함수 호출을 위해 보존해야 합니다.
   - 남은 텍스트 크기만큼 메모리를 새로 할당해 복사하고, 기존 `backup` 메모리는 해제(`free`)한 뒤 정적 포인터가 새 주소를 가리키도록 업데이트합니다. 더 이상 남은 내용이 없다면 백업을 해제하고 `NULL`을 반환합니다.

### 정당성 (Justification)
이 방식은 파일 전체를 한 번에 메모리에 올리지 않고 `BUFFER_SIZE`만큼만 쪼개어 읽기 때문에 대용량 파일을 처리할 때 메모리를 매우 효율적으로 아낄 수 있습니다. 또한 정적 변수를 사용함으로써 파일의 읽기 포인터 위치나 남은 버퍼 잔여물을 유연하게 보존할 수 있어 과제의 요구사항(반복 호출 시 한 줄씩 읽기)을 완벽하게 만족합니다.

## Instructions

### Compilation
컴파일 시에는 반드시 `-D BUFFER_SIZE=n` 플래그를 추가하여 read 함수가 한 번에 읽어올 바이트 크기를 지정해 주어야 합니다.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c