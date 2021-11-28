# 메모장(NotePad)
메모장 만들기 프로젝트

* 기간: 2021.06.01 ~ 2021.11.28
* 사용언어: C++
* 개발환경: Visual Studio 2019
* 사용기술: 
  - MFC
  - 직접만든 Array Library

프로젝트 상세내용
=============
목적
-------------
* 이 메모장은 윈도우 기본 메모장을 참고하여 만든 메모장입니다. 이 메모장을 만들면서 윈도우 메모장에 없어서 아쉬웠던 기능들을 추가하였습니다.

* 윈도우 메모장에서는 실행취소만 1단계가 가능해서 글을 작성하다가 원래 상태로 돌리는 것이 불가능했습니다. 이를 개선하여 제한없이 실행취소를 할 수 있게 만들었습니다.

* 그리고 윈도우 메모장에서는 없던 다시 실행 기능도 추가하여 제한없이 실행할 수 있게 만들었습니다.

* 또한 윈도우 메모장에서는 인쇄를 할 때 미리보기 기능이 없어서 인쇄 전에 어떻게 용지가 출력되는지 알 수 없는 불편함이 있었습니다.

* 이를 개선하여 인쇄 전 미리보기 기능을 추가하여 인쇄할 때 어떻게 출력되는지 확인할 수 있도록 만들었습니다.


개발인원
-------------
<pre>
<code>
* 본인 한명
</code>
</pre>

주요기능(Use Case Diagram)
-------------
![Use Case Diagram(JPG)](https://user-images.githubusercontent.com/63482037/143727127-7244093c-6317-4a47-a3d8-d2644d63c5f5.jpg)


클래스 다이어그램
-------------
* Composite Pattern 활용

![Composite Pattern (JPG)](https://user-images.githubusercontent.com/63482037/143727191-d9faa5e6-4c65-42fe-a6a4-e2e3aaf52d7f.jpg)

* Observer, Factory, Strategy, Visitor Pattern 활용

![Observer, Factory, Strategy (JPG)](https://user-images.githubusercontent.com/63482037/143729627-d37decb6-6dc9-45bf-9595-18d6732bf4be.jpg)


* Command Pattern 활용

![Command Pattern (JPG)](https://user-images.githubusercontent.com/63482037/143729647-1b135141-12f8-43fa-9a81-b65f5ea2c574.jpg)


배운점
-------------
<pre>
<code>
1. Use Case Modeling을 통해 개발의 뼈대를 만드는 법
2. 영문 reference를 직접 보고 필요한 디자인 패턴을 적용하는 법
3. 객체 설계부터 인터페이스 설계까지 책임지며 약 22,000줄의 큰 프로그램을 다뤄보는 법
</code>
</pre>

구동화면
-------------
* 가계부 메인화면

![가계부1](https://user-images.githubusercontent.com/63482037/130325046-ab19ad00-94a9-485b-bd92-1cae91efce59.PNG)


* 가계부 찾기화면

![가계부 찾기](https://user-images.githubusercontent.com/63482037/130325051-e504a571-a363-42e2-85e7-7b009ddab1b0.PNG)


* 가계부 정산화면

![정산하기](https://user-images.githubusercontent.com/63482037/130325062-7cb4fe69-10cc-415e-a8a6-edc5226abea7.PNG)
