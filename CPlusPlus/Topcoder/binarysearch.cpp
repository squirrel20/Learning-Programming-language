int binary_search(int *arr, int length, int key)
{
	int left, mid, right;

	left = 0;
	right = length - 1;
	mid = (left + right) / 2;

	while (left <= right) {
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;

		mid = (left + right) / 2;
	}

	return -1;
}