# Qt_Account_Project

Qt 프로젝트(계좌 조회/관리 프로그램)

## • 사용자 시나리오
**시작 화면**

프로그램 시작시 info.txt 파일에서 전체 멤버, 계좌 정보를 불러와 MemberManager 클래스에 저장합니다
- Log In
  - id, pw를 입력해서 사용자 로그인, 성공/실패 여부를 모달창으로 보여줍니다
  - 로그인 성공후 메인 UI로 넘어갑니다
- Sign Up
  - 이름, id, pw를 입력해서 사용자를 등록합니다
- Quit
  - 현재 멤버, 멤버별 계좌 정보를 intfo.txt에 저장하고 종료합니다
    
**메인 화면**
  - 로그인된 사용자의 계좌 등록, 조회, 입금, 출금 기능을 합니다
  - Account inquiry
    - 사용자의 계좌 이름, ID, 잔액, 생성일자를 조회합니다
  - Account registration
    - 계좌 이름, 잔액, 생성일자(기본은 현재 날짜)를 받아서 계좌를 생성합니다
  - Deposit
    - 사용자가 선택한 계좌에 입금 기능을 수행합니다
  - Withdraw
    - 사용자가 선택한 계좌에 출금 기능을 수행합니다     

시나리오 링크 : https://excalidraw.com/#json=Ax2zqb9NSSpS30fk2x3sg,kYVwl4AR85WPQMQVGRoEkQ
