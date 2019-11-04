volatile int a = 0x5;
volatile int b = 0xA;
volatile int c;

void main()
{
	c = a + b; // 0xF
}
