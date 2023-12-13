#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))



/*
 * main.c
 */

int main(void)
{
    volatile long delay;
	SYSCTL_RCGC2_R |= 0x00000020; // F clock
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTF_DIR_R = 0x8;      // output
	GPIO_PORTF_DEN_R = 0x8;      // digital enable
	GPIO_PORTF_DATA_R = 0x8;     // turn-on
	while(1)
	    ;
}
