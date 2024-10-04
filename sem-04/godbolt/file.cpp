int loop() {
    int x = 0;
	int sum = 0;
	unsigned int i = 0;
	for(i = 0U;i < (1U<<31U);i++)
	{
		x++;
		sum += x;
	}
    return sum;
}

int func(int x) {
    return x * 9;
}

int divide(int x) {
	return x / 49;
}

int main() {
    return 0;
}
