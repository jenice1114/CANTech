## 🇰🇷 개요
CANTech는 자동차 네트워크 프로토콜 중 하나인 CAN의 원리를 학습하고 CAN 통신 환경을 소프트웨어로 구현하여 메시지 송수신을 테스트할 수 있는 프로그램 입니다.

## 참조
* my [Velog](https://velog.io/@jenice/series/Toy-Project)

## can_tech 시작하기

### 설치
1. can_tech 소스 다운로드

```bash
git clone https://github.com/jenice1114/can_tech.git
```

2. 설치 스크립트 실행

```bash
cd script

./install.sh
```

### 빌드

```bash
mkdir build
cd build

# Debug 빌드
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Release 빌드
cmake -DCMAKE_BUILD_TYPE=Release ..

make
```

### 실행

```bash
# Debug 빌드 시
cd build/Debug

# Release 빌드 시
cd build/Release

./can_tech
```

***

## 🇺🇸 Overview
CANTech is a program designed to help users learn the principles of CAN, one of the automotive network protocols, and implement a software-based CAN communication environment to test message transmission and reception.

## Quick Links
* my [Velog](https://velog.io/@jenice/series/Toy-Project)

## Getting Started

### Setup
1. Download the can_tech source

```bash
git clone https://github.com/jenice1114/can_tech.git
```

2. Install the script

```bash
cd script

./install.sh
```

### Build

```bash
mkdir build
cd build

# Debug Mode
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Release Mode
cmake -DCMAKE_BUILD_TYPE=Release ..

make
```

### Run

```bash
# Debug Mode
cd build/Debug

# Release Mode
cd build/Release

./can_tech
```