# StockObjects
내장 객체라고 부르면 윈도우 운영체제가 미리 만들어서 제공하는 GDI 객체이다. 내장 객체를 DC에 선택할 때는 CDC::SelectStockObject() 함수를 사용한다. ex) NULL_PEN, NULL_BRUSH, LTGRAY_BRUSH, WHITE_PEN