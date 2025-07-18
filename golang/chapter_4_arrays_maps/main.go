package main

import (
	// "errors"
	"fmt"
)

func main() {
	// arrays are fixed length, same type, contiguous in memory, indexable
	// array_initialisation()
	// array_slicining()
	go_maps()
}

func array_initialisation() {
	fmt.Println("Demo declaration and initiakisation variation in GoLang")

	// declaration
	var ages [5]int

	// declaration with initialisation
	var weights []int = []int{1, 3, 5, 7, 9, 11, 13}
	weights2 := [1]int{1}
	weights3 := [...]int{1}
	weights4 := []int{1}

	// changing individual values [index] notation
	weights[2] = 125

	fmt.Println(ages, weights2, weights3, weights4)
	fmt.Println("Slicing 3:5 -", weights[3:5]) //slicing
	fmt.Println("Memory Locations for 0, 1:", &weights[0], &weights[1])
}

func array_slicining() {
	values := []int{1, 2, 3, 4, 5}
	values2 := []int{7, 8, 9}

	fmt.Printf("%d\t has length %d and capacity %d\n", values, len(values), cap(values))

	// creating a slice with capacity
	values3 := make([]int, 3, 8)
	fmt.Printf("%d\t\t has length %d and capacity %d\n", values3, len(values3), cap(values3))

	// length and capacity can be different, allowing appends without reallocation of memory
	values = append(values, 6)
	fmt.Printf("%d\t has length %d and capacity %d\n", values, len(values), cap(values))

	// append using spread operator
	values = append(values, values2...)
	fmt.Println("Values after append:", values)

	// iteration over array indexes
	for index := range values {
		fmt.Println(index)
	}

	// iteration over array values
	for index, value := range values {
		fmt.Println(index, value)
	}
}

// maps -> python dictionaries -> js objects {key:value}
func go_maps() {
	var teachers map[string]uint16 = make(map[string]uint16)
	students := map[string]uint64{"Hanu": 100000000000, "Man": 20, "Dhamma": 98}

	fmt.Println(teachers, students["Man"])
	fmt.Println("Invalid keys fallback to def values: ", students["Rame"])

	// testing unavailable/invalid keys
	var age, ok = students["Rame"]
	if ok {
		fmt.Printf("But the blame on rame boy: %d\n", age)
	} else {
		fmt.Printf("Invalid Key: %s\n", "Rame")
	}

	// deleting map values
	delete(students, "Man")

	// itertion over map keys
	for key := range students {
		fmt.Println(key)
	}

	// itertion over map key:value
	for key, value := range students {
		fmt.Printf("%s: %d\n", key, value)
	}
}
