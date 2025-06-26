import java.util.Arrays;
import java.util.Random;

public class quicksort {
    
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        return i + 1;
    }
    
    public static void main(String[] args) {
        int[] sizes = {10, 100, 1000, 10000, 100000, 1000000};
        Random rand = new Random();
        
        System.out.println("Len\tQuickSort Manual\nArrays.sort");
        System.out.println("----------------------------------------");
        
        for (int size : sizes) {
            int[] arr1 = new int[size];
            int[] arr2 = new int[size];
            
            for (int i = 0; i < size; i++) {
                int num = rand.nextInt(1000000);
                arr1[i] = num;
                arr2[i] = num;
            }
            
            // quicksort manual
            long startTime = System.nanoTime();
            quickSort(arr1, 0, arr1.length - 1);
            long manualTime = System.nanoTime() - startTime;
            
            // Arrays.sort
            startTime = System.nanoTime();
            Arrays.sort(arr2);
            long javaTime = System.nanoTime() - startTime;
            
            System.out.printf("%d\t%.3f ms\t%.3f ms%n", 
                size, 
                manualTime / 1_000_000.0, 
                javaTime / 1_000_000.0);
        }
    }
}