/*
google search mere device pr dart install kaise kare
run dart code, open terminal, go to your file location
type 
  cd mai/mera_folder/wo_folder_jisme_code_wali_file_hai 
  mtlb cd <space> file location poori ENTER
type
  dart file_ka naam e.g dart test.dart
*/

//import 'dart:core'        automatically imported dart core library
import 'dart:io';           //dart standard input output library

///fundamentals of dart     
main(){                     //everything runs from main FUNCTION, program ka pilot 7 star
  //printer();                //pilot doosre functions ko bula skta hai
  //print(10);                //ya khud bhi kaam kr skta hai
  //operators();              // ya dono, ya kuch nahi xD
  switchCase();
}

/*print 
      example
          and this is a multi line comment
              comments are not executed in a program.
                inka program pr koi fark nahi pdta
*/
void printer(){
  var fname = "rahul";
  String lname = "anand";
  print(fname + "katya" + lname);       //print function
}

//input example aur ye ek single line comment hai
void inputter(){
  stdout.writeln('Enter your name: ');    //another print function, aise bhi kr skte hain
  var name = stdin.readLineSync();        //read line meaning input and save in name variable
  stdout.writeln('You entered -> $name');
}

void stringFormat(){
  String singleq = 'My name\'s \t ra.\n';   //string yani text '' ke beech hi aaega
  var mixq = "My name's \t ra.\n";          //ya " " ke beech bhi aa skta hai \ lga ke escape sequence use kr skte hai \t = tab, \n = newline
  var rawq = r"My name\'s \t ra.\n";        //  r -> rawstring, escape sequence ka effect khatm
  var multiq = '''my
  name''' + """

    is 
ra""";                                      //''' ''' multiline text,  
  stdout.writeln("Strings -> $singleq $mixq $rawq $multiq");
}


void operators(){
  var a = 10, b = 4;                      //assignment operator =
  //var 10 = b; error 10 to 10 hai use koi aur value kaise di ja shakti hai

///////////binary operators ye 2 operand pe kaam krte hain/////////////
  stdout.writeln('${a+b}, ${a -b}, ${a* b}, ${a / b}, ${a%b}');    //maths
  stdout.writeln(a.toString() + b.toString());     //concatenation of strings
  stdout.writeln(a.toString() * b);                //string multiplied by number
  
  a += 2; b *= 2; stdout.writeln("$a - $b");       //a = a + 2, b = b * 2 increment decrement

  if (a == b)                             //relational 
    stdout.writeln("ok");                          // ==, != not equal, <= less than or equal,
  else                                    //  <, >, >=
    stdout.writeln("not ok");                      // && logical and, || logical or, ! logical not 
                                          //if else agar ye sahi hai to ye wrna wo
  var condition = true;                   
  if (!(condition || false)){
    stdout.writeln(true);
  } else
    stdout.writeln(false);

///////unary operator ye ek operand pe kaam krte hain//////////////////////////////
  stdout.writeln('${a++} $a ${++a} ${--a} $a');  //unary operator krke dekho achcha lgta hai  

//////////ternary operator ye 3 operand pe kaam krte hain////////////////////
  int testvalue = 100;
  var result = testvalue > 200 ? 'sahi' : 'galat';    //if condition true to sahi pe jaega yani : ke left pe
  stdout.write(result);                               // wrna galat ya right side pe jaega
                                                      //3 operand, condition, true_value, false_value
}



//class num has properties number and nimbuda
class Num {
  int nimbuda = -10;
}

void nullAwareOperators(){
  // (?.) if accessed value is null, skip command
  // (??) if accessed value is not defined, provide default value
  // (??=)
  var n = Num(), n2;
  var number;
  stdout.writeln(n.nimbuda);      // prints -10 qki Num ka ek member nimbuda hai
  
  number = n2?.nimbuda;        //n2 is null so n2 can't have any member named nimbuda
  stdout.writeln(number);      // handles null exception and assigns null to number
  
  number = n2?.nimbuda ?? 20;   //n2 is null so n2.nimbuda is inaccessible, defaults number to 
  stdout.writeln(number);          //20
  
  n2 ??= 'teekhalaal';             //if n2 is null n2 = value
  stdout.writeln(n2); 
}

void moreOperators(){
  var i = 100;                        //i ka TYPE run ke time pe decide hoga

  //checking type of variable
  if (i.runtimeType == int) {stdout.write(true);}     //agar i run ke time pe int TYPE ka hai to 
  else {stdout.write(false);}                       //wrna
  
  if (i is int) {stdout.write(true);}     // is checks type of variable agar i int hai to
  else {stdout.write(false);}             //is se directly type check kr skte hain

  var j = i is int ? i as int :  0.0;    // as TYPE CASTS makes j a variable of dataTYPE int
  stdout.write("false $j");                    // as class aur subclass ke context me use me aaega
}

void ifElseLadder(){
  stdout.write("Enter a number: ");

  //take input -> if input null empty string is received stdin.readLineSync() ?? ''
  //int me bdlne ki koshish jo bhi value aayi hai int.tryParse(value) ?? 0
  //ho gya to number me wo value wrna number me 0
  var number = int.tryParse(stdin.readLineSync() ?? '') ?? 0;
  
  //if else flow

  //agar number 100 se bda hai
  if (number > 100) {
    stdout.writeln("$number to 100 se jyada hai..");
  }

  //wrna agar number 80 se bda hai mtlb number 100 ya 100 se km hai 
  //qki upar wali condition fail ho chuki hai
  else if (number > 80) {
    stdout.writeln("$number to 80 se jyada hai..");
  }

  else if (number > 60) {
    stdout.writeln("$number to 60 se jyada hai..");
  }
  else if (number > 40) {
    stdout.writeln("$number to 40 se jyada hai..");
  }
  else if (number > 20) {
    stdout.writeln("$number to 20 se jyada hai..");
  }
  else {
    stdout.writeln("$number to 20 se km hai..");
  }
}

void switchCase(){
  stdout.write("Choose (y/n): ");

  var choose = stdin.readLineSync() ?? '';
  choose = choose.toLowerCase();
  stdout.writeln(choose);
  
  //choose kya ho skta hai uske hisaab se kya krna hai
  switch(choose){
    //choose 'y' hone ke case me
    case 'y':
      stdout.writeln("You chose yes...");
      break;                                  //break taki agli condition ko check na kare
    
    //choose 'n' hone ke case me
    case 'n':
      stdout.writeln("You chose n...");
    
    //aise kitne bhi case die ja skte hain!!!
    
    //agar choose dono me se kuch na ho
    default:
      stdout.writeln("Invalid choice...");
  }
}