# 고도화 개발 내용

## 기존 기능 업그레이드
- 조이스틱에서 키보드 및 마우스 작동 기능 추가

## C++ IOCP Server 연동 & 오픈월드 멀티플레이 고도화 프로젝트
1. 위치 동기화
   - 서버와 클라이언트 간 플레이어 및 게임 객체의 위치 정보를 동기화하여 모든 플레이어가 동일한 환경에서 게임을 진행할 수 있도록 함.
2. 미사일 발사
   - 서버와 클라이언트 간 플레이어들이 미사일을 발사할 수 있는 기능을 연동하여 전투 요소를 할 수 있도록 기능 제공
3. 파괴 동기화
   - 게임 객체의 파괴 상태를 동기화하여 모든 플레이어가 동일한 파괴 상태를 관찰하고 상호작용할 수 있도록 함.

## 기능 시연 이미지
1. 오픈월드 입장
![오픈월드 입장](https://github.com/daev681/FlightSim-unity3D/assets/54939319/34b0b571-8e3e-447e-a755-b6b3e040bec9)
2. 플레이어 동기화
![위치 동기화](https://github.com/daev681/FlightSim-unity3D/assets/54939319/4fd66f92-aa38-4f5b-8b33-60a816e33d3d)
3. 이동
![실제 이동](https://github.com/daev681/FlightSim-unity3D/assets/54939319/0ba0479a-0845-47e0-a279-c7a5f3efb20a)

5. 미사일 발사

![미사일발사](https://github.com/daev681/FlightSim-unity3D/assets/54939319/e23a1ebb-77de-463c-b326-c0079ca5747d)

7. Lock On
![락온 ](https://github.com/daev681/FlightSim-unity3D/assets/54939319/86f5e7f8-c662-4890-842c-08a32e0b65e2)

8. 미사일 격추 장면
![유도 미사일 장면](https://github.com/daev681/FlightSim-unity3D/assets/54939319/d443d868-8a79-47c5-9285-56575608419c)

10. 파괴
    
![파괴](https://github.com/daev681/FlightSim-unity3D/assets/54939319/6605840c-dc0b-4048-852d-7ee515e699de)

12. 서버 연산
    
![서버연산](https://github.com/daev681/FlightSim-unity3D/assets/54939319/d653c02a-753e-4a42-a30b-60e4b0ac4b7c)





## 소스코드 

C++ IOCP SERVER : https://github.com/daev681/FlightSim-IOCP

Unity 3D Project : https://github.com/daev681/FlightSim-unity3D

## 한계점
- 서버 연산량이 많아 모든 플레이어의 완전한 리얼타임 동기화가 불가능함.
- 모든 플레이어의 행동을 실시간으로 처리하고 동기화하는 데에 한계가 있음.

## 추후 개선사항
1. 서버 분산
   - 서버를 분산하여 부하를 분산시키고 처리 능력을 향상시킴으로써 더 많은 플레이어와 자연스러운 동기화를 가능하도록 예정
2. 패킷 가공
   - 서버에서 전송되는 패킷의 형식을 최적화하고, 필요한 정보만을 포함하여 데이터 양을 줄이고 처리 속도를 향상 예정
3. 위치에 따른 동기화 패킷 연산 개선
   - 플레이어의 위치 변화가 클 때에만 동기화를 수행하거나, 특정 조건이 충족될 때만 위치 정보를 전송하는 등의 방법으로 패킷 전송을 최적화하여 서버의 부하 감소 예정


================================
## 클라이언트 참고 사항 
출처
# FlightSim
https://vazgriz.com/346/flight-simulator-in-unity3d-part-1/
