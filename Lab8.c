#include <stdio.h>
void clears()
{
	char c = getchar();
	while (c != '\n' && c != EOF);
	c = getchar();
}
struct GourmantMenu {
	float coffee;
	float tea;
	float subtotal;
	float total;
	float tax;
};

typedef struct GourmantMenu Menu;

void Management(Menu*);

int main(void)
{
	puts("Bievenu au Cafe Gourmant de Montreal !.\n");
	char Name[64] = { 0 };
	puts("Tappez votre nom SVP: ");
	scanf("%63s", Name);


	Menu cupofCoffee;
	cupofCoffee.coffee = 0;
	cupofCoffee.tea = 0;

	if (Name != '\0')
	{
		puts("Combien de tasse de cafe voulez vous acheter ?");
		scanf("%f", &cupofCoffee.coffee);
		puts("le prix d'un tasse de caffe est de $1,75\n");

		
		puts("Combien de tasse de the voulez vous acheter ?");
		scanf("%f", &cupofCoffee.tea);
		puts("le prix d'un tasse de caffe est de $1,50\n");

	} 
	else {
		printf("Retype your name again");
	}
	puts("");

	do {

		cupofCoffee.subtotal = (cupofCoffee.coffee * 1.75) + (cupofCoffee.tea * 1.50);

	} 
	while (cupofCoffee.subtotal <= 0); /*SOMEHOW THIS WORKS WHEN THE VARIABLE IS <=0 */

	puts("-----------------------------Recu--------------------------------------------------------------------\n");

	printf("Nom: %s\n", Name);
	printf("Nombre de tasse de cafe que vous avez commander: %.2f\n", cupofCoffee.coffee);
	printf("Nombre de tasse de cafe que vous avez commander: %.2f\n", cupofCoffee.tea);
	printf("votre prix avant tax c'est : $%.2f\n", cupofCoffee.subtotal);
   
	Management(&cupofCoffee);

	float receipt;

	printf("Votre Prix total Apres tax de 13 pourcents c'est : $%.2f\n", cupofCoffee.total);
	puts("Merci pour vos achats, Bonne Journer !");

	puts("-----------------------------Recu--------------------------------------------------------------------\n");

	return 0;
} 

void Management(Menu* P)
{
	(*P).tax = (*P).subtotal * 0.13;
	(*P).total = (*P).tax + (*P).subtotal;
}