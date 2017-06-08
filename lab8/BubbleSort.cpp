class BubbleSort {
public:
    static void sort(float* array, int size) {
        /*int right = size;
        for (int i = 0; i < right; ++i) {
            for (int j = 0; j < right-1; ++j) {
                if(array[j] > array[j+1]) {
                    float temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
            right--;
        }*/
        int i, j, flag = 1;    // set flag to 1 to start first pass
        float temp;             // holding variable
        for(i = 1; (i <= size) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (size -1); j++)
            {
                if (array[j+1] < array[j])      // ascending order simply changes to <
                {
                    temp = array[j];             // swap elements
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
                }
            }
        }
    }
};
