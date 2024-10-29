//import hm aise function, libraries ya modules ko krte hai jise phle hi kisi 
//aur ne likh diya hai taki hm directly use use kre aur dobara hr kaam shuru
//se na kare
import 'dart:io';

//Ye functions simplified hai
//function program ki aisa unit hai jiska ek specified "FUNCTION" yani kaam hai

//hr dart program me main function hota hai. import ke alawa sirf wahi lines execute 
//hoti hain jo main function me ho. import ki lines import starting me hi ho jaati hai 
//lekin tabhi execute hongi jb main
//function me kisi command ko imported lib ki jaroorat pde 

//main function ka main kaam hai btana ki yaha se program chalna shuru hota hai
 
 //return type  space  function_ka_naam (function ko bheji gayi values*)
 void main(){
  var number = laamba(1);       //laamba ko 1 bhejne pr jo value laamba wapis bhej rha hai
                                //wo value number me save ho jaegi
  //writeln bhi ek function hai jise std io me hmare liye define 
  //kr diya gya hai taki hme print method khud na likhna pde
  stdout.writeln(number);
  stdout.writeln(laamba(1));
  stdout.writeln(dusGuna('1'));
  stdout.writeln(isquare(10));
  stdout.writeln(divideExample(10, 20));
  stdout.writeln(divideExample(20, 10));
  stdout.writeln(divideExampleNamed(numerator: 10, denominator: 20));
}


//true ya false hi return krega, laamba naam ka function qki return type bool hai
//, integer type ki value ise bhej skte hain,
bool laamba(int numa) {
  //is curly brace me saare command hi is function ki "DEFINITION" hai
  stdout.writeln('Abhi laamba function execute ho rha hai');
  // agar jo value aayi hai wo 1000 se jyada hai to true
  if (numa > 1000) {
    return true;
  }
  //wrna false
  else {
    return false;
  }
}

//dus guna koi value lega aur uska dus guna return krega
//return type kuch bhi ho skta hai
dynamic dusGuna(var numa) {
  stdout.writeln('Abhi dusGuna function execute ho rha hai');
  var varType = numa.runtimeType;

  //agar numa ka TYPE yani data type int yani integer ya string yani text hai to
  if (varType == int || varType == String) {
    //uska dus guna bhejo
    return numa*10;
  }
  else {
    // wrna uska 10 guna nahi ho skta.
    // ho to skta hai pr ye function aisa krega ki kahega ki dus guna nahi kia 
    //ja sakta aisi condition me
    return "Iska dus guna nahi ho paega";
  }
}

//arrow operator use krke function definition
int isquare(int numa) => numa * numa;
double fsquare(double numa) => numa * numa;

//Nameless function or anonymous functions
//aise function jinka koi naam nahi hota
void namelessFunctionExample(){
  var names = ['ram', 'bole', 'to', 'ramayan', 'ke', 'main', 'hero'];
  
  //{} ke andar jo function definition hai uska koi name nhi hai
  //ye function names ke hr element ke liye execute ho ra h
  names.forEach((element) {
    stdout.writeln(element);
  });

  //yahi same result aise bhi kia ja skta hai
  //names ke hr value ke liye writeln function ka reference pass kia gya hai
  names.forEach(stdout.writeln);
}


//functions ko jo values () andar bheji jati hai use argument khte hai
//argument positional ho skte hai, yani position ke basis pr receive kia ja skta hai
//ya named ho skte hai ya argument ko uske naam ke basis pr receive kia ja skta hai

//call krte time position ke basis pe
//first value num1 me aaegi aur result me num1 numerator bnega
//second value num2 me aaegi aur result me num2 denominator bnega
//agar call ke time 2 value nahi di to error raise hoga
dynamic divideExample(int num1, int num2) => (num1~/num2).toInt();

//positional parameter ko [] lga ke optional bna skte hai
//ab agr num2 nhi bheja to num2 ki default value 1 maani jaegi
dynamic divideExample2(int num1, [int num2 = 1]) => (num1~/num2).toInt();

//isi ka named argument example dekhte hain
//ab call me numerator and denominator name wali values bhejni hongi
//named parameter optional hote hain
//call ke time koi value pass nahi ki to bhi chalega, numrtr 0 aur dnomntr 1 maana jaega
dynamic divideExampleNamed({var numerator=0, var denominator=1}) => 
          (numerator~/denominator).toInt();

//ek final cool definition likhte hain
//agar denominator 0 hai to ternary operator se denominator 1 
//wrna denominator jo tha wahi
dynamic divideExampleNamed2({var numerator=0, var denominator=1}) => 
          (numerator ~/ (denominator == 0 ? 1: denominator)).toInt();
