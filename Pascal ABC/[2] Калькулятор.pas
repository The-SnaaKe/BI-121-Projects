program poisk_o4ka_slona_pod_vash;
var
  x, y, i: real;
  o4en: string;
  bolshoy: char;
begin
  o4en := 'yes';
  while o4en = 'yes' do
  begin
    write('Введите габариты вашего по x: ');
    readln(x);
    write('Выберете процедуру (+, -, *, /, ^, %): ');
    readln(bolshoy);
    write('Введите габариты вашего по y: ');
    readln(y);
    case bolshoy of
      '+':
        begin
          i := x + y;
          writeln('Размер вашего равен: ', i);
          if i > 150 then
            writeln('Hey bro, nice dick.')
          else
            writeln('You need boy next door.')
        end;
      '-':
        begin
          i := x - y;
          writeln('Размер вашего равен:  ', i);
          if i > 150 then
            writeln('Hey bro, nice dick.')
          else
            writeln('You need boy next door')
        end;
      '*':
        begin
          i := x * y;
          writeln('Размер вашего равен:  ', i);
          if i > 150 then
            writeln('Hey bro, nice dick.')
          else
            writeln('You need boy next door')
        end;
      '/':
        begin
          i := x / y;
          if y = 0 then
            writeln('На 0 делить нельзя! ☠️');
          writeln('Размер вашего равен: ', i);
          if i > 150 then
            writeln('Hey bro, nice dick.')
          else
            writeln('You need boy next door')
        end;
      '^':
        begin
          i := power(x, y);
          writeln('Размер вашего равен:  ', i);
          if i > 150 then
            writeln('Hey bro, nice dick.')
          else
            writeln('You need boy next door')
        end;
      '%':
        begin
          i := x * (100 / y);
          writeln('Размер вашего равен:  ', i);
          if i > 150 then
            writeln('Hey bro, nice dick.')
          else
            writeln('You need boy next door')
        end;
    else
      writeln('Данная операция не известна!')
    end;
    writeln('Продолжить? yes/no');
    read(o4en)
  end;
end.
