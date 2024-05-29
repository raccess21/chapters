import 'dart:io';

//class bluprint hai kisi object ka ki object me kya kya hona chahiye
//object us class ka koi ek manifestation
//object aisi koi bhi cheej hai jiski koi value hai -> yani variables
//aur us value ke saath kuch kiya ja skta hai       -> yani methods ya functions
//dart me object ko class bna ke create kr skte hai
//object ke characteristics uske member variable a data member 
//aur uski functionality member function se define hogi
//
//eg
//
//main kaha gya?? is notes me main last me hai, compiler fir bhi phle main hi execute krega 

//simple object example
void listObject(){
  //List class ka tyohaar obect    //ye saare data members   
  List tyohaar =                  ['diwali', 'holi', 'basant panchmi'];
  tyohaar.toSet();                                      //toSet is object ka ek function
  stdout.writeln(tyohaar);
  //List ek pre defined class hai, iske functions aur data member ko handle
  //krne ka logic pre written hai.
  //hm khud se bhi class bna skte hain
}

//jaise language class hai, hindi english ya dart language ke example to ye hue object
//car class hai, maruti 800 aur ambassador object

//custom class Example
class Udhyog {
  final String name;      //udhyog ka naam final mtlb phli baar jo value isme aagyi wo change nhi hogi us object ke liye
  int employees = 0;      //udhyog me kitne employees
  String service = '';     //service ya product kya bechte
  String udhyogScale = '';     
  static const String jinda = 'hai';    //const values ko change nhi kr skte
  
  //final -> runtime constant, run time pe jo phli value isme daal di whi rhegi, change nhi kr skte
  //vs 
  //const -> compile time constant, compile ke time jo value isme daali gayi wahi rhegi, yani declare ke time
            //hi initialise krna compulsary hai

  //static const -> class ke saare member object ke hote hain, pr static const class ka hota hai
                  //ise directly classname. krke access kiya ja skta hai object bnae bina.
                  //ise class ke saare object share krte hain
  
  //ye udhyog class ka constructor hai, constructor object costruct krta hai
  //jb bhi is class ka kisi object ka phli baar naam likha jaaega ye automatically call hoga
  //basically objects ka bramha yahich hai

  //ye ek default constructor hai, is class ka jb bhi object bnega, ye call hoga
  Udhyog(this.name, int emp, [this.service = '']) {
    stdout.writeln("$name ne Udhyog class ke bramha ko yaad kia hai??");
    employees = emp;                             
    if (emp >= 250) {this.udhyogScale = 'LARGE';}         //this mtlb is object ka udhyogscale
    else if (emp > 49) {this.udhyogScale = 'MEDIUM';}     //jo object construct ho rha hai
    else if (emp > 9) {this.udhyogScale = 'SMALL';} 
    else if (emp > 0) {udhyogScale = 'MICRO';}            //bina this. use kiye bhi yahi kaam
    if (emp >= 250) {udhyogScale = '';}                  //hoga qki yahi object call hua hai
  }

  //ye named constructor hai is naam se object create krenge to ye hoga
  Udhyog.named(this.name) {
    stdout.writeln('$name ne Udhyog class ke named bramha ko yaad kia hai??');
    employees = 0;
    service = '';
    udhyogScale = '';
  }
  
  //Udhyog's output function prints udhyog detail in this format
  void output(){
    stdout.writeln('$name offers $service and it is a $udhyogScale scale enterprise jinda $jinda.');
  } 

}

///////////////INHERITANCE///////////////////
///worker extends udhyog meaning -> worker class Udhyog class ka child hai
///udhyog ki saari property worker use kr skta hai, aur worker ke pass apni bhi
///kuch properties ho skti hain jo Udhyog me na ho
///worker subclass ho gya Udhyog superclass ka aisa bolenge
class Worker extends Udhyog {
  final String ename; 

  //worker constructor jaroori argument apne super class udhyog ko pass krega
  //jb bhi worker bnega to kisi company me to wo hoga hi isliye hr worker object bnne
  //pr Udhyog ka constructor bhi call hoga
  //subclass ke object ko bnane ke liye super class ka constructor call hoga
  Worker(this.ename, String cname, int emp, [service = '']) : super(cname, emp, service) {
    stdout.writeln('$ename ne Worker class ke bramha ko yaad kiya??');
  }

  Worker.udhyogPass(this.ename, Udhyog kaNaam) : 
    super(kaNaam.name, kaNaam.employees, kaNaam.service) {
      stdout.writeln('$ename ne Worker class ke named bramha udhyogpass ko yaad kia??');
    }

  ///agar subclass aur superclass me same naam se property hai to subclass ki property
  ///call hoti hai. output udhyog and worker dono me hai. pr worker ke object se worker 
  ///ka hi output call hoga udhyog ka nahi. qki worker ka output override kr rha hai
  ///udhyog ke output ko
  @override               //dart safety feature, compiler ko btane ke liye ki program me
                          //override intentional hai, na bhi use kro to chalega as expained in
                          //concept of over riding
  //good practice to use override, 'google' for industry standards
  void output() {
    stdout.write('Q. $ename ki company kya hai?\nA. ');
    super.output();
  }
}


/////////GETTERS provide read capabilities to object, compiler by default defines getter
/// and SETTERS provide write capabilities
///jb bhi aap assign krre objeck ko value setter call hota hai
///access krte waqt getter call hota hai
///aap apna getter aur setter custom define kr skte hain
class Square {
  num left, top, right, bottom, _fencing=0, _tiling=0;   //num TYPE me int aur double dono aa jaate hain
  Square(this.left, this.top, this.right, this.bottom);

  //Getters 
  //agar getter aur variable name same ho to issue aata hai. isliye getter name 
  //fencing to variable name _fencing hai, qki fencing getter fencing variable ke bdle 
  //khud ko hi recursively call krne lgta hai
  num get side => left - right;   //side  left - right return krega
  num get fencing => _fencing;    //fencing call pe _fencing ki value bhejaega
  num get tiling => _tiling;      //....
  
  //SETTERs
  set fencing(num cost) => _fencing = 4 * side * cost;   //fencing bole to cost per meter X perimeter 
  set tiling(num cost) => _tiling = cost * side * side;   //tiling
   
  //height aur width ko define krte hain
  void output(){
    stdout.writeln('This square has side $side\nFencing cost: $fencing\nTiling cost: $tiling');    
  }
  //yaha side, fencing, tiling ka setter call hua
  //getter setter . operator se access ho jaate hai, normal function ki trh
  //inme () nahi lgana pdta.
}



main(){
  Square r1 = Square(10, 10, 20, 20);
  r1.fencing = 4;     //fencing setter -> square ke perimeter ka 4 guna fencing variable me save ho jaega
  r1.tiling = 10;     //tiling setter -> square ke area ka 10 guna tiling member variable me save ho jaega
  r1.output();
}

void classExample() {
  listObject();
  Udhyog kaalaPaaniTour = Udhyog('Kaala Paani Tour', 25, 'Travel'); //kaalapaani ke liye constructor call hua
  kaalaPaaniTour.output();                              //kaalapaani ka output function

  //Udhyog ab ek valid datatype jaisa hai
  var atlas = Udhyog('Atlas Cycles', 120, 'Machinery');
  atlas.output();

  var koiNahi = Udhyog.named('kappa');
  koiNahi.output();

  koiNahi.name;     //koi nahi ka name qki name koinahi object ki property hai
  //koiNahi.jinda;  //jinda class ki property hai so this causes error
  Udhyog.jinda;     

}

void inheritanceExample() {
  Udhyog kaalaPaaniTour = Udhyog('Kaala Paani Tour', 25, 'Travel');
  
  //Worker Udhyog ka subclass hai, worker ke constructor ko ye argument pass hue
  var mukesh = Worker('Mukesh', 'Atlas Cycles', 120, 'Machinery');
  var kuldeep = Worker.udhyogPass('Kuldeep', kaalaPaaniTour);
  
  mukesh.output();
  kuldeep.output();
}