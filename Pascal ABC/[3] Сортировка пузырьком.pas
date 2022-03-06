program x;

const
  n = 50;

var
  i, j, c: integer;
  a: array[1..n] of integer;

begin
  for i := 1 to n do
  begin
    a[i] := random(101) - 50;
    write(a[i]:4);
  end;
  writeln('  - Несортированный масив');
  for i := 1 to n - 1 do
    for j := 1 to n - 1 do
      if(a[j] < a[j + 1]) then
      begin
        c := a[j];
        a[j] := a[j + 1];
        a[j + 1] := c;
      end;
  for i := 1 to n do
    write(a[i]:4);
  writeln('  - Сортированный масив');
end.