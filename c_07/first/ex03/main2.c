#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char	*strs[] = {"Hi", "my", "name", "is", "Wojtek"};
	char	*strs1[] = {"1234", "5678", "90"};
	char	*strs2[] = {"Hi", "my", "name", "is", "Wojtek"};
	char	*strs3[] = {"Banana", "Apple", "Orange", "Carrot"};
	char	*strs4[] = {"42"};
	char	*strs5[] = {};
	printf("%s\n", ft_strjoin(5, strs, " "));
	printf("%s\n", ft_strjoin(3, strs1, ""));
	printf("%s\n", ft_strjoin(5, strs2, ", "));
	printf("%s\n", ft_strjoin(4, strs3, " and "));
	printf("%s\n", ft_strjoin(1, strs4, "!!!!"));
	printf("%s\n", ft_strjoin(0, strs5, "TEST"));
}
