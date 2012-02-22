/*Return count of number of 1's in word
 *Date: 21/2/2012
 *Author:Simon.H
 *Version:1.0
 */
#include <stdio.h>
int bitCount(int x);

int main()
{
	int i;
	int j = 0;
	printf("Please input a number:\n");
	scanf("%d", &i);
	j = bitCount(i);
	printf("The numbers of 1 is %d.\n", j);
}

int bitCount(int x)
{
	int m1 = 0x11 | (0x11 << 8);
	int mask = m1 | (m1 << 16);
	int s = x & mask;
	s += x >> 1 & mask;
	s += x >> 2 & mask;
	s += x >> 3 & mask;
	s += (s >> 16);
	mask = 0xF | (0xF << 8);
	s = (s & mask) + ((s >> 4) & mask);
	return (s + (s >> 8)) & 0x3F;
}

