#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int getLengthOfNumber(long cardNumber){
	long numBuffer = cardNumber;
	int length;
	for(length = 0; numBuffer > 0; length++){
		// printf("Number buffer %lld\n", numBuffer);
		numBuffer = numBuffer / 10;
	}
	// printf("%d\n", length);
	return length;
}

void printArray(int numbers[], int size){
	for(int i = 0; i < size; i++){
		printf("%d\n", numbers[i]);
	}
}


int getSumOfArray(int arr[], int size){
	int i, sum;
	sum = 0;
	for(i = 0; i < size; i++){
		sum += arr[i];
	}
	return sum;
}

bool checkIfValidCardNumber(long cardNumber){
	long card_number = cardNumber;
	int length = getLengthOfNumber(card_number);
	int numbers[length];
	int i = length - 1;
	while (card_number > 0){
		numbers[i] = card_number % 10;
		card_number /= 10;
		i--;
	}
	i = 1;
	
	int number;

	while(i < length){
		// printf("Looping... \n");
		
		number = numbers[i] * 2;
		
		if (number > 9){

			int numberLength = getLengthOfNumber(number);
			// printf("numberLength: %d\n", numberLength);
			
			int bufferNumber, j, sum;
			sum = 0;
			while(j < numberLength){
				sum += number % 10;
				number /= 10;
				j++;
			}
			// printf("sum: %d\n", sum);
			number = sum;
		}
		numbers[i] = number;
		
		i+=2;
	}
	
	// printArray(numbers, length);
	int sum = getSumOfArray(numbers, length);
	if (!(sum % 10)){
		return true;
	}
	return false;
}

const char * getManufacturer(long cardNumber){
	long number = cardNumber;
	int length = getLengthOfNumber(number);

	int numbers[length];

	const char *manufacturers[3];

	manufacturers[0] = "VISA";

	manufacturers[1] = "AMEX";
	manufacturers[2] = "MasterCard";
	manufacturers[3] = "INVALID";
	int i = length - 1;

	while (number > 0){
		numbers[i] = number % 10;
		number /= 10;
		i--;
	}


	if(numbers[0] == 4){
		return manufacturers[0];
	}else if(numbers[0] == 3 && ( numbers[1] == 4 || numbers[1] == 7)){
		return manufacturers[1];
	}else if (numbers[0] == 5 && ( numbers[1] >= 1 && numbers[1] <= 5)){
		return manufacturers[2];
	}else{
		manufacturers[3];
	}
}

void main() {
	long number;
	bool valid;
	printf("Card number: ");
	scanf("%lld", &number);
	valid = checkIfValidCardNumber(number);
	if (valid){
		printf("Valid!\n");
		printf("%s\n", getManufacturer(number));
	}else {
		printf("INVALID!\n");
	}
	
}