package main

import (
	"errors"
	"fmt"
)

func main() {
	// functions
	print_with_separator("Hey", "Hello", ":")
	fmt.Println(intDivision(10, 5))

	// simple error handling demo with multiple returns by function
	result, remainder, err := intDivisionWithError(10, 3)
	if err != nil {
		fmt.Println("Dividing by zero undefined")
	} else if remainder == 0 {
		fmt.Printf("Division quotient: %d", result)
	} else {
		fmt.Printf("Division quotient: %d and remainder %d", result, remainder)
	}
}

// functions can recieve arguments
func print_with_separator(t1 string, t2 string, sep string) {
	fmt.Println(t1 + sep + t2)
}

// function can return values
func intDivision(nume int, deno int) int {
	if deno == 0 {
		return 0
	}
	return nume / deno
}

// function can return multiple values, like here error for divide by zero
func intDivisionWithError(nume int, deno int) (int, int, error) {
	if deno == 0 {
		return 0, 0, errors.New("Cannot divide by zero")
	}

	result := nume / deno
	remainder := nume % deno
	return result, remainder, nil
}
