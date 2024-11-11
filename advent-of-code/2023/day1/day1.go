package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func extractTwoDigitNumber(line string) int {
	var frontNumber int = -1
	for _, c := range line {
		if unicode.IsDigit(c) {
			frontNumber = int(c - '0')
			break
		}
	}

	var backNumber int = -1
	for i := len(line) - 1; i >= 0; i-- {
		if unicode.IsDigit(rune(line[i])) {
			backNumber = int(line[i] - '0')
			break
		}
	}

	if frontNumber != -1 && backNumber != -1 {
		return frontNumber*10 + backNumber
	}
	return 0
}

func main() {
	file, err := os.Open("/home/abhinav/code/codebase/advent-of-code/2023/day1/input.txt")
	if err != nil {
		fmt.Println("Error opening file", err)
		return
	}
	defer file.Close()

	sum := 0
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		sum += extractTwoDigitNumber(line)
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
		return
	}

	fmt.Printf("Total sum: %d\n", sum)
}
