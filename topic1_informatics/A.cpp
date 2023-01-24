// Простой stack
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
 
 
stack<int> s;
char str[100];
int n;
int main()
{
  while(scanf("%s",&str))
  {
    if (strcmp(str,"push") == 0){
      cin>>n;
      s.push(n);
      cout<<"ok"<<"\n";
    } 
    else if (strcmp(str,"pop") == 0){
       cout<<s.top()<<"\n";
      s.pop();
    } 
    else if (strcmp(str,"back") == 0){
       cout<<s.top()<<"\n";
    } 
    else if (strcmp(str,"size") == 0){
       cout<<s.size()<<"\n";
    } 
    else if (strcmp(str,"clear") == 0){
      while(!s.empty()) 
    s.pop();
      cout<<"ok"<<"\n";
    } 
    else{
      cout<<"bye"<<"\n";
      break;
    }
  }
  return 0;
}

/*
Функция scanf() является процедурой ввода общего назначения, 
считывающей данные из пото­ка stdin. Она может считывать данные всех базовых типов
и автоматически конвертировать их в нужный внутренний формат.

%s - Считать строку
Например, чтобы считать целое число и присвоить его значение переменной count, 
необходи­мо воспользоваться следующим обращением к scanf():

scanf("%d", &count);
*/

/*
Эта функция устроена так: она сравнивает две Си-строки символ за символом. 
Если строки идентичны (и по символам и по их количеству) – функция возвращает в программу число 0. 
Если первая строка  длиннее второй – возвращает в программу число 1, а если меньше, то -1.  
Число -1 возвращается и  тогда, когда длина строк равна, но символы строк не совпадают.
*/