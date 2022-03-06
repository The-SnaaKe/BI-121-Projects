program f_for_down;

uses
  graphabc;

var
  z: byte;
  a: array[1..3, 1..3]of Integer;

procedure a1;
begin
  clearwindow;
  SetPenColor(clBlack);
  setpenwidth(1);
  line(960, 0, 960, 1890);
  line(0, 0, 0, 1890);
  line(0, 470, 961, 470);
  floodfill(100, 100, cllightblue);
  
  setwindowsize(960, 800);
  
  //самолёт
  SetPenColor(clBlack);
  setpenwidth(3);
  line(400, 190, 450, 210);
  line(400, 230, 450, 210);
  
  line(400, 190, 200, 190);
  line(400, 230, 200, 230);
  line(200, 190, 200, 230);
  
  line(200, 190, 170, 170);
  line(200, 230, 170, 250);
  
  line(170, 160, 170, 170);
  line(170, 260, 170, 250);
  
  line(170, 160, 220, 160);
  line(170, 260, 220, 260);
  
  line(250, 190, 220, 160);
  line(250, 230, 220, 260);
  
  floodfill(350, 200, clred);
  floodfill(200, 170, clgray);
  floodfill(200, 240, clgray);
  //солнце
  setbrushcolor(clyellow);
  setpencolor(clorange);
  circle(850, 50, 150);
  line(560, 10, 702, 25);
  line(600, 150, 709, 100);
  line(680, 275, 773, 178);
  line(860, 200, 840, 320);
  
  //волны + море
  setpenwidth(5);
  setpencolor(clblue);
  arc(20, 530, 65, 135, 50);
  arc(105, 530, 65, 135, 50);
  arc(190, 530, 65, 135, 50);
  arc(275, 530, 65, 135, 50);
  arc(360, 530, 65, 135, 50);
  arc(445, 530, 65, 135, 50);
  arc(525, 530, 65, 135, 50);
  arc(605, 530, 65, 135, 50);
  arc(685, 530, 65, 135, 50);
  arc(765, 530, 65, 135, 50);
  arc(845, 530, 65, 135, 50);
  arc(925, 530, 65, 135, 50);
  floodfill(300, 700, clcyan);
  setbrushcolor(clwhite);
end;

procedure b2;
var
  i, j, sum: integer;
begin
  clearwindow;
  randomize;
  writeln;
  writeln('Двумерный массив 3 на 3: ');
  for i := 1 to 3 do
  begin
    for j := 1 to 3 do
    begin
      a[i, j] := random(101) - 50;
      write(a[i, j]:4);
    end;
    writeln;
  end;
  sum := 0;
  for i := 1 to 3 do
    for j := 1 to 3 do
      sum := sum + a[i, j];
  writeln;
  writeln(' Ответ: ', sum);
  writeln;
end;

procedure c3;
var
  i, j, buf: integer;
begin
  clearwindow;
  randomize;
  writeln;
  writeln('Двумерный массив 3 на 3: ');
  for i := 1 to 3 do
  begin
    for j := 1 to 3 do
    begin
      a[i, j] := random(101) - 50;
      write(a[i, j]:4);
    end;
    writeln;
  end;
  writeln;
  writeln('Зеркальное отражение: ');
  i := 1;
  for j := 1 to 3 do
  begin
    buf := a[i, j];
    a[i, j] := a[i + 2, j];
    a[i + 2, j] := buf;
  end;
  for i := 1 to 3 do
  begin
    for j := 1 to 3 do
    begin
      write(a[i, j]:4);
    end;
    writeln;
  end;
  writeln;
end;

begin
  repeat
    writeln('Нажмите 1 - что-бы получить рисунок. ');
    writeln('Нажмите 2 - что-бы получить сумму массива. ');
    writeln('Нажмите 3 - что-бы отзеркалить массив. ');
    writeln('Нажмите 0 - если мамка зашла в комнату. ');
    readln(z);
    clearwindow;
    case z of
      1: a1;
      2: b2;
      3: c3;
    end;
  until z = 0;
end.