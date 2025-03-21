import java.util.*;

public class tempCodeRunnerFile{
    static void swapalter(int[]arr ,int size)
    {
        for(int i = 0;i<size;i += 2)
        {
            if(i+1 <size)
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    static void printArray(int[] arr)
    {
        for(int num :arr)
        {
            System.out.print(num + " ");

        }
        System.out.println();

    }


    public static void main(String[]args)
    {
        int[] odd = {2,3,4,5,9};
        int[] even = {2,3,4,9};


        swapalter(odd,odd.length);
        printArray(odd);


        swapalter(even,even.length);
        printArray(even);
    }
}
