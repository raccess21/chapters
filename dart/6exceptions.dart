import 'dart:io';

//agar runtime pe koi exception yani error aata hai to use runtime me handle kaise kare
//taki program smoothly apna process complete kre

main(){
  multiplier(3.25, 'a');
}

void multiplier (var val1, var val2) {
  int result = 0;
  
  //koshish krte hain
  try {
    //agar checker true ho gya to
    if (checker(val1, val2)) {
      result = val1 * val2;
      stdout.writeln('Result is $result');
    }
  }  

  //ya ho skta hai ki error aa jae to use catch krke
  catch(error) {
    //print kr hi dete hain kya error taki idea ho kya isssue hai
    stdout.writeln(error);
    stdout.writeln('Result was not calculated.');
  }

  //ab jb sb ho hi gya hai to last me ye to krna hi hai chahe error aaye ya na aaye
  finally {
    stdout.writeln('Bye bye');
  }
}

//checker function
bool checker(var val1, var val2) {
  //agar dono value int nahi hai to feko error
  if (val1.runtimeType != int && val2.runtimeType != int) {
    throw Exception('$val1 and $val2 must be numbers.');
  }

  //wrna pyaar se bheja result
  else {
    return true; //val1 * val2;
  }
}

