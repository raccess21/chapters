package main

import (
	"fmt"
	"math/rand"
)

func main() {
	// if_else()
	switch_case()
	// for_loop()
	// while_loop()
	// do_while_loop()
	// loop_using_range()
}

// go if else
func if_else() {
	// if this then that otherwise that other thing yeah
	if 1 == 2 {
		println("Oh Boy == campares for equality")
	} else if 1 > 2 {
		println("> is greater than")
	} else if 1 < 2 {
		println("< is smaller than")
	} else {
		println("What else, 1 is definitely smaller than 2")
	}

	if 1 != 2 {
		println("2 knew. He could never be 1. It was not 2's fault after all. But that's how the world is.")
	}

	// and or bore drill chill will ya
	if 1 == 1 && 1 == 2 {
		println("How could they both be true.")
	}

	if 1 == 1 || 1 == 2 {
		println("If either then a rhyming log for you.")
	}
	// note go will skip 1 == 2 check since left of || is already true so need need to evaluate further checks
}

// GO switch implementation
func switch_case() {
	rand.Seed(10)
	value := rand.Intn(101)
	result := 0

	// go switches break implicity for case match
	// switch without conditional
	switch {
	case value < 10:
		fmt.Printf("%d is less than 10", value)
		result = -1
	case value > 10:
		fmt.Printf("%d is more than 10", value)
		result = 1
	default:
		fmt.Printf("%d is equal to 10", value)
		result = 0
	}
	fmt.Println()

	// switch with conditional
	switch result {
	case -1:
		fmt.Println("Result was less than 10")
	case 0:
		fmt.Println("Result was exactly 10")
	case 1:
		fmt.Println("Result was more than 10")
	default:
		fmt.Println("This default will never print. Probability won't allow it.")
	}
}

// GO for loop
func for_loop() {
	fmt.Println("\nDemonstrating for loop in GoLang")

	for i := 0; i < 5; i++ {
		fmt.Print(i, " ")
	}
}

func while_loop() {
	fmt.Println("\nDemonstrating while loop in GoLang")

	i := 0
	for i < 5 {
		// skipping iteration using continue
		if i == 3 {
			continue
		}

		fmt.Print(i, " ")
		i++
	}
}

func do_while_loop() {
	fmt.Println("\nDemonstrating do while loop in GoLang")

	i := 0
	for {
		fmt.Print(i, " ")
		if i == 5 {
			break
		}
		i++
	}
}

func loop_using_range() {
	fmt.Println("\nDemonstrating loop using range in GoLang")
	for i := range 5 {
		print(i, " ")
	}
}
