// main package
package main

// standard formatting library
import (
	"fmt"
)

// entry point for go program main function, called automatically on execution
func main() {

	// go build command builds machine executable that can be run directly
	// go run command compiles and runs code after which executable is deleted

	// a simple function call in GO
	// go_values()
	// variables()
	// constants()
	operators_types_conversions()
}

// GO VALUES
// Note functions can be created using func function_name, functions discussed later
func go_values() {
	// Println in fmt prints line to console
	fmt.Println("Demonstration of values in GoLang")
	fmt.Println(1)             // integers
	fmt.Println("Hello World") // string
	fmt.Println(true)          // boolean
	fmt.Println(0.1)           // float
}

// GO types and type declaration
func variables() {
	// int, float, string, boolean, with size options in int

	// declaration var variable_name type = value

	// declaration with assignment
	// strings can be wrapped with " " or ` `
	var name, alpha string = "raccess21", `Alpha Male is a:
	Monkey What What`

	// declaration without assignment
	var suspense int16

	// variable type can also be inferred based on initialisation
	age := 1
	isObese := true
	totalWeight := 1000.01
	isOrIsnt := "is obese for weighing"

	// multiple declarations
	var a, b, c, d int16 = 2, 3, 5, 7

	// declared variables can be assigned values
	suspense = a + b + c + d

	fmt.Println("Demonstration of variables in GoLang")
	fmt.Println(name, "at age", age, isOrIsnt, totalWeight, "kg:", isObese, suspense, alpha)

}

func constants() {
	// constants are values that dont change throughout runtime

	const url = "On_Your_Mark-Studio_Ghibli.com"

	// constants can also be declared in groups
	const (
		PORT = 8080
		GOOD = "Of course."
	)

	fmt.Println("Demonstration of constants in GoLang")
	fmt.Println(url, "is available on port:", PORT, "And", GOOD, "it is good.")
}

func operators_types_conversions() {
	fmt.Println("Demonstration of operators and types in GoLang")

	println("Integer only: ", 1+2-3*4/5)
	println("Type fixed  : ", 1+2-float64(3*4)/5)

	// type casting float <> int for mathematical operations
	num1 := 2
	var num2 float32 = 0.1
	println(num1+int(num2), "or", float32(num1)+num2)

	// string operations
	var name1, name2 string = "Mumtaz", "Mahal"

	// + concatenates string, len counts bytes used for saving that string
	println(name1, name2, "total length:", len(name1+name2))

}
