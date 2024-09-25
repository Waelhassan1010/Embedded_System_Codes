/*
 * wael hassan
 */

#include"CA.h"
void setup()
{
	CA_state=STATE(CA_wating);
}

void main()
{
	setup();
	while(1)
	{
		CA_state();
	}
}