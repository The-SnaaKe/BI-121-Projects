program q;

uses
  crt;

const
  n = 3;

var
  a: array [1..n, 1..n] of string[20];
  i, j: byte;
  hk: char;

begin
  writeln('Введите ', n * n, ' слов,после каждого слова нажимайте enter');
  for i := 1 to n do
    for j := 1 to n do
    begin
      writeln('Слово[ ', i, ' , ', j, ' ] ');
      a[i, j] := ' ';
      repeat
        hk := readkey;
        if hk <> #13 then
        begin
          a[i, j] := a[i, j] + hk;
          write(hk);
        end
        else writeln;
      until hk = #13;
    end;
  for i := 1 to n do
  begin
    writeln;
    for j := 1 to n do
    begin
      write(a[i, j]:4);
    end;
  end;
  writeln;
  writeln('Что получилось:');
  write(a[random(1, n), 1] + a[random(1, n), 2] + a[random(1, n), 3]);
  writeln;
end.