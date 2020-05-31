import java.util.*;

public class MergeSort implements Runnable {
    private int[] a;
    
    public MergeSort(int[] a) {
        this.a = a;
        //System.out.println("new mergesort");
    }
    private void merge(int[] left, int[] right, int[] a) {
        int i=0, j=0, k=0;
        while (i<left.length && j<right.length && k<a.length) {
            if(left[i]<=right[j]) {
                a[k]=left[i];
                i++;
            }
            else {
                a[k]=right[j];
                j++;
            }
            k++;
        }
        
        while (i<left.length && k<a.length) {
            a[k++]=left[i++];
        }
        while (j<right.length && k<a.length) {
            a[k++]=right[j++];
        }
    }
    private void mergeSort(int[] a) {
        
        if(a.length<2) return;
        int[] left = Arrays.copyOfRange(a, 0, a.length/2);
        int[] right = Arrays.copyOfRange(a, a.length/2, a.length);
        
        Thread left_thread = new Thread(new MergeSort(left));
        Thread right_thread = new Thread(new MergeSort(right));
        left_thread.start();
        right_thread.start();
        
        try {
            left_thread.join();
            right_thread.join();
        } catch (InterruptedException e) {
            
        }
        merge(left, right, a);
    }
    
    public void run() {
        mergeSort(a);
    }
}
