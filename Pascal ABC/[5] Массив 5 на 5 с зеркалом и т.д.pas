program massiv;

const
  n = 5;

var
  a: array[1..n, 1..n] of integer;
  i, j, k, sum: integer;
  z: string;

begin
  readln(z);
  writeln('Двумерный массив 5 на 5');
  randomize;
  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      a[i, j] := random(81) - 40;
    end;
  end;
  for i := 1 to n do
  begin
    writeln;
    for j := 1 to n do
    begin
      write(a[i, j]:4);
    end;
  end;
  case z of
    'Сумма':
      begin
        sum := 0;
        for i := 1 to n do
        begin
          for j := 1 to n do
          begin
            sum := sum + a[i, j];
          end;
        end;
        writeln;
        writeln(' Ответ: ', sum);
      end;
    'Mirror':
      begin
        for i := 1 to n - 1 do
        begin
          for j := 1 to n - 1 do
          begin
            k := a[i, j];
            a[i, j] := a[n - j + 1, n - i + 1];
            a[n - j + 1, n - i + 1] := k;
          end;
        end;
        writeln;
        for i := 1 to n do
        begin
          writeln;
          for j := 1 to n do
          begin
            write(a[i, j]:5);
          end;
        end;
      end;
    'итае и джитае':
      begin
        for i := 1 to n do
        begin
          for j := 1 to n do
          begin
            a[i, j] := k;
            a[i, j] := a[j, i];
            a[j, i] := k;
          end;
        end;
        writeln;
        for i := 1 to n do
        begin
          writeln;
          for j := 1 to n do
          begin
            write(a[i, j]:5);
          end;
        end;
      end;
  end;
end.
