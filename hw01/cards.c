#include <stdio.h>
#include <stdlib.h>

/*  Gets card name and saves to buffer.	
	card_name: card buffer
	returns: card value (2-11) OR error (0)
*/
void get_card(char *card_name)
{
	puts("Enter the card name: ");
	scanf("%2s",card_name);
}

/* 	Returns value of card. if invalid card, retuns 0	
	card_name: two-character card id
*/
int parse_card(char *card_name)
{
	int val = 0;
	switch(card_name[0]) {
	case 'K':
	case 'Q':
	case 'J':
		val=10;
		break;
	case 'A':
		val=11;
		break;
	default:
		val=atoi(card_name);
		if((val<2 ||val>10)){
			val=0;			
		}
	}
	return val;
}
/*  Adjusts card count
	
	val: value of latest card
	count: current card count
	returns: update card count
*/
int count_card(int val,int count)
{
	if ((val>1)&&(val<7)){
		count++;
	} else if(val==10){
		count--;
	}
	return count;

}


int main() 
{
	char card_name[3];
	int count = 0;
	int val = 0;
	while (1){
		get_card(card_name);
		if (card_name[0]=='X'){
			break;
		}		
		val = parse_card(card_name);
		if(!val){
			puts("I don't understand that value!");
			continue;
		}
		count = count_card(val,count);
		printf("Current count :%i\n",count);
	}
	return 0;
}
