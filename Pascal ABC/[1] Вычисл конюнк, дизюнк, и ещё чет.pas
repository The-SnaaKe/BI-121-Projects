program SCAM;
  var 
   a: boolean;
   b: boolean;
   x: boolean;
   z, y: string;
begin
    y:='yes';
  while y = 'yes' do
    begin
  write('Правда или не правда?: ');
  readln(a);
  write('Выберете процедуру (и,/,no/): ');
  readln(z);
  write('Правда или не правда?: ');
  readln(x);
    case z of
      'и':
        begin
         x:= a and b;
         writeln('Ответ: ',x);
      if x=true then
        writeln ('Это хорошо, что это правда.')
      else
        writeln ('Это плохо, что это плохо') 
        end;
      '/':
        begin
         x:= a or b;
         writeln('Ответ: ',x);
      if x=true then
        writeln ('Это хорошо, что это правда.')
      else
        writeln ('Это плохо, что это плохо') 
        end;
      'no/':
        begin
        x:= a xor b;
         writeln('Ответ: ',x);
      if x=true then
        writeln ('Это хорошо, что это правда.')
      else
        writeln ('Это плохо, что это плохо') 
        end;
    else
      writeln('Данная операция не известна!')
  end;
  writeln('Продолжить? yes/no');
  read (y)
  end;
end.
