#include <stdio.h>
#include <stdlib.h>

int getCoins(int amount){
	int coins = 0;
	int coinChoices[] = { 25, 10, 5, 1 };
	int i = 0;
	while (amount != 0 && i < sizeof(coinChoices)){
		int count = amount / coinChoices[i];
		if (count){
			coins += count;
			amount %= coinChoices[i];
		}
		i++;
	}
	return coins;
}

void main(int argc, char* argv[]){
	int amount;
	amount = atoi(argv[1]);
	int coins = getCoins(amount);
	printf("Coins: %d\n", coins);
}