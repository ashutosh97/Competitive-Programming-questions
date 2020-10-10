#include "bubble_sort.h"

int main(void)
{
	int to_sort[] = {303, -909, 101, 42, 0, 42, 21, 1, 2};
	size_t arr_len = sizeof(to_sort) / sizeof(to_sort[0]);
	int *sorted = bubble_sort(to_sort, arr_len);

	print_array(sorted, arr_len);

	return(EXIT_SUCCESS);
}
