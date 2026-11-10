#include<stdio.h>

#define	BURNING		0x1
#define	POISION		0x2
#define	ELECTRIC	0x4
#define	BLEED		0x8


void main()
{
	int PlayerStatus = 0;

	PlayerStatus |= POISION;
	PlayerStatus |= ELECTRIC;

	PlayerStatus &= ~POISION;


	if (PlayerStatus & BURNING)
	{
		printf("Player is Burning\n");
	}
	if (PlayerStatus & POISION)
	{
		printf("Player is Poision\n");
	}
	if (PlayerStatus & BLEED)
	{
		printf("Player is Bleeding\n");
	}
	if (PlayerStatus & ELECTRIC)
	{
		printf("Player is Electric\n");
	}
	/*else
	{
		printf("Default");
	}*/

	


}

