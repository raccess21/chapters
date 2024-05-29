import 'dart:io';

main(){
  doWhile();
}

/////////  1 for loop /////////////////////
//loops se ek hi kaam ko baar baar kr skte hai:
void forLoop(){
  //for( strating value,  condition kb tk chalana hai, i ko kitna increase krna hai)
  //is case me i = 1 se chalega i 1 1 badhta jaega jb tk ki i 10 ya 10 se chhota hai
  
  // i ki value 1 ho gayi
  for(var i=1; i<=10; i++){
    //kya i 10 ya 10 se km hai?? agar ha to ye saari commands
    stdout.writeln(i);
  
    // i ki value is run ki aakhiri line execute hone ke baad update 
    //ho jaegi. flow aisa rhega
    
  }
}

//number ki value check wala example using loop
void numCheckForLoop(){
  stdout.write("Enter a number: ");
  var number = int.tryParse(stdin.readLineSync() ?? '') ?? 0;
  
  //agar number 0 se km hai to
  if (number < 0) {
    stdout.writeln("$number to 0 se km hai...");
  }
  
  //wrna
  else {

    // i ki value 100 se
    for(var i = 100; i >= 0; i -= 20){
      // kya i 0 ya 0 se jyada hai?
      
      // agar number i se bda hai to..........
      if (number > i) {
        stdout.writeln('$number to $i se jyada hai.');
        break;
        // ho gayi na ab condition check
        //ab aage aur isi loop ko chalane ka koi fayda nahi hai
        //to break HOTA TO CHALATE RHTE
      }
    }
  }
}


/////////for in loop
void forInLoop(){
  //array of numbers
  //             0  1   2    3    
  var numbers = [1, 7, '21', 12];

  stdout.writeln('Using for in..');
  for (var n in numbers){
    stdout.writeln(n);
  }

  //or we can do the same thing like this
  stdout.writeln('Using simple for and indexing');
  for (var i = 0; i < numbers.length; i++) {
    stdout.writeln(numbers[i]);
  }
}

/////////for each loooooooooooop/////////////////
void forEachLoop(){
  stdout.writeln('For each loop');
  var numbers = [1, 3, 5, 43];
  
  //numbers ke har element ke liye writeln (koi bhi) function call hua 
  stdout.writeln('Function ke reference ke saath');
  numbers.forEach(stdout.writeln);

  //ya hr element ke liye command 
  stdout.writeln('for each conditionals ke saath');
  numbers.forEach((element) {
    if (element % 2 == 0){
      stdout.writeln('$element is even.');  
    }
    else {
      stdout.writeln('$element is odd.');
    }
  });

  //using arrow function element ke liye ek line ka arrow
  //function define bhi kr skte hain
  stdout.writeln('for each arrow function ke saath');
  numbers.forEach((element) => stdout.writeln(element));
}

void whileLoop(){
  //while yani jb tk ye condition true hai tb tk
  //loop krte raho

  var i = 0;
  while(i <= 100) {
    stdout.writeln(i);
    i = i + 20; 
  }
}


void doWhile(){
 //do ye commands execute krte raho jb tk ki
 //while wali condtion true hai
 //isme phle command execute hogi uske baad check hoga

  var i = 0;
  do {
    stdout.writeln(i);
    i = i + 20; 
  } while( i <= 100); 
}

void doWhileExample(){
  var choice = 'y';
  do {
    stdout.write("Enter y to break: ");
    choice = (stdin.readLineSync() ?? 'y')[0].toLowerCase();
    stdout.writeln('You enterd $choice');
  } while (choice != 'y');
}