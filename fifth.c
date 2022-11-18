//Given a list of length n (random integers), sort every third element. All other elements should remain untouched.
int* sortEveryThirdElement(int *a. int n)
{
    int i;
    int j;
    int temp;
    for (i = 2; i < n; i += 3)
    {
        for (j = i + 1; j < n; j += 3)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

//Now, given a value of k, print the k smallest elements among the untouched elements. n is the length of the array.
void ksmallestAmongUntouched(int *a, int k, int n)
{
    int i;
    int j;
    int temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }
}