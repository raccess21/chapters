import 'dart:io';

void main(){
  collections();
}

/// fundamental Data types in dart
void dataTypes(){
  var novalue;            //declare datatype dynamic variable mtlb jo bhi value de do wahi type
  int vali ;           // declare with datatype, static variable, int type integer type 1, 2, -10, 0
  vali = 3;             //value assignment
  double vald = 0.03;   //declare and assign mtlb initialise, 
                        //double fractions -786.1008, 786.786, 1008.1008, -1008.786
  
  String vals = '3';    //strings type or type jisme text save ho skta hai
  bool valb = true;
  var valv = vali;        //dynamic valv ka type wo hoga jo vali ka dataTYPE hai
  var valn = null;        // valn kis kaam ka, koi value nahi, bolo haay rabba     
  const pi = 3.14;        //const or constant value, vaues that can't change
  print(vali.runtimeType);    //variable ka type int or string or whatever
  stdout.writeln("All values are \n$novalue \n$vali \n$vald \n$vals \n$valb \n$valv \n$valn \n$pi");

}

///conversion of one dataTYPE into another dataTYPE
void typeConversion(){
  var vali = int.parse('1');      //int . parse '1' -> integer of string '1' 
  assert(vali == 1);              //assert aage error catch krne me useful hoga
  var vald = double.parse('1');   // string '1' ka double value kya hoga wahi vald me save
  assert(vald == 1.0);
  var vals = 0.1.toString();      // string value of 0.1 -> '0.1'
  assert(vals == '0.1');
  var valpi = 3.14159.toStringAsFixed(3);  //pi ki string value lekin kewal 3 decimal points tk
  
  print("Values are -> $vali, $vald, $vals, $valpi");

  /*
    var vali2 = int.parse('pasha'); 
    This will generate FormatException error
    
  */
}

//dart me built in collections bhi hai, collections basic type se bnaye jaate hain
void collections(){
  
  ////////Lists///////////////////////////////////
  ///List [] enclose hote hai ye ordered collection hote hai
  ///inki value 0 se n -1 tk jaati hai
  ///             0, 1, 2            //total 3 values
  List numbers = [1, 2,'aajao'];     //LIST -> ordered set of any TYPE of values
  stdout.writeln('Is list ki length ${numbers.length}');
  stdout.writeln('$numbers: 0 ${numbers[0]}: 1 ${numbers[1]}: 2 ${numbers[2]}');


  List <String> snumbers = ['1', '2', '3'];       //now only string allowed qki static TYPE string de dia hai
  List <String> scnumbers = const ['1', '2', '3']; //values ab consant hain, inhe aage change nahi kia ja sakega

  List numbers2 = numbers;      //numbers ka reference numbers2 ko pass kia gya
                                //mtlb numbers ka jo memory location tha wahi memory location
                                //numbers2 ka bhi hai
  List numbers3 = [...numbers]; //numbers ki values numbers3 me copy hui, dono ki mem location alag alag hai
                                // ... spread operator hai
  stdout.writeln('$snumbers  $scnumbers  $numbers2  $numbers3');                               
  //                SET   ///////////////////      
  //set is an unordered collection
  // ye math wala set hai, isme saari values unique hoti hai
  //koi item duplicate nahi hota. Set {} enclose hote hain
  var com1 = Set(), com2 = Set.of([1, 2, 3]), com3 = [1,2,3].toSet();
  Set com4 = <String>{}, com5 = <int>{};
  stdout.writeln('Set definitions: $com1 $com2 $com3 $com4 $com5');
  
  Set compliments  = {'chal nikal', 'abe ja na', 'dk udhar kya dekh ra hai', 'chal nikal'};
  stdout.writeln('$compliments : ${compliments.length}'); 
  
  //printing every value using for loop, loop explained in loop notes
  for (var comp in compliments) {
    stdout.write('$comp : ');
  }

  /////////MAP////////////////////
  ///maps are dictionaries -------------> inme key aur unki value
  ///yani key - value pair me data save hota hai
  ///list me values by rule 0 se n -1 tk jaati hai
  ///map me hm hr value ka naam specify kr skte hai
  Map mnumbers = {
    '1' : 1,
    'doosra' : 2,
    3 : 'aajao',
  };

  stdout.writeln('Map example: $mnumbers');
  stdout.writeln('${mnumbers["1"]}: ${mnumbers["doosra"]}: ${mnumbers[3]}');
  
  //definitions
  var n1 = Map(), n2 = {'lala': '2', 'mala': '108'};
  n2['kala'] = 'koi nahi';
  stdout.writeln('$n1 : $n2');
}
