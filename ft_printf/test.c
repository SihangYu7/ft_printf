#include "ft_printf.h"
#include <stdio.h>

int main() {
    // Test case: single '%'
    printf("%d", ft_printf("%"));
	printf("%d", printf("%"));
}

